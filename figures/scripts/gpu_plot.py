import copy
import glob
import math
import seaborn as sns
import pandas as pd
from pathlib import Path
import numpy as np
import matplotlib
from npbench.infrastructure import utilities as util
# matplotlib.rcParams['text.usetex'] = True
import matplotlib.pyplot as plt
from scipy.stats.mstats import gmean, hmean
import argparse 

# geomean which ignores NA values
def my_geomean(x):
	x=x.dropna()
	res = gmean(x)
	return res

# make nice/short numbers with up/down indicator
def my_speedup_abbr(x):
	prefix = ""
	label = ""
	if math.isnan(x):
		return ""
	if x < 1:
		prefix = u"\u2191"
		x = 1/x
	elif x > 1:
		prefix = u"\u2193"
	if x > 100:
		x = int(x)
	if x > 1000:
		label = prefix + str(round(x/1000, 1)) + "k"
	else:
		label = prefix + str(round(x, 1))
	return str(label)

# make nice/short runtime numbers with seconds / milliseconds
def my_runtime_abbr(x):
	suffix = " s"
	if math.isnan(x):
		return ""
	if x < 0.1:
		x = x*1000
		suffix = " ms"
	return str(round(x,2)) + suffix


def bootstrap_ci(
    data, 
    statfunction=np.median, 
    alpha = 0.05, 
    n_samples = 300):

    """inspired by https://github.com/cgevans/scikits-bootstrap"""
    import warnings

    def bootstrap_ids(data, n_samples=100):
        for _ in range(n_samples):
            yield np.random.randint(data.shape[0], size=(data.shape[0],))    
    
    alphas = np.array([alpha/2, 1 - alpha/2])
    nvals = np.round((n_samples - 1) * alphas).astype(int)
    if np.any(nvals < 10) or np.any(nvals >= n_samples-10):
        warnings.warn("Some values used extremal samples; results are probably unstable. "
                      "Try to increase n_samples")

    data = np.array(data)
    if np.prod(data.shape) != max(data.shape):
        raise ValueError("Data must be 1D")
    data = data.ravel()
    
    boot_indexes = bootstrap_ids(data, n_samples)
    stat = np.asarray([statfunction(data[_ids]) for _ids in boot_indexes])
    stat.sort(axis=0)

    return stat[nvals][1] - stat[nvals][0]



parser = argparse.ArgumentParser()
parser.add_argument("-f", "--folder", type=str, nargs="?", default=".")
parser.add_argument("-p",
					"--preset",
					choices=['S', 'M', 'L', 'paper'],
					nargs="?",
					default='paper')
args = vars(parser.parse_args())
db_folder = args["folder"]
if(db_folder[-1]!="/"):
	db_folder += "/"
# Read data
data = None
# pathlist = glob.glob(csv_folder+'/*.csv') 
# for f in pathlist:
# 	ndata = pd.read_csv(f)
# 	if data is None:
# 		data = ndata
# 	else:
# 		data = pd.concat([data, ndata])
# create a database connection
database = db_folder+r"npbench.db"

conn = util.create_connection(database)
data = pd.read_sql_query("SELECT * FROM results", conn)
data = data[data['preset'] == args['preset']]
print(data)

# failures = pd.read_csv('NumPy Benchmarks - Failures.csv')

#get rid of kind and dwarf, we don't use them
data = data.drop(['kind', 'dwarf'], axis=1).reset_index(drop=True)

# remove everything that does not validate, then get rid of validated column
# data = data[data['validated']==True]
data = data.drop(['validated'], axis=1).reset_index(drop=True)
frameworks = set(data["framework"])
print(frameworks)
# for each framework and benchmark, choose only the best details,mode (based on median runtime), then get rid of those
aggdata = data.groupby(["benchmark", "domain", "framework", "mode", "details"], dropna=False).agg({"time": np.median}).reset_index()
best = aggdata.sort_values("time").groupby(["benchmark", "domain", "framework", "mode"], dropna=False).first().reset_index()
bestgroup = best.drop(["time"], axis=1)  # remove time, we don't need it and it is actually a median
data = pd.merge(left=bestgroup, right=data, on=["benchmark", "domain", "framework", "mode", "details"], how="inner") # do a join on data and best
data = data.drop(['mode', 'details'], axis=1).reset_index(drop=True)

gpu_data = data[data.framework.isin(list("DaCe GPU"))]
benchmarks = set(gpu_data["benchmark"])
gpu_benchmarks = set()
for b in benchmarks:
    res = gpu_data[gpu_data["benchmark"]==b]
    if len(res[res["framework"]=="DaCe GPU"]) > 0:
        gpu_benchmarks.add(b)
final_gpu_data = gpu_data[gpu_data.benchmark.isin(gpu_benchmarks)]


# get improvement over numpy (keep times in best_wide_time for numpy column), reorder columns
best_wide = best.pivot_table(index=["benchmark", "domain"], columns="framework", values="time").reset_index() # pivot to wide form
best_wide = best_wide.sort_values(by=['domain']).reset_index(drop=True)                         # sort by domain
# best_wide = best_wide[['benchmark', 'domain', 'CuPy GPU', 'DaCe GPU', 'DaCe', 'Numba', 'Pythran', 'NumPy']].reset_index(drop=True) 
best_wide = best_wide[['benchmark', 'domain', 'CuPy GPU', 'DaCe GPU', 'NumPy']].reset_index(drop=True) 
best_wide_time = best_wide.copy(deep=True)
# for f in ['CuPy GPU', 'DaCe GPU', 'DaCe', 'Numba', 'Pythran', 'NumPy']:
for f in ['CuPy GPU', 'DaCe GPU', 'NumPy']:
    best_wide[f] = best_wide_time['NumPy'] / best_wide[f]

final_best_wide = best_wide[best_wide.benchmark.isin(gpu_benchmarks)]
gmean_dace_numpy = gmean(final_best_wide["DaCe GPU"])
hmean_dace_numpy = hmean(final_best_wide["DaCe GPU"])
median_dace_numpy = np.median(final_best_wide["DaCe GPU"])
gmean_cupy_numpy = gmean(final_best_wide["CuPy GPU"])
hmean_cupy_numpy = hmean(final_best_wide["CuPy GPU"])
median_cupy_numpy = np.median(final_best_wide["CuPy GPU"])
gmean_dace_cupy = gmean(final_best_wide["DaCe GPU"] / final_best_wide["CuPy GPU"])
hmean_dace_cupy = hmean(final_best_wide["DaCe GPU"] / final_best_wide["CuPy GPU"])
median_dace_cupy = np.median(final_best_wide["DaCe GPU"] / final_best_wide["CuPy GPU"])
print(gmean_dace_numpy, hmean_dace_numpy, median_dace_numpy)
print(gmean_cupy_numpy, hmean_cupy_numpy, median_cupy_numpy)
print(gmean_dace_cupy, hmean_dace_cupy, median_dace_cupy)

for i in final_gpu_data.index:
    b = final_gpu_data["benchmark"][i]
    final_gpu_data["time"][i] /= best_wide_time[best_wide_time["benchmark"]==b]["NumPy"]

ax = sns.barplot(x="benchmark", y="time", hue="framework", data=final_gpu_data, palette=["#69A8F5", "#F55B4E"])
ax.set(xlabel="Benchmark", ylabel="Runtime (relative to NumPy on CPU)", yscale="log")
ax.axhline(y=1.0, linewidth=2, linestyle="--", color="#F5B645")
ax.legend(['CuPy', 'DaCe'], loc="best")
leg = ax.get_legend()
leg.legendHandles[0].set_color("#69A8F5")
leg.legendHandles[1].set_color("#F55B4E")
plt.xticks(rotation=90)
plt.style.use('classic')
plt.tight_layout()
plt.savefig("gpuplot.pdf", dpi=600)
plt.show()

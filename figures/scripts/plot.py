import glob
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
import argparse 

dask_df = None
dace_df = None
legate_df = None
parser = argparse.ArgumentParser()
parser.add_argument("-f", "--folder", type=str, nargs="?", default=".")

args = vars(parser.parse_args())
res_folder = args["folder"]

# read dask data
# df = pd.read_csv(res_folder+'/dask.res', sep="\s+", header=None)
# df = df.rename(columns={0: "framework", 1: "benchmark", 2: "init_time", 3: "time", 4: "sockets", 5: "sizes"})
# df = df.drop(['init_time'], axis=1)
# df = df[['benchmark', 'framework', 'sockets', 'sizes', 'time']]


# read dace data
for name in glob.glob(res_folder+'/dace_cpu*.csv'):
    tdf = pd.read_csv(name)
    dace_df = pd.concat([dace_df, tdf])

# read legate data
# for name in glob.glob(res_folder + "/legate_cpu*.csv"):
#     if "_v2" in name:
#         continue
#     # Version 2 runs jacobi 1d/2d for only 10 iterations
#     # and gemm, k2mm, k3mm with square matrices
#     tdf = pd.read_csv(name)
#     legate_df = pd.concat([legate_df, tdf])
# legate_df = legate_df.replace("legate_cpu", "Legate")
# legate_df = legate_df.replace("jacobi1_2d", "jacobi_2d")

df = pd.concat([dace_df])
df = df.replace("dace_cpu", "DaCe")

# plot scaling efficiency tal
sns.set_style("whitegrid")
medians = df.groupby(["framework", "benchmark", "sockets"])['time'].median()
medians = medians.reset_index()
all_medians = medians.copy()
medians.drop(medians[medians.sockets > 1].index, inplace=True)
medians = medians.drop(['sockets'], axis=1)
medians = medians.rename(columns={"benchmark": "benchmark", "time": "time_single"})
scaling = df.merge(medians, how='left', left_on=['benchmark', 'framework'], right_on=['benchmark', 'framework'] )
scaling['efficiency'] = (scaling['time_single'] / scaling['time'])*100

g = sns.relplot(data=scaling, x="sockets", y="efficiency", kind="line", hue="framework", style="framework", col="benchmark", col_wrap=6, facet_kws={'sharey': True, 'sharex': True},
                dashes=False, markers=['v'], height=2.5, aspect=1, legend=False, palette=["#F55B4E"])
                #"#69A8F5", "#76b900"
[plt.setp(ax.get_xticklabels(), rotation=90) for ax in g.axes.flat]
#ax.legend.set_title("Scaling Efficiency [%]")
g.set_titles(row_template = '{row_name}', col_template = '{col_name}')
g.set(xscale="log")
g.set(xlim=(1, 2050), xticks=[1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048], xticklabels=[1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048],
 xlabel="Procs (18c)", ylabel="Parallel Efficiency [%]")
plt.subplots_adjust(wspace=0.5)


ax2 = None # save the last axis object
for i, ax in enumerate(g.axes.flat):
    kernel = ax.get_title()
    dace = all_medians[ (all_medians['benchmark']==kernel) & (all_medians['framework']=="DaCe") ]
    ax2 = ax.twinx()
    if len(dace['sockets']):
        dace_plot = ax2.plot(dace['sockets'], dace['time'], color="#69A8F5", linestyle="dashed", marker="o", markersize=4)
        #plt.text(x=512, y=dace['time'].iloc[-1] +1, s="18k cores", rotation=90)
    if i==5:
        ax2.set_ylabel('Runtime [s]', fontsize=12)
ax2.set_ylabel('Runtime [s]', fontsize=12)

from matplotlib.lines import Line2D
custom_lines_r = [Line2D([0], [0],  marker="o", color="#69A8F5")]
for r in custom_lines_r:
    r.set_linestyle("--")
custom_lines_e = [Line2D([0], [0],  marker="v", color="#F55B4E")]
ax.legend(custom_lines_r + custom_lines_e,
          ['DaCe Runtime', 'DaCe Parallel Efficiency'],
           title="", ncol=1, bbox_to_anchor=(2.9, 0.55))


# compute geomean of scaling efficiency improvement
# tmp = scaling.drop(['sizes', 'time', 'time_single'], axis=1).pivot_table(index=['benchmark', 'sockets'], columns=['framework'], values=['efficiency']).reset_index()
# tmp.columns = ["_".join(v) for v in tmp.columns.values]
# improv = tmp['efficiency_DaCe']/tmp['efficiency_DASK']
# improv_l = tmp['efficiency_DaCe']/tmp['efficiency_Legate']
# a = np.log(improv)
# print("GeoMean Scaling Eff. improvement over Dask: ", np.exp(a.mean()))
# print("ArithMean Scaling Eff. improvement over Dask: ", improv.mean())
# print("Median Scaling Eff. improvement over Dask: ", improv.median())
# b = np.log(improv_l)
# print("GeoMean Scaling Eff. improvement over Legate: ", np.exp(b.mean()))
# print("ArithMean Scaling Eff. improvement over Legate: ", improv_l.mean())
# print("Median Scaling Eff. improvement over Legate: ", improv_l.median())



plt.show()
g.savefig('facet.pdf', bbox_inches='tight')


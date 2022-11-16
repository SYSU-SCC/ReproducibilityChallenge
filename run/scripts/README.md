# run
## Description

This folder includes the "run.sh" to run all the benchmark and store the result. However, this shell script couldn't run simply by calling "./run.sh". You may need to modify the distributed command, which includes the hostname needed to be modified. This script reuses the spack software to load the software installed previously.

## environment valuables needed

```bash
source ../../compile/spack-0.18.1/share/spack/setup-ev.sh
```

To run the command above will help to get the spack environment.

## environment valuables during runtime

Due to that the environment valuables are too long, we couldn't put them here.

## Differences in the experiment design compared to the Data-Centric Python paper

We run the distributed version for two different configuration.

## Indicate how you measured timings

We reuse the script included in npbench to measure our timings.

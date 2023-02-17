# spec-cpuv8-sampleflow

A benchmark for the SPEC CPUv8 test suite based on the deal.II and SampleFlow libraries.

...describe parallelism...



# Workload definitions

The benchmark comes with the requisite three workloads. To execute
these, run the benchmark executable with the name of the respective
input file as the sole command line argument. The input files are as follows:

- `test.prm`: This workload utilizes 4-way parallelism for the main loop. On an ~2018 system using two AMD Epyc 7552 processors with 48 cores each, the run time for the test load is approximately as follows:
```
real    0m13.015s
user    0m25.348s
sys     0m1.093s
```
The last few lines of output should look like this:
```
Sample number 16000
Mean value of the 4-parameter downscaling:
    1.3992 1.62418 1.45369 3.61521 
Comparison mean value of the downscaled 64-parameter mean:
    1.3992 1.62418 1.45369 3.61521 
Number of samples = 16000
```

- `train.prm`: This workload utilizes 8-way parallelism for the main loop. On the same system as mentioned above, its run time is approximately as follows:
```
real    0m58.535s
user    2m6.218s
sys     0m4.873s
```
The last few lines of output should look like this:
```
Sample number 60000
Mean value of the 4-parameter downscaling:
    5.40504 2.92193 6.40175 5.72443 
Comparison mean value of the downscaled 64-parameter mean:
    5.40504 2.92193 6.40175 5.72443 
Number of samples = 60000
```

- `reference.prm`: This workload utilizes 32-way parallelism for the main loop. On the same system as mentioned above, its run time is approximately as follows:
```
real    5m10.347s
user    18m34.011s
sys     0m30.149s
```
The last few lines of output should look like this:
```
Sample number 320000
Mean value of the 4-parameter downscaling:
    3.33384 6.76076 3.81944 16.9824 
Comparison mean value of the downscaled 64-parameter mean:
    3.33384 6.76076 3.81944 16.9824 
Number of samples = 320000
```

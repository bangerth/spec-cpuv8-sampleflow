# About 747.sampleflow

747.sampleflow is a benchmark for the SPEC CPUv8 test suite that is
based on the deal.II and SampleFlow libraries, see
https://www.dealii.org and https://github.com/bangerth/sampleFlow/
. The deal.II has previously already served as the basis for
[447.dealii](https://www.spec.org/cpu2006/Docs/447.dealII.html) in
SPEC CPU2006 and
[510.parest](https://www.spec.org/cpu2017/Docs/benchmarks/510.parest_r.html)
in SPEC CPU2017.

The current benchmark is an implementation of a testcase that uses a
Monte Carlo sampling method to gain information about a probability
distribution p(x). The definition of the function p(x) involves the
solution of a partial differential equation using the finite element
method. The overall problem this benchmark solves is concisely defined
in [this preprint](https://arxiv.org/abs/2102.07263) (which has been
accepted for publication in SIAM Review); it is intended as a problem
that is simple enough to solve yet complicated enough that one needs
sophisticated algorithms to get answers with sufficient accuracy. For
example, the "ground truth" answers provided in the preprint above
were obtained using some 30 CPU years of computations. More
sophisticated algorithms than those used in the preprint should be
able to obtain the same accuracy with far less effort, but generally
the accuracy one gets is inversely proportional to (the square root
of) the computational effort and the very large effort made for the
results in the paper reflects a desire to have published results with
as much accuracy as possible.

This benchmark implements a sampling algorithm for p(x) that is based
on a variation of the Differential Evaluation algorithm, which is a
parallel version of the [Metropolis-Hastings
algorithm](https://en.wikipedia.org/wiki/Metropolis%E2%80%93Hastings_algorithm).
In it, a number _N_ of chains are running in parallel, occasionally
exchanging information. In the version used for this benchmark, _N_ is
a parameter that is set in the input file. The resulting algorithm is
then of the fork-join type: At the beginning of each iteration, _N_
work items are created to generate a new sample on each of these
chains, and these items can be worked on independently; once done, we
start another parallel phase where the samples are post-processed. The
fork-join approach of this benchmark is implemented using a simple
thread pool that maps tasks on available worker threads. It creates as
many worker threads as std::thread::hardward_concurrency() states the
machine can provide.


# Author

Wolfgang Bangerth <bangerth@gmail.com>, Colorado State University.

The benchmark contains the deal.II library in a simplified version,
primarily stripping out all external dependencies. Many people have
contributed over the past 25 years to deal.II, see
[https://dealii.org/authors.html](this page).

The benchmark also contains the SampleFlow library; the list of
authors for SampleFlow can be found
[here](https://github.com/bangerth/SampleFlow/graphs/contributors).

Finally, deal.II contains a stripped-down version of
[BOOST](https://www.boost.org/).


# License

deal.II is licensed under the GNU LGPL 2.1 or later.

SampleFlow is licensed under the GNU LGPL 2.1.

BOOST is licensed under the [BOOST Software
License](https://www.boost.org/users/license.html).


# Workload definitions

The benchmark comes with the requisite three workloads. To execute
these, run the benchmark executable with the name of the respective
input file as the sole command line argument. The input files are as follows:

- `test.prm`: This workload utilizes 4-way parallelism for the main loop. On an ~2018 system using two AMD Epyc 7552 processors with 48 cores each, the run time for the test load is approximately as follows when using `-O3` optimization:
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

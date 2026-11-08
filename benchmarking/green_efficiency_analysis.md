# Green Efficiency Analysis

## Measurement Methodology

All measurements were taken in the same environment: a Linux remote web terminal, compiled with `[PASTE YOUR EXACT COMPILE COMMAND]`. Time was measured with `clock()` from `<time.h>` and converted to seconds by dividing by `CLOCKS_PER_SEC`. Each program was run at least three consecutive times, and the outputs were recorded without modification.

For `instrumentation_lab.c`, I took four consecutive timestamps (`t0` to `t3`) around the three phases. The end of each phase is the start of the next one, so no time is lost between phases and TOTAL equals the sum of the three phases. The final checksum test and the printing were left outside the measured region because they are not part of the computation phases.

## Observed Performance Differences

In `baseline_loop.c`, the same deterministic loop took [RUN 1] s, [RUN 2] s and [RUN 3] s. The work is identical in every run, yet the times differ slightly, which shows that execution time is not perfectly repeatable on this machine.

In `comparison_algorithms.c`, both implementations returned the same results in all three runs (625025000 and 25000), so they solve the same problem. The naive version took 2.742956 s, 2.751179 s and 2.742586 s (average 2.745574 s). The single-pass version took 0.000112 s, 0.000106 s and 0.000106 s (average 0.000108 s). The naive version was therefore about 25,400 times slower.

This matches the operation counts. The nested loop performs 50000 x 50001 / 2 = 1,250,025,000 iterations, while the single pass performs 50,000, a ratio of about 25,i001. The measured ratio of about 25,422 is very close, which supports the O(n^2) versus O(n) explanation.

In `instrumentation_lab.c`, the program reported TOTAL [X] s, BUILD_DATA [0.000294] s, PROCESS [0.000314] s and REDUCE [0.000135] s. The largest share of the time was spent in [0.000314], which is where optimization effort would pay off first.

## Relation Between Runtime and Energy Consumption

I did not measure energy; I measured only CPU time. A processor that stays busy longer generally draws power for longer, so shorter CPU time is a reasonable proxy for lower energy use. This is an assumption, not something my data proves.

Under that assumption, the naive implementation keeps the CPU busy for about 2.75 s on a task the single-pass version finishes in about 0.0001 s. If such a function ran frequently or on larger inputs, the extra CPU time would accumulate. The same argument appears in the provided sustainability article, but that article is a conceptual opinion piece without measurements, so I use it only as context.

## Limitations of the Experiment

- `clock()` reports CPU time, not wall-clock time and not energy, so energy conclusions are indirect.
- Only [N] runs were made per program, a small sample for judging variability.
- The terminal runs in a remote environment that may be shared, so other workloads could affect the timings.
- The single-pass time (about 0.1 ms) is small compared with the clock's resolution. Its spread of 0.000006 s is about 5.6% of its mean, while the naive spread of 0.008593 s is only about 0.3%, so the small measurement is the least reliable.
- Only one input size was tested, so the growth rate was not verified empirically.

## Practical Engineering Takeaway

Choosing the right algorithm mattered far more than any other factor in these experiments: a factor of roughly 25,400 in runtime came from changing the algorithm alone. Instrumenting each phase with `clock()` showed where time is actually spent, so effort goes where it matters. Repeating measurements and reporting averages is necessary because identical runs still differ slightly. Finally, runtime is only a proxy for energy, so claims about energy savings should be backed by dedicated measurements.# Green Efficiency Analysis

## Measurement Methodology

All measurements were taken in the same environment: a Linux remote web terminal, compiled with `[PASTE YOUR EXACT COMPILE COMMAND]`. Time was measured with `clock()` from `<time.h>` and converted to seconds by dividing by `CLOCKS_PER_SEC`. Each program was run at least three consecutive times, and the outputs were recorded without modification.

For `instrumentation_lab.c`, I took four consecutive timestamps (`t0` to `t3`) around the three phases. The end of each phase is the start of the next one, so no time is lost between phases and TOTAL equals the sum of the three phases. The final checksum test and the printing were left outside the measured region because they are not part of the computation phases.

## Observed Performance Differences

In `baseline_loop.c`, the same deterministic loop took [RUN 1] s, [RUN 2] s and [RUN 3] s. The work is identical in every run, yet the times differ slightly, which shows that execution time is not perfectly repeatable on this machine.

In `comparison_algorithms.c`, both implementations returned the same results in all three runs (625025000 and 25000), so they solve the same problem. The naive version took 2.742956 s, 2.751179 s and 2.742586 s (average 2.745574 s). The single-pass version took 0.000112 s, 0.000106 s and 0.000106 s (average 0.000108 s). The naive version was therefore about 25,400 times slower.

This matches the operation counts. The nested loop performs 50000 x 50001 / 2 = 1,250,025,000 iterations, while the single pass performs 50,000, a ratio of about 25,001. The measured ratio of about 25,422 is very close, which supports the O(n^2) versus O(n) explanation.

In `instrumentation_lab.c`, the program reported TOTAL [0.000743] s, BUILD_DATA [0.000294] s, PROCESS [0.000314] s and REDUCE [0.000135] s. The largest share of the time was spent in [0.000314], which is where optimization effort would pay off first.

## Relation Between Runtime and Energy Consumption

I did not measure energy; I measured only CPU time. A processor that stays busy longer generally draws power for longer, so shorter CPU time is a reasonable proxy for lower energy use. This is an assumption, not something my data proves.

Under that assumption, the naive implementation keeps the CPU busy for about 2.75 s on a task the single-pass version finishes in about 0.0001 s. If such a function ran frequently or on larger inputs, the extra CPU time would accumulate. The same argument appears in the provided sustainability article, but that article is a conceptual opinion piece without measurements, so I use it only as context.

## Limitations of the Experiment

- `clock()` reports CPU time, not wall-clock time and not energy, so energy conclusions are indirect.
- Only [N] runs were made per program, a small sample for judging variability.
- The terminal runs in a remote environment that may be shared, so other workloads could affect the timings.
- The single-pass time (about 0.1 ms) is small compared with the clock's resolution. Its spread of 0.000006 s is about 5.6% of its mean, while the naive spread of 0.008593 s is only about 0.3%, so the small measurement is the least reliable.
- Only one input size was tested, so the growth rate was not verified empirically.

## Practical Engineering Takeaway

Choosing the right algorithm mattered far more than any other factor in these experiments: a factor of roughly 25,400 in runtime came from changing the algorithm alone. Instrumenting each phase with `clock()` showed where time is actually spent, so effort goes where it matters. Repeating measurements and reporting averages is necessary because identical runs still differ slightly. Finally, runtime is only a proxy for energy, so claims about energy savings should be backed by dedicated measurements.

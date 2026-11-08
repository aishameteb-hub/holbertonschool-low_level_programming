cat > comparison_algorithms-metrics.md << 'EOF'
# comparison_algorithms metrics

Environment: Linux (remote web terminal)
Compile command: gcc -Wall -Wextra -pedantic -std=gnu99 comparison_algorithms.c -o comparison_algorithms

## Raw output

### Run 1
```
Naive algorithm result: 625025000
Naive algorithm time: 2.742956 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000112 seconds
```

### Run 2
```
Naive algorithm result: 625025000
Naive algorithm time: 2.751179 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000106 seconds
```

### Run 3
```
Naive algorithm result: 625025000
Naive algorithm time: 2.742586 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000106 seconds
```

## Averages

| Implementation | Average time (s) |
|---|---|
| Naive | 2.745574 |
| Single-pass | 0.000108 |

## iRelative difference

The naive implementation is ~25,400 times slower than the single-pass implementation (2.745574 / 0.000108 ≈ 25,422).

## Notes

The naive version is O(n^2) because of the nested loops (about 1.25 billion iterations for n = 50000); the single-pass version is O(n) (50000 iterations). The naive timings are close to each other across runs; the single-pass timings are very small (around 0.1 ms), so small absolute variations appear large in relative terms.
EOF

# Benchmark Results

## Performance Measurements

| Metric | Result |
|---|---:|
| Standalone execution time | 0.339687 seconds |
| Multi-process execution time | 22.38 seconds |
| Maximum memory usage | 1652 KB |
| CPU usage | 0% |
| IPC-related syscall time | 0.001379 seconds |

## Performance Analysis

The standalone benchmark completed in 0.339687 seconds, while the multi-process simulator took 22.38 seconds for the tested sequence.

The multi-process version has additional overhead due to process creation and FIFO-based IPC. The maximum measured memory usage was 1652 KB, and the measured IPC-related system-call time was approximately 1.379 ms.

Overall, the multi-process design provides process separation and IPC communication at the cost of additional execution overhead.

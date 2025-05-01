

# C++ Performance Benchmarks

A collection of benchmarks and optimization techniques for C/C++ code, focusing on different output methods and their performance impacts.

## Overview

This repository contains practical examples demonstrating how different output methods in C/C++ affect execution time. By understanding these performance differences, you can make informed decisions to optimize your code.

## Projects

### ExecutionTime

This benchmark compares the execution time of various output methods in C/C++:

- `printf()` to stdout
- Direct write to stdout
- No output (computation only)
- `fprintf()` to file
- `std::ofstream` to file


#### Results

From our benchmark tests:


| Method | Execution Time (ns) |
| :-- | :-- |
| printf() to stdout | 11,361 ns |
| stdout (write) | 3,335 ns |
| No output | 42 ns |
| fprintf() to file | 58,769 ns |
| std::ofstream to file | 34,235 ns |

These results clearly show how much performance can vary based on your output method choice.

#### Usage

```bash
cd ExecutionTime
g++ -o ExecutionTime main.cpp
./ExecutionTime
```


## Key Takeaways

1. Console output operations are expensive in terms of execution time
2. Direct writing to stdout is significantly faster than printf()
3. File operations are generally slower than console output
4. Modern C++ file streams (std::ofstream) outperform traditional C-style file operations
5. For performance-critical code, minimize or eliminate debug output statements

## Suggested Improvements

- Consider using conditional compilation for debug output
- In production code, use logging levels to control output verbosity
- For high-performance applications, consider buffering output


## Future Work

- Benchmark different string formatting methods
- Compare performance across different operating systems
- Analyze memory usage alongside execution time


## Contributing

Contributions are welcome! Feel free to submit pull requests with additional benchmarks or optimization techniques.

## License

MIT

---

*Note: This repository is intended for educational purposes to demonstrate performance differences between common programming patterns.*

<div style="text-align: center">⁂</div>

[^1]: Screenshot-from-2025-05-01-20-43-21.jpg


# C++ Performance Benchmarks

A collection of benchmarks and optimization techniques for C/C++ code, focusing on different output methods and their performance impacts.

## Overview

This repository contains practical examples demonstrating how different output methods in C/C++ affect execution time. By understanding these performance differences, you can make informed decisions to optimize your code.

## Projects

### ExecutionTime

This benchmark compares the execution time of various output methods in C/C++:

- `printf()` to stdout
- Direct write to stdout
- No output (computation only)
- `fprintf()` to file
- `std::ofstream` to file


#### Results

From our benchmark tests:


| Method | Execution Time (ns) |
| :-- | :-- |
| printf() to stdout | 11,361 ns |
| stdout (write) | 3,335 ns |
| No output | 42 ns |
| fprintf() to file | 58,769 ns |
| std::ofstream to file | 34,235 ns |

These results clearly show how much performance can vary based on your output method choice.

#### Usage

```bash
cd ExecutionTime
g++ -o ExecutionTime main.cpp
./ExecutionTime
```


## Key Takeaways

1. Console output operations are expensive in terms of execution time
2. Direct writing to stdout is significantly faster than printf()
3. File operations are generally slower than console output
4. Modern C++ file streams (std::ofstream) outperform traditional C-style file operations
5. For performance-critical code, minimize or eliminate debug output statements

## Suggested Improvements

- Consider using conditional compilation for debug output
- In production code, use logging levels to control output verbosity
- For high-performance applications, consider buffering output


## Future Work

- Benchmark different string formatting methods
- Compare performance across different operating systems
- Analyze memory usage alongside execution time


## Contributing

Contributions are welcome! Feel free to submit pull requests with additional benchmarks or optimization techniques.

## License

MIT

---

*Note: This repository is intended for educational purposes to demonstrate performance differences between common programming patterns.*

<div style="text-align: center">⁂</div>

[^1]: Screenshot-from-2025-05-01-20-43-21.jpg

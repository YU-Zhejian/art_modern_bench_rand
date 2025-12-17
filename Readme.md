# Readme

Various benchmarks for optimization purposes.

To run the samples, install `libboost-dev`, `libboost-all-dev`, `libabsl-dev`, `libgsl-dev`, `libpcg-cpp-dev`, and `libtestu01-0-dev` on Ubuntu.

## TODO
- Add tests for original SFMT implementation. The original SFMT supports bulk operations, which is nice.

## Conclusive Remarks

- For bulk random generator like MKL and SFMT19937, generating random numbers in bulk is much faster than generating them one by one.

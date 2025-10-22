# Readme

Various benchmarks for optimization purposes.

To run the samples, install `libboost-dev`, `libboost-all-dev`, `libabsl-dev`, `libgsl-dev`, `libpcg-cpp-dev`, and `libtestu01-0-dev` on Ubuntu.

## TODO

- VMT19937 requires bundling of file sized ~48 MiB INTO THE BINARY. See also: [This issue indicating the library may be further developed](https://github.com/fabiocannizzo/VMT19937/issues/1).
- Add tests for original SFMT implementation. The original SFMT supports bulk operations, which is nice.

## Conclusive Remarks

- For bulk random generator like MKL, VMT19937, generating random numbers in bulk is much faster than generating them one by one.

# Copyright

This project uses GPL v3 License, a copy of which is available at [License.md](License.md).

## `xoshiro` by Nessan Fitzmaurice, David Blackman and Sebastiano Vigna

Available from <https://github.com/nessan/xoshiro> under tag [v1.0.0](https://github.com/nessan/xoshiro/releases/tag/v1.1.0) and commit [176fa19](https://github.com/nessan/xoshiro/commit/176fa191c8493e4c5cb06a44bc083010664fe39b).

Affected files:

- `/deps/xoshiro/**`

The version we used (`vigna.h`) is a C++ implementation migrated from the C code of original authors (David Blackman and Sebastiano Vigna) as we're currently not supporting C++20.

The original C code is distributed under the [CC-0 license](http://creativecommons.org/publicdomain/zero/1.0/) with other files licensed under the MIT license.

## SIMD-oriented Fast Mersenne Twister (SFMT) by Mutsuo Saito and Makoto Matsumoto

Available from <http://ims.dse.ibaraki.ac.jp/rand_gen/>.

Affected files:

- `/deps/slim_sfmt-1.5.1/**`

Licensed under the 3-clause BSD license.

## Other Random Generators Recommended and Adapted by M.E. O'Neill

M.E. O'Neill, the author of the PCG random generator, had recommended several other random generators in his [blog post](https://www.pcg-random.org/posts/some-prng-implementations.html). He generously adapted those random generators from original authors and made them available under the MIT license.

Affected files in `deps/other_rngs` with their original GitHub Gist URLs:

- [`jsf.hpp`](https://gist.github.com/imneme/85cff47d4bad8de6bdeb671f9c76c814)
- [`gjrand.hpp`](https://gist.github.com/imneme/7a783e20f71259cc13e219829bcea4ac)
- [`sfc.hpp`](https://gist.github.com/imneme/f1f7821f07cf76504a97f6537c818083)
- [`lehmer.hpp`](https://gist.github.com/imneme/aeae7628565f15fb3fef54be8533e39c)
- [`splitmix.hpp`](https://gist.github.com/imneme/6179748664e88ef3c34860f44309fc71)
- [`arc4.hpp`](https://gist.github.com/imneme/4f2bf4b4f3a221ef051cf108d6b64d5a)

Licensed under the MIT license.

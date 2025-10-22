#pragma once

#include <cstdint>

#include <mkl.h>

class MKLRNGWrapper {
public:
    using result_type = std::uint32_t;
    DELETE_COPY_MOVE(MKLRNGWrapper)
    explicit MKLRNGWrapper(const MKL_INT type, const MKL_UINT seed)
    {
        vslNewStream(&stream_, type, seed);
        VSLBRngProperties brng;
        vslGetBrngProperties(type, &brng);
        min_ = (brng.IncludesZero != 0) ? 0 : 1;
        max_ = (1ULL << brng.NBits) - 1;
    }
    ~MKLRNGWrapper() { vslDeleteStream(&stream_); }
    ABSL_ATTRIBUTE_ALWAYS_INLINE result_type operator()()
    {
        result_type value = 0;
        viRngUniformBits(VSL_RNG_METHOD_UNIFORM_STD, stream_, 1, &value);
        return value;
    }
    ABSL_ATTRIBUTE_ALWAYS_INLINE result_type min() const { return min_; }
    ABSL_ATTRIBUTE_ALWAYS_INLINE result_type max() const { return max_; }

private:
    VSLStreamStatePtr stream_ = nullptr;
    result_type min_;
    result_type max_;
};

#pragma once
#include "class_utils.hh"

#include <cstdint>

#include <mkl.h>

class MKLRNGWrapper {
public:
    using result_type = std::uint32_t;
    DELETE_COPY_MOVE(MKLRNGWrapper)
    MKLRNGWrapper(MKL_INT type, MKL_UINT seed);
    ~MKLRNGWrapper();
    result_type operator()();
    result_type min() const;
    result_type max() const;

private:
    VSLStreamStatePtr stream_ = nullptr;
    result_type min_;
    result_type max_;
};

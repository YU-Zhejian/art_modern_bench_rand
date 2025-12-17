#include "mkl_rng_wrapper.hh"

MKLRNGWrapper::MKLRNGWrapper(const int type, const unsigned int seed)
{
    vslNewStream(&stream_, type, seed);
    VSLBRngProperties brng;
    vslGetBrngProperties(type, &brng);
    min_ = (brng.IncludesZero != 0) ? 0 : 1;
    max_ = (1ULL << brng.NBits) - 1;
}

MKLRNGWrapper::~MKLRNGWrapper() { vslDeleteStream(&stream_); }
MKLRNGWrapper::result_type MKLRNGWrapper::operator()()
{
    result_type value = 0;
    viRngUniformBits(VSL_RNG_METHOD_UNIFORM_STD, stream_, 1, &value);
    return value;
}
MKLRNGWrapper::result_type MKLRNGWrapper::min() const { return min_; }
MKLRNGWrapper::result_type MKLRNGWrapper::max() const { return max_; }

#include "gsl_rng_wrapper.hh"

#include <gsl/gsl_rng.h>

#include <string>

GslRngWrapper::GslRngWrapper(const gsl_rng_type* t)
    : r(gsl_rng_alloc(t))
{
}

GslRngWrapper::GslRngWrapper(const gsl_rng_type* t, result_type seed)
    : GslRngWrapper(t)
{
    gsl_rng_set(r, seed);
}
GslRngWrapper::~GslRngWrapper() { gsl_rng_free(r); }
GslRngWrapper::result_type GslRngWrapper::operator()() { return gsl_rng_get(r); }
GslRngWrapper::result_type GslRngWrapper::min() const { return gsl_rng_min(r); }
GslRngWrapper::result_type GslRngWrapper::max() const { return gsl_rng_max(r); }
std::string GslRngWrapper::name() const { return { gsl_rng_name(r) }; }

#pragma once

#include "class_utils.hh"

#include <gsl/gsl_rng.h>

#include <string>

class GslRngWrapper {
public:
    DELETE_COPY_MOVE(GslRngWrapper)
    using result_type = decltype(gsl_rng_get(nullptr));
    explicit GslRngWrapper(const gsl_rng_type* t);
    GslRngWrapper(const gsl_rng_type* t, result_type seed);
    ~GslRngWrapper();
    result_type operator()();
    [[nodiscard]] result_type min() const;
    [[nodiscard]] result_type max() const;
    [[nodiscard]] std::string name() const;

private:
    gsl_rng* r;

}; // namespace labw::art_modern

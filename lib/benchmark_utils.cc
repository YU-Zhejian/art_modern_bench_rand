#include "benchmark_utils.hh"

#include <sstream>

std::string describe(const std::vector<std::size_t>& times)
{
    auto const mean_ = mean(times);
    std::ostringstream oss;
    oss << "gmean: " << std::setw(10) << formatWithCommas(geometric_mean(times)) << "; mean/sd: " << std::setw(15)
        << formatWithCommas(mean_) + "/" + formatWithCommas(sd(times, mean_));
    return oss.str();
}
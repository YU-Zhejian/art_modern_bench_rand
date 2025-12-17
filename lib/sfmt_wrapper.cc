#include "sfmt_wrapper.hh"

#include <SFMT.h>

#include <cstdlib>
#include <vector>

SFMTRandomDevice::SFMTRandomDevice()
    : sfmt(std::malloc(sizeof(sfmt_t)))
{
    sfmt_init_gen_rand(static_cast<sfmt_t*>(sfmt), 1234);
}

std::uint32_t SFMTRandomDevice::operator()() { return sfmt_genrand_uint32(static_cast<sfmt_t*>(sfmt)); }

SFMTRandomDevice::~SFMTRandomDevice() { std::free(sfmt); }

SFMTBulkRandomDevice::SFMTBulkRandomDevice()
    : sfmt(std::malloc(sizeof(sfmt_t)))
{
    sfmt_init_gen_rand(static_cast<sfmt_t*>(sfmt), 1234);
}
void SFMTBulkRandomDevice::gen(std::vector<SFMTBulkRandomDevice::result_type>& vec)
{
    sfmt_fill_array32(static_cast<sfmt_t*>(sfmt), vec.data(), static_cast<int>(vec.size()));
}
SFMTBulkRandomDevice::~SFMTBulkRandomDevice() { std::free(sfmt); }

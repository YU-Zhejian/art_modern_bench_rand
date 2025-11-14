#pragma once
#include "class_utils.hh"

#include <absl/base/attributes.h>

#include <climits>
#include <cstdint>
#include <vector>

class SFMTRandomDevice  {
public:
    using result_type = std::uint32_t;
    DELETE_COPY_MOVE(SFMTRandomDevice)
    SPAN_RESULT_TYPE
    SFMTRandomDevice();
    ~SFMTRandomDevice();
    result_type operator()();
private:
  void* sfmt ; // The actual type is sfmt_t, but we avoid including SFMT.h here
};

class SFMTBulkRandomDevice {
public:
  using result_type = std::uint32_t;
    DELETE_COPY_MOVE(SFMTBulkRandomDevice)
    SPAN_RESULT_TYPE
    SFMTBulkRandomDevice();
    ~SFMTBulkRandomDevice();
    void gen(std::vector<result_type>& vec);
private:
  void* sfmt ; // The actual type is sfmt_t, but we avoid including SFMT.h here
};

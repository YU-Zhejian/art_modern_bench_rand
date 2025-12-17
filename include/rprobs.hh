#pragma once

#include "class_utils.hh"

#include <climits>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <string>
#include <thread>

constexpr std::size_t N_BASES = (1 << 10);
constexpr std::size_t N_TIMES = (1 << 10);
constexpr std::size_t N_REPLICA = 200UL;

std::uint64_t seed();

std::string formatWithCommas(std::size_t number);

class DumbRandomDevice {
public:
    DELETE_COPY_MOVE(DumbRandomDevice)
    using result_type = std::uint32_t;
    SPAN_RESULT_TYPE
    DumbRandomDevice() = default;
    ~DumbRandomDevice() = default;
    result_type operator()();
};

class CustomRandomDevice {
public:
    DELETE_COPY_MOVE(CustomRandomDevice)
    using result_type = std::uint32_t;
    SPAN_RESULT_TYPE
    explicit CustomRandomDevice(const std::string& path = "/dev/random");
    ~CustomRandomDevice();
    result_type operator()();

private:
    std::ifstream rand_stream_;
    std::string path_;
};

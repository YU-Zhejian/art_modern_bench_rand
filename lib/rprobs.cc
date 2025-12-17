#include "rprobs.hh"

#include <chrono>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <ios>
#include <string>
#include <thread>

std::uint64_t seed()
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch())
               .count()
        * std::hash<std::thread::id>()(std::this_thread::get_id());
}
std::string formatWithCommas(std::size_t number)
{
    std::string numStr = std::to_string(number);
    int insertPosition = static_cast<int>(numStr.length()) - 3;

    while (insertPosition > 0) {
        numStr.insert(insertPosition, ",");
        insertPosition -= 3;
    }

    return numStr;
}

CustomRandomDevice::result_type CustomRandomDevice::operator()()
{
    result_type random_number = 0;
    rand_stream_.read(reinterpret_cast<char*>(&random_number), sizeof(random_number));
    if (rand_stream_.fail()) {
        throw std::system_error(errno, std::generic_category(), "Failed to read from " + path_);
    }
    return random_number;
}

DumbRandomDevice::result_type DumbRandomDevice::operator()() { return 0; }

CustomRandomDevice::CustomRandomDevice(const std::string& path)
    : rand_stream_(path, std::ios::binary)
    , path_(path)
{
    if (!rand_stream_.is_open()) {
        std::abort();
    }
}
CustomRandomDevice::~CustomRandomDevice()
{
    if (rand_stream_.is_open()) {
        rand_stream_.close();
    }
}

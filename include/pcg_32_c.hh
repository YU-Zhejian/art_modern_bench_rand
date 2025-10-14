#pragma once

#include "class_utils.hh"

#include <chrono>
#include <cstdint>

/**
 * Minimalist PCG32 implementation in C.
 *
 * See: <https://github.com/imneme/pcg-c-basic>
 *
 * *Really* minimal PCG32 code / (c) 2014 M.E. O'Neill / pcg-random.org
 * Licensed under Apache License 2.0 (NO WARRANTY, etc. see website)
 */
class pcg32_c {
public:
    pcg32_c(uint64_t state, uint64_t inc)
        : state(state)
        , inc(inc) { };

    pcg32_c()
        : pcg32_c { 0x853c49e6748fea9bULL, 0xda3e39cb94b95bdbULL } { };
    ~pcg32_c() = default;

    DELETE_COPY_MOVE(pcg32_c)
    using result_type = uint32_t;
    SPAN_RESULT_TYPE

    uint32_t operator()()
    {
        uint64_t const oldstate = state;
        // Advance internal state
        state = oldstate * 6364136223846793005ULL + (inc | 1);
        // Calculate output function (XSH RR), uses old state for max ILP
        uint32_t const xorshifted = ((oldstate >> 18U) ^ oldstate) >> 27U;
        uint32_t const rot = oldstate >> 59U;
        return (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
    }

    void seed(const uint64_t initstate, const uint64_t initseq)
    {
        state = 0U;
        inc = (initseq << 1U) | 1U;
        (void)(*this)();
        state += initstate;
        (void)(*this)();
    }

    void seed()
    {
        auto now = std::chrono::system_clock::now().time_since_epoch().count();
        auto addr = reinterpret_cast<intptr_t>(this);
        seed(now, addr);
    }

private:
    uint64_t state;
    uint64_t inc;
};

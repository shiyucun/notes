
#pragma once

#include <assert.h>
#include <random>

class Random {
    using RandomDevice_t = std::random_device;
    using RandomEngine_t = std::mt19937;
public:
    explicit Random() {
        m_random_engine = std::mt19937(m_random_device());
    }

    ~Random() = default;

    int32_t GetRangeInt(int32_t begin, int32_t end) {
        assert (begin <= end);

        if (begin == end) {
            return
                begin;
        }

        std::uniform_int_distribution<int32_t> distribution(begin, end);
        return distribution(m_random_engine);
    }

    double GetRangeDouble(double begin, double end) {
        assert (begin <= end);

        if (begin == end) {
            return begin;
        }

        std::uniform_real_distribution<double> distribution(begin, end);
        return distribution(m_random_engine);
    }

private:
    RandomDevice_t m_random_device;
    RandomEngine_t m_random_engine;
};

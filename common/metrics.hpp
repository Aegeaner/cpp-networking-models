#pragma once

#include <atomic>
#include <iostream>
#include <chrono>

namespace networking_lab {

struct Metrics {
    std::atomic<uint64_t> requests_processed{0};
    std::atomic<uint64_t> bytes_transferred{0};
    std::atomic<uint64_t> active_connections{0};

    void report() const {
        std::cout << "[Metrics] Requests: " << requests_processed 
                  << ", Bytes: " << bytes_transferred 
                  << ", Active Conns: " << active_connections << std::endl;
    }
};

} // namespace networking_lab

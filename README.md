# C++ Networking Models Lab

An educational project comparing different high-performance networking models in C++.
This repository contains reference implementations of a simple Redis-like protocol server using various architectural patterns.

## Project Structure

- **common/**: Shared protocol parser and metrics utilities.
- **1-blocking/**: Thread-per-connection model (C++17).
- **2-thread_pool/**: Fixed thread pool model (C++17).
- **3-asio_callback/**: Asynchronous callback model using Asio (C++17).
- **4-asio_coroutine/**: Coroutine-based model using Asio (C++20).
- **5-libevent/**: C-style Reactor pattern using Libevent (C++17 wrappers).
- **6-seastar/**: Shared-nothing thread-per-core model using Seastar (C++20).

## Build Instructions

### Prerequisites
- CMake 3.16+
- C++20 compatible compiler (GCC 10+, Clang 10+, MSVC 2019+)
- Dependencies (for specific modules):
    - Asio (Standalone)
    - Libevent
    - Seastar

### Building
```bash
mkdir build && cd build
cmake ..
cmake --build .
```

## Protocol
Simple text-based protocol:
- `SET key value`
- `GET key`

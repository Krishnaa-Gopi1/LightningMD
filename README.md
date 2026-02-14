# LightningMD

LightningMD is a high-performance C++ tick analytics engine built for quantitative trading systems.

## v0 - Phase 1

- CSV tick ingestion
- Tick struct
- Engine pipeline architecture
- Clean CMake build system
- Modular include/src separation

## Build Instructions

mkdir build \
cd build \
cmake -G "MinGW Makefiles" .. \
mingw32-make \
./LightningMD 

## Future Work

- Streaming ingestion
- Rolling VWAP
- Lock-free queues
- Multi-threading
- Memory pool allocator

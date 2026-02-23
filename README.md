# LightningMD

LightningMD is a high-performance C++ tick analytics engine built for quantitative trading systems. \
This project focuses on systems design, performance engineering, and low-latency analytics — similar to infrastructure used in quantitative trading systems.


## v0 - Data Stream Pipeline

- CSV tick ingestion
- Tick struct
- Engine pipeline architecture
- Clean CMake build system
- Modular include/src separation

## v1.0 - Rolling VWAP and Volatility 

- Rolling VWAP (O(1) per tick)
- Rolling Volatility (O(1) per tick)
- Fixed-size sliding window
- CSV tick ingestion
- Synthetic market data testing
- Modular analytics architecture

## Rolling Volume Weighted Average Price (VWAP)

Maintains:

- sum(price × quantity)
- sum(quantity)

Formula:

VWAP = sum(price × quantity) / sum(quantity)

Oldest tick is removed when window exceeds N.

Time Complexity: O(1)

---

## Rolling Volatility

Maintains:

- sum(price)
- sum(price²)

Variance computed using:

Var = (sum(price²) / N) − (mean²)

Volatility = sqrt(Var)

Time Complexity: O(1)

## Build Instructions

mkdir build \
cd build \
cmake -G "MinGW Makefiles" .. \
mingw32-make \
./LightningMD

## Future Work

- Replace std::deque with circular buffer
- Pre-allocated memory
- Remove dynamic allocations
- Micro-benchmarking


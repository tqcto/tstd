# tstd
tstd is my standard library.
tstd have some utilities.
For example, directory suite, file suite, memory handler etc.

# Build

### Prerequisites
- CMake 3.15 or higher
- C++17

### Build Instructions

Release build for MSBuild :

```bash
# 1. Clone this repository
git clone https://github.com/tqcto/tstd.git
# 2. Configure the build directory
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
# 3. Build the library/executable
cmake --build build --config Release
```

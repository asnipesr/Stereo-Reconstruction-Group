# Stereo-Reconstruction-Group
Spring 2022 cs241 repository

### Installation instructions: 
- Required programs: CMake, VCPKG 
- Recommended: VS2019+ for development
- use vcpkg to install `opencv3:x64-windows`
- In the project directory, run `cmake -B out -S . -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake`
- Then to run the project (if not using an IDE) run `cmake --build out`
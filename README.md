# Stereo-Reconstruction-Group
Spring 2022 cs241 repository

### Installation instructions: 
- Required programs: CMake, VCPKG 
- Recommended: VS2019+ for development
- use vcpkg to install `opencv3:x64-windows`
- In the project directory, run `cmake -B out -S . -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake`
- Then to run the project (if not using an IDE) run `cmake --build out`
- If you get a bunch of errors about cvdef.h, you'll have to open the file up and comment out line 64 (for some reason it's a file that's used by the legacy C api but it has namespaces in it?)
# Stereo-Reconstruction-Group
Spring 2022 cs241 repository

### Installation instructions: 
- Required programs: CMake, VCPKG 
- Recommended: VS2019+ for development
- use vcpkg to install `opencv:x64-windows`
- In the project directory, run `cmake -B out -S . -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake`
- Then to run the project (if not using an IDE) run `cmake --build out`
- Make sure to run the executable from `main.c` and not `match_points.cpp`


### External data:
- images from [here](https://vision.middlebury.edu/stereo/data/)

### Citations:
- H. Hirschmüller and D. Scharstein. Evaluation of cost functions for stereo matching.
  In IEEE Computer Society Conference on Computer Vision and Pattern Recognition (CVPR 2007), Minneapolis, MN, June 2007.
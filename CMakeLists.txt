cmake_minimum_required (VERSION 3.8)

project ("Stereo-Reconstruction-Group")

find_package(OpenCV REQUIRED)

add_executable (Stereo-Reconstruction-Group "main.c" "main.h")

target_link_libraries(Stereo-Reconstruction-Group opencv_core opencv_imgcodecs) # if any specific opencv components are required, this is where they go
cmake_minimum_required (VERSION 3.8)

project ("Stereo-Reconstruction-Group")

set(OpenCV_DIR /Users/nguyencanhminh/build_opencv)


find_package (OpenCV REQUIRED)

ADD_LIBRARY(match_points STATIC "match_points.cpp" "match_points.h")
ADD_EXECUTABLE (${PROJECT_NAME} "main.c")
TARGET_LINK_LIBRARIES (match_points ${OpenCV_LIBS}) 
TARGET_LINK_LIBRARIES (${PROJECT_NAME} match_points)


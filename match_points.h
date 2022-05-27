#pragma once
#ifdef __cplusplus
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

using namespace cv;
using namespace std;

#endif

#ifdef __cplusplus
extern "C" {
#endif
	struct {
		double x;
		double y;
	} typedef Pos;

	struct {
		int width;
		int length;
		Pos** points;
	} typedef Points;

	void get_match_points(char* file1, char* file2, Points** points, double threshold);
	void display_depths(double* points, int width, int height);
#ifdef __cplusplus
}
#endif

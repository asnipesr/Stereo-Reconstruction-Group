#include "main.h"

#include <stdio.h>
#include <opencv2/imgcodecs/imgcodecs_c.h>

int main(int argc, char* argv[])
{
	IplImage* img1 = cvLoadImage("test.png", 1);
	if (img1 == NULL) {
		printf("Invalid image file!\n");
		return -1;
	}
	IplImage* img2 = cvLoadImage("test2.png", 1);
	if (img2 == NULL) {
		printf("Invalid image file!\n");
		return -1;
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "match_points.h"


typedef struct
{
	double x;
	double y;
	double z;
} vector;

int main(int argc, char* argv[])
{
	Points* p = malloc(sizeof(Points));

	int baseline = 5;

	int width = 1920;
	int height = 1080;


	//// I CHANGE HERE
	vector camera1_pos = { width / 2, height / 1, 0 };
	vector camera2_pos = { 50 + width / 2, height / 1, 0 };

	get_match_points("./images/im0.png", "./images/im1.png", &p, 0.82);


	double* dists = calloc((width / 1) * (height / 1), sizeof(double));
	printf("%lld\n", (width / 1) * (height / 1) * sizeof(double));
	if (dists == NULL) {
		printf("Why?");
		exit(-1);
	}

	for (int i = 0; i < height / 1; i++){
		for (int j = 0; j < width / 1; j++)
		{
			double approx_img2_x;
			double approx_img2_y;
			// nearest matching point
			double minDistance = 5000;
			int correspondingMatchPoint = 0;

			for (int y = 0; y < p->length; y++)
			{
				// match point from img1
				Pos p1 = p->points[0][y];
				double dist = (double)sqrt(pow(j - p1.x, 2) + pow(i - p1.y, 2));
				if (dist < minDistance) {
					minDistance = dist;
					correspondingMatchPoint = y;
				}

			}

			// match point in img1 and img2
			Pos p1 = p->points[0][correspondingMatchPoint];
			Pos p2 = p->points[1][correspondingMatchPoint];

			// minDistance = 0 ---> is match point
			if (minDistance != 0)
			{
				// offset
				double offsetX = (double)(p2.x - p1.x);
				double offsetY = (double)(p2.y - p1.y);

				approx_img2_x = j + offsetX;
				approx_img2_y = i + offsetY;
			}
			else
			{
				approx_img2_x = (double)p2.x;
				approx_img2_y = (double)p2.y;
			}


			// Interception of C1 - (i, j) and C2 - (approx_img2_x, approx_img2_y)
			// Calculate distances 
			double a1 = (i - camera1_pos.y) / (j - camera1_pos.x);
			double a2 = (approx_img2_y - camera2_pos.y) / (approx_img2_x - camera2_pos.x);

			double b1 = i - a1 * j;
			double b2 = approx_img2_y - a2 * approx_img2_x;

			double intercept_x = (b2 - b1) / (a1 - a2);
			double intercept_y = a1 * intercept_x + b1;

			double distance_1 = (double)sqrt(pow(intercept_x - camera1_pos.x, 2) + pow(intercept_y - camera1_pos.y, 2));
			dists[(i * (width / 1)) + j] = distance_1;
			//int distance_2 = sqrt(pow(intercept_x - camera2_pos.x, 2) + pow(intercept_y - camera2_pos.y, 2));


			// printf("%f, %f, %d, %d \n", intercept_x, intercept_y, distance_1, distance_2);
		}
	}

	display_depths(dists, width / 1, height / 1);
}

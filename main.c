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

int main(int argc, char *argv[])
{
	Points *p = malloc(sizeof(Points));

	int baseline = 5;

	int width = 1920;
	int height = 1080;

	vector camera1_pos = {50 + width / 2, height / 2, 0};
	vector camera2_pos = {width / 2, height / 2, 0};

	get_match_points("./images/im0.png", "./images/im1.png", &p, 0.8);
	
	for (int i = 0; i < width / 100; i++)
	{
		for (int j = 0; j < height / 100; j++)
		{
			int approx_img2_x;
			int approx_img2_y;
			// nearest matching point
			int minDistance = INT8_MAX;
			int correspondingMatchPoint;

			for (int y; y < p->length; y++)
			{
				// match point from img1
				Pos p1 = p->points[0][y];
				int dist = sqrt(pow(i - p1.x, 2) + pow(j - p1.y, 2));
				minDistance = (minDistance < dist) ? minDistance : dist;
				correspondingMatchPoint = y;
			}

			// match point in img1 and img2
			Pos p1 = p->points[0][correspondingMatchPoint];
			Pos p2 = p->points[1][correspondingMatchPoint];

			// minDistance = 0 ---> is match point
			if (minDistance != 0)
			{
				// offset
				int offsetX = p2.x - p1.x;
				int offsetY = p2.y - p1.y;

				approx_img2_x = i + offsetX;
				approx_img2_y = j + offsetY;
			}
			else
			{
				approx_img2_x = p2.x;
				approx_img2_y = p2.y;
			}


			// Interception of C1 - (i, j) and C2 - (approx_img2_x, approx_img2_y)
			// Calculate distances 
			double a1 = (j - camera1_pos.y) / (i - camera1_pos.x);
			double a2 = (approx_img2_y - camera2_pos.y) / (approx_img2_x- camera2_pos.x);

			double b1 = j - a1 * i;
			double b2 = approx_img2_y - a2 * approx_img2_x;

			double intercept_x = (b2 - b1) / (a1 - a2);
			double intercept_y = a1 * intercept_x + b1;

			int distance_1 = sqrt(pow(intercept_x - camera1_pos.x, 2) + pow(intercept_y - camera1_pos.y, 2));
			int distance_2 = sqrt(pow(intercept_x - camera2_pos.x, 2) + pow(intercept_y - camera2_pos.y, 2));


			printf("%f, %f, %d, %d \n", intercept_x, intercept_y, distance_1, distance_2);
		}
	}

	// for (int y = 0; y < p->length; y++)
	// {
	// 	// match point from img1
	// 	Pos p1 = p->points[0][y];
	// 	// corresponding in img2
	// 	Pos p2 = p->points[1][y];

	// 	double a1 = (p1.y - camera1_pos.y) / (p1.x - camera1_pos.x);
	// 	double a2 = (p2.y - camera2_pos.y) / (p2.x - camera2_pos.x);

	// 	double b1 = p1.y - a1 * p1.x;
	// 	double b2 = p2.y - a2 * p2.x;

	// 	double intercept_x = (b2 - b1) / (a1 - a2);
	// 	double intercept_y = a1 * intercept_x + b1;

	// 	int distance_1 = sqrt(pow(intercept_x - camera1_pos.x, 2) + pow(intercept_y - camera1_pos.y, 2));
	// 	int distance_2 = sqrt(pow(intercept_x - camera2_pos.x, 2) + pow(intercept_y - camera2_pos.y, 2));

	// 	// printf("%f, %f, %d, %d ", intercept_x, intercept_y, distance_1, distance_2);
	// 	// printf("\n");
	// }
}

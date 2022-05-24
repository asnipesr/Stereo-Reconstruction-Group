#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "match_points.h"


typedef struct {
	double x;
	double y;
	double z;
} vector;

int main(int argc, char* argv[]) {
	Points* p = malloc(sizeof(Points));
	
	int baseline = 5;

	int width = 1920;
	int height = 1080;

	vector camera1_pos = { 97.99 + width / 2, height / 2, 0 };
	vector camera2_pos = { width / 2, height / 2, 0 };

	get_match_points("..\\..\\..\\images\\im0.png", "..\\..\\..\\images\\im1.png", &p, 0.8);

	for (int y = 0; y < p->length; y++) {
		for (int x = 0; x < p->width; x++) {
			printf("%f, %f  ", p->points[x][y].x, p->points[x][y].y);
		}
		printf("\n");
	}
}
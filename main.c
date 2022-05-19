#include <stdio.h>
#include <stdlib.h>
#include "match_points.h"


typedef struct {
	double x;
	double y;
	double z;
} vector;

int main(int argc, char *argv[]) {
	Points* p = malloc(sizeof(Points));
	vector camera1_pos = { 3, 0, 0 };
	vector camera2_pos = { 0, 0, 0 };
	get_match_points("..\\..\\..\\images\\view0.png", "..\\..\\..\\images\\view1.png", &p);

	for (int y = 0; y < p->length; y++) {
		for (int x = 0; x < p->width; x++) {
			printf("%f, %f  ", p->points[x][y].x, p->points[x][y].y);
		}
		printf("\n");
	}
}
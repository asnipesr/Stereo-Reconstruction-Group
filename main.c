#include <stdio.h>
#include <stdlib.h>
#include "match_points.h"


int main(int argc, char *argv[]) {
	Points* p = malloc(sizeof(Points));

	get_match_points("..\\..\\..\\images\\view0.png", "..\\..\\..\\images\\view1.png", &p);

	for (int y = 0; y < p->length; y++) {
		for (int x = 0; x < p->width; x++) {
			printf("%f, %f  ", p->points[x][y].x, p->points[x][y].y);
		}
		printf("\n");
	}
}
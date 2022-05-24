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
	FILE* config = fopen("..\\..\\images\\calib.txt", "r");
	char line[255];
	int baseline = 0;

	while (fgets(line, 255, config)) {
		if (strncmp("baseline", line, 9) == 0) {
			char num[10] = { 0 };
			strcpy(line[9], num);
			num[9] = '\0';
			baseline = atoi(num);
			printf("%d\n", baseline);
		}
	}

	vector camera1_pos = { 3, 0, 0 };
	vector camera2_pos = { 0, 0, 0 };
	get_match_points("..\\..\\images\\im0.png", "..\\..\\images\\im1.png", &p, 0.8);

	for (int y = 0; y < p->length; y++) {
		for (int x = 0; x < p->width; x++) {
			printf("%f, %f  ", p->points[x][y].x, p->points[x][y].y);
		}
		printf("\n");
	}
}
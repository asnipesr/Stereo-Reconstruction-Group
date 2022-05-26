#include "match_points.h"

void get_match_points(char* file1, char* file2, Points** points, double threshold) {
	Mat img1 = imread(file1, ImreadModes::IMREAD_GRAYSCALE);
	if (img1.empty()) {
		printf("Invalid image!\n");
		exit(-1);
	}
	Mat img2 = imread(file2, ImreadModes::IMREAD_GRAYSCALE);
	if (img2.empty()) {
		printf("Invslid image!\n");
		exit(-1);
	}

	Ptr<ORB> orb = ORB::create();
	Ptr<BFMatcher> matcher = BFMatcher::create();

	vector<KeyPoint> queryKeypoints, trainKeypoints;
	Mat queryDescriptors, trainDescriptors;

	orb->detectAndCompute(img1, noArray(), queryKeypoints, queryDescriptors);
	orb->detectAndCompute(img2, noArray(), trainKeypoints, trainDescriptors);

	vector<vector<DMatch>> matches;
	vector<DMatch> goodMatches;

	vector<KeyPoint> goodQueryKeypoints;
	vector<KeyPoint> goodTrainKeypoints;


	matcher->knnMatch(queryDescriptors, trainDescriptors, matches, 2);
	for (int i = 0; i < matches.size(); i++) {
		if (matches[i][0].distance < threshold * matches[i][1].distance) {
			goodMatches.push_back(matches[i][0]);
			goodQueryKeypoints.push_back(queryKeypoints[matches[i][0].queryIdx]);
			goodTrainKeypoints.push_back(trainKeypoints[matches[i][0].trainIdx]);
		}
	}
	Mat o;
	drawMatches(img1, queryKeypoints, img2, trainKeypoints, goodMatches, o);
	imshow("matches", o);
	waitKey();

	vector<Point2f> queryPoints;
	vector<Point2f> trainPoints;

	KeyPoint::convert(goodQueryKeypoints, queryPoints);
	KeyPoint::convert(goodTrainKeypoints, trainPoints);

	vector<Pos> queryPos;
	vector<Pos> trainPos;
	Pos** p = new Pos*[2];
	p[0] = new Pos[queryPoints.size()];
	p[1] = new Pos[queryPoints.size()];
	for (int i = 0; i < queryPoints.size(); i++) {
		Pos q = { queryPoints[i].x, queryPoints[i].y };
		Pos t = { trainPoints[i].x, queryPoints[i].y };
		queryPos.push_back(q);
		trainPos.push_back(t);
		p[0][i] = q;
		p[1][i] = t;
	}

	(*points)->points = p;
	(*points)->width = 2;
	(*points)->length = (int)queryPos.size();
}

void display_depths(int* points, int width, int height) {
	int min = points[0];
	int max = points[0];
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (points[(i * width) + j] < min) {
				min = points[(i * width) + j];
			}
			if (points[(i * width) + j] > max) {
				max = points[(i * width) + j];
			}
		}
	}
	std::cout << "[";
	for (int i = 0; i < height; i++) {
		std::cout << "[";
		for (int j = 0; j < width; j++) {
			points[(i * width) + j] = (points[(i * width) + j] - min) * 255 / max;
			std::cout << points[(i * width) + j] << ",";
		}
		std::cout << "],";
	}
	std::cout << "]";

}
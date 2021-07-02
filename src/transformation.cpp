#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include "opencv2/highgui/highgui.hpp"

#include "../inc/transformation.h"
#include "../inc/mouse.h"

using namespace std;
using namespace cv;


//// Affine Transforamtion of number plate
//// Find points from image and distination points
//// Number of points needed: 3
////vector<Point2f> sourcePlate, destinationPlate;
////sourcePlate = { Point2f(400,250), Point2f(400,320), Point2f(200,330) };
////destinationPlate = { Point2f(770,350), Point2f(770,450), Point2f(250,370) };
void affline_transform(Mat& org_image, Mat& transformed_image) {
	namedWindow("Original Plate", 1);
	setMouseCallback("Original Plate", platePoints, NULL);

	imshow("Original Plate", org_image);

	waitKey(0);

	// Calculate the affine matrix from the found points in the image
	Mat affineMatrix = getAffineTransform(pointsPlate, destinationPlate);
	// Apply the affine transformation on the image
	warpAffine(org_image, transformed_image, affineMatrix, org_image.size());

}

//// Perspective Transformation of snooker table
//// Find points from image and distination points
// //// Number of points needed: 4
////vector<Point2f> sourceSnooker, destinationSnooker;
////sourceSnooker = { Point2f(338,645), Point2f(671,650), Point2f(922,916), Point2f(101,919) };
////destinationSnooker = { Point2f(278,223), Point2f(785,220), Point2f(830,905), Point2f(205,907) };
void prespective_transform(Mat& org_image, Mat& transformed_image) {
	namedWindow("Original Snooker", 1);
	setMouseCallback("Original Snooker", snookerPoints, NULL);

	imshow("Original Snooker", org_image);

	waitKey(0);

	// Calculate the perspective matrix from the found points in the image
	Mat perspectiveMatrix = getPerspectiveTransform(pointsSnooker, destinationSnooker);
	// Apply the perspective transformatin on the image
	warpPerspective(org_image, transformed_image, perspectiveMatrix, transformed_image.size());

}


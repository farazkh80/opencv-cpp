#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include "opencv2/highgui/highgui.hpp"

#include "../inc/transformation.h"
#include "../inc/mouse.h"

using namespace std;
using namespace cv;


//// Affine Transforamtion of number plate
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

//// Hough transform lines
void hough_transform_lines(Mat& org_img, Mat& line_detected_img) {
	//edge detection
	Canny(org_img, line_detected_img, 200, 255);

	// hough transform
	vector<Vec2f> lines;
	HoughLines(line_detected_img, lines, 1, CV_PI, 150);

	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;

		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));

		line(line_detected_img, pt1, pt2, Scalar(0, 0, 255), 3, LINE_AA);
	}
}

//// Hough transform lines probabilistic
void hough_transform_lines_prob(Mat& org_img, Mat& line_detected_img) {
	// Edge detection
	Canny(org_img, line_detected_img, 200, 255);

	// Hough transform probabilistic
	vector<Vec4i> linesP;
	HoughLinesP(line_detected_img, linesP, 1, CV_PI / 180, 50, 50, 10);

	// Draw the lines
	for (size_t i = 0; i < linesP.size(); i++)
	{
		Vec4i l = linesP[i];
		line(line_detected_img, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, LINE_AA);
	}
}

//// Hough transform circles
void hough_transform_circles(Mat& org_img, Mat& circle_detected_img) {
	Mat gray;
	cvtColor(org_img, gray, COLOR_RGB2GRAY);

	medianBlur(gray, gray, 5);

	vector<Vec3f> circles;
	HoughCircles(gray, circles, HOUGH_GRADIENT, 1,
		gray.rows / 32,  // change this value to detect circles with different distances to each other
		100, 20, 1, 15 // change the last two parameters
   // (min_radius & max_radius) to detect larger circles
	);

	for (size_t i = 0; i < circles.size(); i++)
	{
		Vec3i c = circles[i];
		Point center = Point(c[0], c[1]);
		// circle center
		circle(circle_detected_img, center, 1, Scalar(0, 100, 100), 3, LINE_AA);
		// circle outline
		int radius = c[2];

		circle(circle_detected_img, center, radius, Scalar(255, 0, 255), 3, LINE_AA);
	}
}

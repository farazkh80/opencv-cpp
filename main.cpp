#include <iostream>
#include <vector>
#include <map>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include "colorBounds.h"

using namespace std;
using namespace cv;

// Bluring functions
void GaussianBlurImage(const Mat& org, Mat& gaussianBlured) {
	GaussianBlur(org, gaussianBlured, Size(1, 1), 9, 9);
}
void medianBlurImage(const Mat& org, Mat& medianBlured) {
	medianBlur(org, medianBlured, 9);
}
// Color Scaling functions
void grayScaleImage(const Mat& org, Mat& grayScaled) {
	cvtColor(org, grayScaled, COLOR_BGR2GRAY);
}
void manualGrayScaleImage(const Mat& org, Mat& grayScaled) {
	for (int i = 0; i < org.rows; i++) {
		for (int j = 0; j < org.cols; j++) {

			Vec3b bgrPixel = org.at<Vec3b>(i, j);

			unsigned char grayScale = (bgrPixel[2] + bgrPixel[1] + bgrPixel[0]) / 3;

			grayScaled.at<Vec3b>(i, j) = { grayScale, grayScale, grayScale };

		}
	}
}
void BGR2HSV(const Mat& org, Mat& hsvImg) {
	cvtColor(org, hsvImg, COLOR_BGR2HSV);
}

void detectColor(const Mat& hsvImg, Mat& colorDetectedImage, vector<int>& lower_bound, vector<int>& upper_bound) {
	int low_H = lower_bound[0], low_S = lower_bound[1], low_V = lower_bound[2];
	int high_H = upper_bound[0], high_S = upper_bound[1], high_V = upper_bound[2];
	cout << high_H << " " << low_S << endl;
	inRange(hsvImg, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), colorDetectedImage);
}
int main()
{
	// Get the image path
	string image_path = "C:/C++-Projs/opencvtest/images/Niels_Feijen_NL.jpg";

	// read the image
	Mat image1 = imread(image_path, IMREAD_COLOR);

	// resize the image
	resize(image1, image1, Size(500, 500));
	imshow("original img ", image1);

	//// Turn to gray scale
	Mat grayScaledImg;
	grayScaleImage(image1, grayScaledImg);

	//imshow("gray Scale ", grayScaledImg);

	// Blur Image
	Mat medianBluredImg, guassianBluredImg;
	medianBlurImage(image1, medianBluredImg);
	GaussianBlurImage(image1, guassianBluredImg);

	//imshow("meidanBlurImg ", medianBluredImg);
	//imshow("guassianBlurImg ", guassianBluredImg);


	//convert from BGR to HSV
	Mat hsvImg, imgThreshold;
	BGR2HSV(image1, hsvImg);
	//imshow("HSV Image ", hsvImg);

	// Detect the object based on HSV Range Values
	detectColor(hsvImg, imgThreshold, BLUE_LOWER_BOUND, BLUE_UPPER_BOUND);
	imshow("Threshold Image ", imgThreshold);

	int k = waitKey(0);

	return 0;
}
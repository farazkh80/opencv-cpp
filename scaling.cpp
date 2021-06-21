#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include "scaling.h"

using namespace std;
using namespace cv;

/* Color Scaling functions */
// Returns a Gray Scaled Version of the image passed
void gray_scale_image(const Mat& org_img, Mat& gray_scaled_img) {
	cvtColor(org_img, gray_scaled_img, COLOR_BGR2GRAY);
}

// Returns a Gray Scaled Version of the image passed
void manual_gray_scale_image(const Mat& org_img, Mat& gray_scaled_img) {
	for (int i = 0; i < org_img.rows; i++) {
		for (int j = 0; j < org_img.cols; j++) {

			Vec3b bgrPixel = org_img.at<Vec3b>(i, j);

			unsigned char gray_scale = (bgrPixel[2] + bgrPixel[1] + bgrPixel[0]) / 3;

			gray_scaled_img.at<Vec3b>(i, j) = { gray_scale, gray_scale, gray_scale };

		}
	}
}

// Returns a HSV Scaled Version of the image passed
void BGR_2_HSV(const Mat& org_img, Mat& hsv_img) {
	cvtColor(org_img, hsv_img, COLOR_BGR2HSV);
}


/* Color detection functions */
// Returns a Color Detected version of the image passed in color range [lower_bound, upper_bound]
void detect_color(const Mat& hsv_img, Mat& color_detected_img, vector<int>& lower_bound, vector<int>& upper_bound) {
	int low_H = lower_bound[0], low_S = lower_bound[1], low_V = lower_bound[2];
	int high_H = upper_bound[0], high_S = upper_bound[1], high_V = upper_bound[2];
	cout << high_H << " " << low_S << endl;
	inRange(hsv_img, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), color_detected_img);
}

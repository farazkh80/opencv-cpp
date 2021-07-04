#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#include "../inc/binary_vision.h"
#include "../inc/scaling.h"

using namespace std;
using namespace cv;


/* Binary Vision helper functions */

// Thresholding functions
void binary_regular_threshold_image(const Mat& org_img, Mat& binary_img, int threshold_value) {
	Mat gray;
	gray_scale_image(org_img, gray);

	threshold(gray, binary_img, threshold_value, 255, THRESH_BINARY);
}

void binary_otsu_threshold_image(const Mat& org_img, Mat& binary_img, int threshold_value) {
	Mat gray;
	gray_scale_image(org_img, gray);

	threshold(gray, binary_img, threshold_value, 255, THRESH_BINARY | THRESH_OTSU);
}

void binary_band_threshold_image(const Mat& org_img, Mat& binary_img, int low_threshold_value, int high_threshold_value) {
	Mat binary_img_1, binary_img_2;

	threshold(org_img, binary_img_1, low_threshold_value, 255, THRESH_BINARY);
	threshold(org_img, binary_img_2, high_threshold_value, 255, THRESH_BINARY_INV);

	bitwise_and(binary_img_1, binary_img_2, binary_img);
}

void binary_adaptive_threshold_image(const Mat& org_img, Mat& binary_img, int block_size, double offset) {
	Mat gray;
	gray_scale_image(org_img, gray);

	adaptiveThreshold(gray, binary_img, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, block_size, offset);
}

// Mathematical Morphology functions
void binary_dilate_default(const Mat& org_binary_img, Mat& dilated_img) {
	dilate(org_binary_img, dilated_img, Mat());
}

void binary_dilate_custom(const Mat& org_binary_img, Mat& dilated_img, int structuring_elem_h, int structuring_elem_w) {
	Mat structuring_element(structuring_elem_h, structuring_elem_w, CV_8U, Scalar(1));
	dilate(org_binary_img, dilated_img, structuring_element);
}

void binary_erode_default(const Mat& org_binary_img, Mat& eroded_img) {
	erode(org_binary_img, eroded_img, Mat());
}

void binary_erode_custom(const Mat& org_binary_img, Mat& eroded_img, int structuring_elem_h, int structuring_elem_w) {
	Mat structuring_element(structuring_elem_h, structuring_elem_w, CV_8U, Scalar(1));
	erode(org_binary_img, eroded_img, structuring_element);
}

void binary_open_custom(const Mat& org_binary_img, Mat& opened_img, int structuring_elem_h, int structuring_elem_w) {
	Mat structuring_element(structuring_elem_h, structuring_elem_w, CV_8U, Scalar(1));
	morphologyEx(org_binary_img, opened_img, MORPH_OPEN, structuring_element);
}

void binary_close_custom(const Mat& org_binary_img, Mat& closed_img, int structuring_elem_h, int structuring_elem_w) {
	Mat structuring_element(structuring_elem_h, structuring_elem_w, CV_8U, Scalar(1));
	morphologyEx(org_binary_img, closed_img, MORPH_CLOSE, structuring_element);
}

// Draws contours on a copy of passed image with random colours
void extract_contours(const Mat& org_img, Mat& contoured_img, int threshold_value) {
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	Mat binary_img;
	binary_regular_threshold_image(org_img, binary_img, threshold_value);

	findContours(binary_img, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);

	for (int contour = 0; contour < contours.size(); contour++)
	{
		Scalar colour(rand() & 0xFF, rand() & 0xFF, rand() & 0xFF);
		drawContours(contoured_img, contours, contour, colour, FILLED, 8, hierarchy);

	}
}

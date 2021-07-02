#pragma once
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#include "../inc/edge_detection.h"

using namespace std;
using namespace cv;


// Laplacian edge detection
void laplacian_edge_detection(Mat& gray_img, Mat& edge_detected_img, int kernel_size, int ddepth) {
	Mat blurred_img;
	GaussianBlur(gray_img, blurred_img, cv::Size(3, 3), 3);

	Laplacian(blurred_img, edge_detected_img, ddepth, kernel_size);

	// converting back to
	convertScaleAbs(edge_detected_img, edge_detected_img);
}

// Canny edge detection
void canny_edge_detection(Mat& gray_img, Mat& edge_detected_img, int lower_threshold, int higher_threshold) {
	Mat blurred_img;
	GaussianBlur(gray_img, blurred_img, cv::Size(3, 3), 3);

	Canny(blurred_img, edge_detected_img, lower_threshold, higher_threshold);

}
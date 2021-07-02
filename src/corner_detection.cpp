#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#include "../inc/corner_detection.h"

using namespace std;
using namespace cv;

void harris_corner_detector(Mat& gray, Mat& corner_output_norm, const int neighborhood_size, const int aperture_parameter, const float free_harris_parameter) {

	Mat output, output_norm_scaled;

	// Detecting corners using the cornerHarris built in function
	output = Mat::zeros(gray.size(), CV_32FC1);
	cornerHarris(gray, output,
		neighborhood_size,              // Neighborhood size
		aperture_parameter,              // Aperture parameter for the Sobel operator
		free_harris_parameter);          // Harris detector free parameter

	// Normalizing - Convert corner values to integer so they can be drawn
	normalize(output, corner_output_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
	convertScaleAbs(corner_output_norm, output_norm_scaled);

}

void draw_harris_corners(Mat& corner_detected_image, const Mat& corner_output_norm, float radius_size, const Scalar& color, const int thickness, const int line_type) {
	// Drawing a circle around corners
	for (int j = 0; j < corner_output_norm.rows; j++) {
		for (int i = 0; i < corner_output_norm.cols; i++) {
			if ((int)corner_output_norm.at<float>(j, i) > 100) {
				circle(corner_detected_image, Point(i, j), radius_size, color, thickness, line_type, 0);
			}
		}
	}
}


void shiTomasi_corner_detector(Mat& gray, vector<Point2f>& corners, const int number_of_corners, const float minimal_quality_of_corners, const int minimum_euclidean_distance, const int size_of_average_block, const float free_harris_parameter) {

	Mat output, output_norm, output_norm_scaled;

	// Detecting corners using the goodFeaturesToTrack built in function
	goodFeaturesToTrack(gray,
		corners,
		number_of_corners,            // Max corners to detect
		minimal_quality_of_corners,           // Minimal quality of corners
		minimum_euclidean_distance,             // Minimum Euclidean distance between the returned corners
		Mat(),          // Optional region of interest
		size_of_average_block,              // Size of an average block for computing a derivative covariation matrix over each pixel neighbothood
		false,          // Use Harri Detector or cornerMinEigenVal - Like when you create your own
		free_harris_parameter);          // Free parameter for the Harris detector
}

void draw_shiTomasi_corners(Mat& corner_detected_image, const vector<Point2f>& corners, float radius_size, const Scalar& color, const int thickness, const int line_type) {
	// Drawing a circle around corners
	for (size_t i = 0; i < corners.size(); i++) {
		circle(corner_detected_image, corners[i], radius_size, color, thickness, line_type, 0);
	}
}
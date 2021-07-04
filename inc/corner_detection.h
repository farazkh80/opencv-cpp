#pragma once
#ifndef CORNER_DETECTION_H

using namespace std;
using namespace cv;

void harris_corner_detector(Mat& gray, Mat& corner_output_norm, const int neighborhood_size = 3, const int aperture_parameter = 3, const float free_harris_parameter = 0.04);

void draw_harris_corners(Mat& corner_detected_image, const Mat& corner_output_norm, const float radius_size = 4, const Scalar& color = Scalar(0, 0, 255), const int thickness = 2, const int line_type = 8);

void shiTomasi_corner_detector(Mat& gray, vector<Point2f>& corners, const int number_of_corners = 100, const float minimal_quality_of_corners = 0.01, const int minimum_euclidean_distance = 10,
	const int size_of_average_block = 3, const float free_harris_parameter = 0.04);

void draw_shiTomasi_corners(Mat& corner_detected_image, const vector<Point2f>& corners, const float radius_size = 4, const Scalar& color = Scalar(0, 0, 255), const int thickness = 2, const int line_type = 8);

#endif
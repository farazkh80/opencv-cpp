#pragma once
#ifndef EDGE_DETECTION_H

#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

void laplacian_edge_detection(Mat& gray_img, Mat& edge_detected_img, int kernel_size, int ddepth);

void canny_edge_detection(Mat& gray_img, Mat& edge_detected_img, int lower_threshold, int higher_threshold);

#endif

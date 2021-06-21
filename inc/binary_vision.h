#pragma once
#ifndef BINARY_VISION_H

#include <opencv2/core.hpp>

#include "scaling.h"

using namespace std;
using namespace cv;

/* Binary Vision helper functions */

// Thresholding functions
void binary_regular_threshold_image(const Mat& org_img, Mat& binary_img, int threshold_value);

void binary_otsu_threshold_image(const Mat& org_img, Mat& binary_img, int threshold_value);

void binary_band_threshold_image(const Mat& org_img, Mat& binary_img, int low_threshold_value, int high_threshold_value);

void binary_adaptive_threshold_image(const Mat& org_img, Mat& binary_img, int block_size, double offset);

// Mathematical Morphology functions
void binary_dilate_default(const Mat& org_binary_img, Mat& dilated_img);

void binary_dilate_custom(const Mat& org_binary_img, Mat& dilated_img, int structuring_elem_h, int structuring_elem_w);

void binary_erode_default(const Mat& org_binary_img, Mat& eroded_img);

void binary_erode_custom(const Mat& org_binary_img, Mat& eroded_img, int structuring_elem_h, int structuring_elem_w);

void binary_open_custom(const Mat& org_binary_img, Mat& opened_img, int structuring_elem_h, int structuring_elem_w);

void binary_close_custom(const Mat& org_binary_img, Mat& closed_img, int structuring_elem_h, int structuring_elem_w);

// Draws contours on a copy of passed image with random colours
void extract_contours(const Mat& org_img, Mat& contoured_img, int threshold_value);

#endif

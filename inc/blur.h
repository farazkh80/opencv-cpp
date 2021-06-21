#pragma once
#ifndef BLUR_H

#include <opencv2/core.hpp>

using namespace std;
using namespace cv;


/* Bluring functions */
// Returns a Gaussian Blured version of the image passed
void gaussian_blur_image(const Mat& org_img, Mat& gaussian_blured_img);

// Returns a Median Blured version of the image passed
void median_blur_image(const Mat& org_img, Mat& median_blured_img);

#endif


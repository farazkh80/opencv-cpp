#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include "../inc/blur.h"

using namespace std;
using namespace cv;


/* Bluring functions */
// Returns a Gaussian Blured version of the image passed
void gaussian_blur_image(const Mat& org_img, Mat& gaussian_blured_img) {
	GaussianBlur(org_img, gaussian_blured_img, Size(1, 1), 9, 9);
}

// Returns a Median Blured version of the image passed
void median_blur_image(const Mat& org_img, Mat& median_blured_img) {
	medianBlur(org_img, median_blured_img, 9);
}
#pragma once
#ifndef SCALING_H

using namespace std;
using namespace cv;

/* Color Scaling functions */
// Creates a Gray Scaled Version of the image passed
void gray_scale_image(const Mat& org_img, Mat& gray_scaled_img);

// Creates a Gray Scaled Version of the image passed
void manual_gray_scale_image(const Mat& org_img, Mat& gray_scaled_img);

// Creates a HSV Scaled Version of the image passed
void BGR_2_HSV(const Mat& org_img, Mat& hsv_img);

/* Color detection functions */
// Returns a Color Detected version of the image passed in color range [lower_bound, upper_bound]
void detect_color(const Mat& hsv_img, Mat& color_detected_img, vector<int>& lower_bound, vector<int>& upper_bound);
#endif

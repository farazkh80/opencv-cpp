#pragma once
#ifndef HISTOGRAM_H
#define HISTOGRAM_H

using namespace std;
using namespace cv;


/* Histogram helper functions */
// Draw the passed gray scale histogram
Mat draw_gray_scale_histogram(const MatND& histogram, int hist_size = 256, int hist_w = 512, int hist_h = 400);

// Draw the passed bgr histograms
Mat draw_bgr_histogram(const Mat& b_hist, const Mat& g_hist, const Mat& r_hist, int hist_size, int hist_w = 512, int hist_h = 400);

// Smooth Histogram
void smooth_1D_histogram();

// Compute 1D gray scale histogram for a gray scaled passed image
void compute_1D_gray_scaled_histogram(const Mat& org_gray_scaled_img, MatND& histogram, int hist_size = 256, int hist_w = 512, int hist_h = 400);

// Compute 1D BGR histogram for a gray scaled passed image
void compute_1D_bgr_histogram(const Mat& org_img, Mat& b_hist, Mat& g_hist, Mat& r_hist, int hist_size = 256, int hist_w = 512, int hist_h = 400);

// Compare two histograms based on the passed metric
double compare_histograms(const MatND& histogram_1, const MatND& histogram_2, HistCompMethods comaprassion_metric = HISTCMP_CORREL);

#endif


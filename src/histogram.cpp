#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#include "../inc/histogram.h"

using namespace std;
using namespace cv;

/* Histogram helper functions */
// Draw the passed gray scale histogram
Mat draw_gray_scale_histogram(const MatND& histogram, int hist_size, int hist_w, int hist_h) {
	Mat hist_img(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
	int bin_w = cvRound((double)hist_w / hist_size);

	for (int i = 1; i < hist_size; i++)
	{
		line(hist_img, Point(bin_w * (i - 1), hist_h - cvRound(histogram.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(histogram.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
	}

	return hist_img;
}

// Draw the passed bgr histograms
Mat draw_bgr_histogram(const Mat& b_hist, const Mat& g_hist, const Mat& r_hist, int hist_size, int hist_w, int hist_h) {
	Mat hist_img(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
	int bin_w = cvRound((double)hist_w / hist_size);

	for (int i = 1; i < hist_size; i++)
	{
		line(hist_img, Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
		line(hist_img, Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))),
			Scalar(0, 255, 0), 2, 8, 0);
		line(hist_img, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))),
			Scalar(0, 0, 255), 2, 8, 0);
	}

	return hist_img;
}

// Smooth Histogram
void smooth_1D_histogram() {

}

// Compute 1D gray scale histogram for a gray scaled passed image
void compute_1D_gray_scaled_histogram(const Mat& org_gray_scaled_img, MatND& histogram, int hist_size, int hist_w, int hist_h) {
	float channel_range[] = { 0.0, (float)hist_size };
	const float* channel_ranges = channel_range;
	int number_bins = hist_size;

	calcHist(&org_gray_scaled_img, 1, 0, Mat(), histogram, 1, &number_bins, &channel_ranges);

	normalize(histogram, histogram, 0, hist_h, NORM_MINMAX, -1, Mat());
}

// Compute 1D BGR histogram for a gray scaled passed image
void compute_1D_bgr_histogram(const Mat& org_img, Mat& b_hist, Mat& g_hist, Mat& r_hist, int hist_size, int hist_w, int hist_h) {
	vector<Mat> bgr_planes;
	split(org_img, bgr_planes);

	float channel_range[] = { 0.0, (float)hist_size };
	const float* channel_ranges = { channel_range };
	bool uniform = true, accumulate = false;

	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &hist_size, &channel_ranges, &uniform, &accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &hist_size, &channel_ranges, &uniform, &accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &hist_size, &channel_ranges, &uniform, &accumulate);

	normalize(b_hist, b_hist, 0, hist_h, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, hist_h, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, hist_h, NORM_MINMAX, -1, Mat());
}

// Compare two histograms based on the passed metric
double compare_histograms(const MatND& histogram_1, const MatND& histogram_2, HistCompMethods comaprassion_metric) {
	return compareHist(histogram_1, histogram_2, comaprassion_metric);
}

// Equalize passed picture using its histogram
void equalize_gray_scaled_histogram(const Mat& org_img, Mat& equalized_img) {
	equalizeHist(org_img, equalized_img);
}


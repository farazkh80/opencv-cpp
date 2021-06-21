#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include "colorBounds.h"
#include "scaling.h"
#include "blur.h"
#include "histogram.h"
#include "binary_vision.h"

using namespace std;
using namespace cv;

int main()
{
	// Get the image path
	string image_path = "C:/C++-Projs/opencvtest/images/binary-vision/bv-3.jpg";

	// read the image
	Mat image1 = imread(image_path, IMREAD_COLOR);

	// resize the image
	resize(image1, image1, Size(500, 500));


	Mat image2, image3;
	gray_scale_image(image1, image2);
	binary_band_threshold_image(image2, image3, 150, 200);

	imshow("original img 1 ", image1);
	imshow("original img 3 ", image3);

	int k = waitKey(0);

	return 0;
}
#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include "../inc/colorBounds.h"
#include "../inc/scaling.h"
#include "../inc/blur.h"
#include "../inc/histogram.h"
#include "../inc/binary_vision.h"
#include "../inc/transformation.h"

using namespace std;
using namespace cv;



int main()
{
	// Get the image path
	string image_path = "C:/C++-Projs/opencvtest/images/transformation/tran-2.jpg";

	// read the image
	Mat image1 = imread(image_path, IMREAD_COLOR);

	// resize the image
	resize(image1, image1, Size(500, 500));

	if (image1.empty())
	{
		cout << "Error loading the image" << endl;
		return -1;
	}

	Mat perspecImg, affineImg;

	//// Affline trnasformation

	prespective_transform(image1, perspecImg);

	return 0;
}
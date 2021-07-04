#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/videoio.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include "../inc/color_bounds.h"
#include "../inc/scaling.h"
#include "../inc/blur.h"
#include "../inc/histogram.h"
#include "../inc/binary_vision.h"
#include "../inc/transformation.h"
#include "../inc/edge_detection.h"
#include "../inc/corner_detection.h"
#include "../inc/face_detection.h"


using namespace std;
using namespace cv;


int main()
{
	// Get the image path
	string image_path_1 = "C:/C++-Projs/opencvtest/images/face-detection/face-detect-2.jpg";

	// read the image
	Mat img_faces = imread(image_path_1, IMREAD_COLOR);
	Mat face_detected_img;

	img_faces.copyTo(face_detected_img);

	face_detection(img_faces, face_detected_img);


	imshow("Original face Image", img_faces);
	imshow("detected face Image", face_detected_img);
	waitKey(0);

	return 0;
}
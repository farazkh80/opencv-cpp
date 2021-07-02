#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
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


using namespace std;
using namespace cv;





int main()
{
	// Get the image path
	string image_path_1 = "C:/C++-Projs/opencvtest/images/corner-detection/corner-detect-1.jpeg";

	// read the image
	Mat image1 = imread(image_path_1, IMREAD_COLOR);

	//resize the image
	resize(image1, image1, Size(500, 300));

	//// Get the image path
	//string image_path_1 = "C:/C++-Projs/opencvtest/images/transformation/hough-tran-1.jpg";
	//string image_path_2 = "C:/C++-Projs/opencvtest/images/transformation/hough-tran-2.jpg";

	//// read the image
	//Mat imageLines = imread(image_path_1, IMREAD_COLOR);
	//Mat imageCircles = imread(image_path_2, IMREAD_COLOR);

	//Mat detectImgLines, detectImgLinesP, detectImgCircles;
	//imageLines.copyTo(detectImgLines);
	//imageLines.copyTo(detectImgLinesP);
	//imageCircles.copyTo(detectImgCircles);


	//// resize the image
	////resize(image1, image1, Size(500, 500));

	//if (imageLines.empty() || imageCircles.empty())
	//{
	//	cout << "Error loading the image" << endl;
	//	return -1;
	//}

	//// Hough transform lines
	////Edge detection
	//Canny(imageLines, detectImgLines, 200, 255);

	//// Hough transform
	//vector<Vec2f> lines;
	//HoughLines(detectImgLines, lines, 1, CV_PI, 150);

	//for (size_t i = 0; i < lines.size(); i++)
	//{
	//	float rho = lines[i][0], theta = lines[i][1];
	//	Point pt1, pt2;
	//	double a = cos(theta), b = sin(theta);
	//	double x0 = a * rho, y0 = b * rho;
	//	pt1.x = cvRound(x0 + 1000 * (-b));
	//	pt1.y = cvRound(y0 + 1000 * (a));
	//	pt2.x = cvRound(x0 - 1000 * (-b));
	//	pt2.y = cvRound(y0 - 1000 * (a));
	//	line(detectImgLines, pt1, pt2, Scalar(0, 0, 255), 3, LINE_AA);
	//}

	//// Display
	//imshow("Original Line Image", imageLines);
	//imshow("Line Detection", detectImgLines);
	//waitKey(0);








	//// Hough transform lines probabilistic
	//// Edge detection
	//Canny(imageLines, detectImgLinesP, 200, 255);

	//// Hough transform probabilistic
	//vector<Vec4i> linesP;
	//HoughLinesP(detectImgLinesP, linesP, 1, CV_PI / 180, 50, 50, 10);

	//// Draw the lines
	//for (size_t i = 0; i < linesP.size(); i++)
	//{
	//	Vec4i l = linesP[i];
	//	line(detectImgLinesP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, LINE_AA);
	//}

	//imshow("Original Line Image", imageLines);
	//imshow("Line Detection P", detectImgLinesP);
	//waitKey(0);









	// Circle Detection Hough Transform

	//Mat gray;
	//cvtColor(imageCircles, gray, COLOR_RGB2GRAY);

	//medianBlur(gray, gray, 5);

	//vector<Vec3f> circles;
	//HoughCircles(gray, circles, HOUGH_GRADIENT, 1,
	//	gray.rows / 80,  // change this value to detect circles with different distances to each other
	//	100, 20, 1, 18 // change the last two parameters
 //  // (min_radius & max_radius) to detect larger circles
	//);

	//for (size_t i = 0; i < circles.size(); i++)
	//{
	//	Vec3i c = circles[i];
	//	Point center = Point(c[0], c[1]);
	//	// circle center
	//	circle(detectImgCircles, center, 1, Scalar(0, 100, 100), 3, LINE_AA);
	//	// circle outline
	//	int radius = c[2];

	//	circle(detectImgCircles, center, radius, Scalar(255, 0, 255), 3, LINE_AA);
	//}

	//imshow("Original Circle Image", imageCircles);
	//imshow("Circle Detection", detectImgCircles);
	//waitKey(0);










	return 0;
}
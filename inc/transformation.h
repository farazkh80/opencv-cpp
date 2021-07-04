#pragma once
#ifndef TRANSFORMATION_H

using namespace std;
using namespace cv;


//// Affine Transforamtion of number plate
//// Transform the image between source points to destination points
//// Number of points needed: 3
////vector<Point2f> sourcePlate, destinationPlate;
////sourcePlate = { Point2f(400,250), Point2f(400,320), Point2f(200,330) };
////destinationPlate = { Point2f(770,350), Point2f(770,450), Point2f(250,370) };
void affline_transform(Mat& org_image, Mat& transformed_image);

//// Perspective Transformation of snooker table
//// Transform the image between source points to destination points
// //// Number of points needed: 4
////vector<Point2f> sourceSnooker, destinationSnooker;
////sourceSnooker = { Point2f(338,645), Point2f(671,650), Point2f(922,916), Point2f(101,919) };
////destinationSnooker = { Point2f(278,223), Point2f(785,220), Point2f(830,905), Point2f(205,907) };
void prespective_transform(Mat& org_image, Mat& transformed_image);

//// Hough transform lines
/// Find potential straight lines
/// params:
///	org_img => colored original img
/// line_detected_img => a COPY of org_img that the lines will be drawn on
void hough_transform_lines(Mat& org_img, Mat& line_detected_img);

//// Hough transform lines probabilistic
/// Find the potential straight lines with a relative probability
/// params:
///	org_img => colored original img
/// line_detected_img => a COPY of org_img that the lines will be drawn on
void hough_transform_lines_prob(Mat& org_img, Mat& line_detected_img);

//// Hough transform circles
/// Find potential circles
/// params:
///	org_img => colored original img
/// line_detected_img => a COPY of org_img that the lines will be drawn on
void hough_transform_circles(Mat& org_img, Mat& circle_detected_img);

#endif
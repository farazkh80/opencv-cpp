#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>

#include "../inc/face_detection.h"

using namespace std;
using namespace cv;

// Default Face detection
void face_detection(Mat& org_frame, Mat& face_detected_frame)
{
	Mat frame_gray;
	CascadeClassifier face_cascade;

	//string faceClassifier = "C:/Users/kemik/OneDrive/Skrivebord/haarcascade_frontalface_default.xml";
	string faceClassifier = "C:/C++-Projs/opencvtest/src/haarcascade_frontalface_alt2.xml";

	if (!face_cascade.load(faceClassifier))
	{
		cout << "Could not load the classifier";
		exit(1);
	};

	cvtColor(org_frame, frame_gray, COLOR_BGR2GRAY);

	// Detect faces
	std::vector<Rect> faces;
	face_cascade.detectMultiScale(frame_gray, faces);

	for (size_t i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
		ellipse(face_detected_frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(0, 0, 255), 6);
		Mat faceROI = frame_gray(faces[i]);
	}
}

// Custom Face detection
void face_detection_custom(Mat& processed_gray_img, Mat& face_detected_frame)
{
	CascadeClassifier face_cascade;

	//string faceClassifier = "C:/Users/kemik/OneDrive/Skrivebord/haarcascade_frontalface_default.xml";
	string faceClassifier = "C:/C++-Projs/opencvtest/src/haarcascade_frontalface_alt2.xml";

	if (!face_cascade.load(faceClassifier))
	{
		cout << "Could not load the classifier";
		exit(1);
	};

	// Detect faces
	std::vector<Rect> faces;
	face_cascade.detectMultiScale(processed_gray_img, faces);

	for (size_t i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
		ellipse(face_detected_frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(0, 0, 255), 6);
		Mat faceROI = processed_gray_img(faces[i]);
	}
}
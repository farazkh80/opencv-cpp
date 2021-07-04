#pragma once
#ifndef FACE_DETECTION_H

using namespace std;
using namespace cv;

// Detection of faces in an image or captured frame
// params:
// org_frame: the original image or captured frame
// face_detected_frame: COPY of org_img with detected faces
void face_detection(Mat& org_frame, Mat& face_detected_frame);

// Custom Face detection
// params:
// org_frame: pre-processed gray version of org image or captured frame
// face_detected_frame: COPY of org_img with detected faces
void face_detection_custom(Mat& processed_gray_img, Mat& face_detected_frame);

#endif
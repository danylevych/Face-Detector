#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <string>
#include <vector>


#include "FaceBorders.h"


class FaceDetector
{
private:
	int scaleF = 2;
	int neighbors = 10;
	cv::Mat image;
	cv::VideoCapture camera;
	cv::CascadeClassifier model;
	std::vector<cv::Rect> faces;
	FaceBorders border;

public:
	FaceDetector(int cameraId, const std::string& modelData);

public:
	void Run();
	bool IsEquipmentOk();

private:
	void CheckEquipment();
	void HandleCameraIssue();
	void HandleModelIssue();

private:
	cv::Mat ProcessImage();
	void DetectFaces(cv::Mat& processedImg);
	void DrawDetectedFaces();
	void Display();

	bool WantClose();

	void RelizeAllEquipment();

};

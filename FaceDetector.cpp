#include "FaceDetector.h"


FaceDetector::FaceDetector(int cameraId, const std::string &modelData)
	: camera(cameraId)
	, model()
	, border(cv::Scalar(0, 255, 0), "Face", cv::Scalar(0, 255, 0), cv::HersheyFonts::FONT_HERSHEY_COMPLEX_SMALL)
{
	model.load(modelData);

	border.SetBoundThickness(3);
	border.SetFontThickness(1);
}


void FaceDetector::Run()
{
	CheckEquipment();

	do {
		cv::Mat processedImg = ProcessImage();
		DetectFaces(processedImg);
		DrawDetectedFaces();
		Display();
	} while (!WantClose());

	RelizeAllEquipment();
}


bool FaceDetector::IsEquipmentOk()
{
	return camera.isOpened() && !model.empty();
}


void FaceDetector::CheckEquipment()
{
	if (IsEquipmentOk()) {
		return;
	}

	HandleCameraIssue();
	HandleModelIssue();
}


void FaceDetector::HandleCameraIssue()
{
	if (!camera.isOpened()){
		throw std::runtime_error("The camera has not been opend.");
	}
}


void FaceDetector::HandleModelIssue()
{
	if (model.empty()) {
		throw std::runtime_error("The model is empty, check your data file.");
	}
}

cv::Mat FaceDetector::ProcessImage()
{
	cv::Mat grayImg;

	if (camera.read(image)) {
		cv::cvtColor(image, grayImg, cv::COLOR_BGR2GRAY);
		cv::equalizeHist(grayImg, grayImg);
	}

	return grayImg;
}


void FaceDetector::DetectFaces(cv::Mat& processedImg)
{
	if (processedImg.empty()) {
		return;
	}

	model.detectMultiScale(processedImg, faces, 1.03, 8, 0, cv::Size(80, 80));
}


void FaceDetector::DrawDetectedFaces()
{
	for (int i = 0; i < faces.size(); i++) {
		border.SetText("Face #" + std::to_string(i + 1));
		border.Draw(faces[i], image);
	}
}


void FaceDetector::Display()
{
	cv::imshow("Face Detector", image);
}


bool FaceDetector::WantClose()
{
	return cv::waitKey(1) == 27;
}


void FaceDetector::RelizeAllEquipment()
{
	cv::destroyAllWindows();
	camera.release();
}

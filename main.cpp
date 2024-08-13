#include "FaceDetector.h"


int main()
{
	FaceDetector detector(0, "Resources/haarcascade_frontalface_default.xml");
	detector.Run();
}

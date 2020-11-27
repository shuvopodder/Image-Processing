#include <iostream>
#include "opencv2/opencv.hpp"


int main()
{
	cv::VideoCapture cam(0);  //open webcam
	if (!cam.isOpened()) {
		throw std::runtime_error("Failed to open camera");
	}

	while (true)
	{
		cv::Mat frames;
		cam >> frames;
		cv::imshow("Video", frames);
		if (cv::waitKey(30) >= 0) break;
	}

	return 0;
}
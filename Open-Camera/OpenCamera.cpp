#include <opencv2/core/core.hpp>
#include <iostream>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat frame;

	VideoCapture cap;

	int deviceID = 1;			// 0 = default camera ID
	int apiID = cv::CAP_ANY;	// 0 = autodetect default API

	// open camera
	cap.open(deviceID, apiID);

	// check if openning camera is successful
	if (false == cap.isOpened())
	{
		cout << "Unable to open video capture" << endl;
		cin.get();

		return -1;
	}

	cout << "Start grabbing..." << endl;

	// continuously read frames from camera and display
	while (1)
	{
		cap.read(frame);

		if (frame.empty())
		{
			cerr << "ERROR: blank frame grabbed" << endl;
			break;
		}

		imshow("Live", frame);

		if (waitKey(5) >= 0)
		{
			break;
		}
	}

	return 0;
}
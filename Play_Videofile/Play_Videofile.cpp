#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	string videofile = "Kyoto.mp4";

	VideoCapture cap(videofile);

	if (false == cap.isOpened())
	{
		cout << "Cannot open videofile" << endl;
		return -1;
	}

	// get frame rate of video
	double fps = cap.get(CAP_PROP_FPS);
	cout << "FPS: " << fps << endl;

	// create window
	string windowName = "Video";
	namedWindow(windowName, WINDOW_NORMAL);

	
	while (true)
	{
		Mat frame;

		bool readSuccess = cap.read(frame);

		if (false == readSuccess)
		{
			cout << "End of video" << endl;
			break;
		}

		imshow(windowName, frame);
		
		// wait for for 10 ms until any key is pressed.  
		// If the 'Esc' key is pressed, break the while loop.
		// If the any other key is pressed, continue the loop 
		// If any key is not pressed withing 10 ms, continue the loop
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed. Video stopped..." << endl;
			break;
		}
	}
	
	return 0;
}
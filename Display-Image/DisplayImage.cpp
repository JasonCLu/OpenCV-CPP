#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <string>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	//string imagePath = samples::findFile("starry_night.jpg");
	string imagePath = "mountains.jpg";

	// read image
	Mat img = imread(imagePath, IMREAD_COLOR);	// IMREAD_COLOR, IMREAD_GRAYSCALE, ..

	// resize image
	float scale = 0.30;

	Size s = img.size();
	int resizedWidth = s.width * scale;
	int resizedHeight = s.height * scale;

	cout << "(" << s.width << "," << s.height << ")" << "-->" << "(" << resizedWidth << "," << resizedHeight << ")" << endl;

	Mat resizedImage;

	resize(img, resizedImage, Size(resizedWidth, resizedHeight));


	if (img.empty())
	{
		cout << "Could not read image: " << imagePath << endl;
		return -1;
	}
	else
	{
		imshow("Image", resizedImage);

		waitKey(0);
	}

	return 0;
}
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	if (argc < 3)
	{
		cout << "Incorrect number of arguments" << endl;
		cout << "Usage guide:\n\t resize.exe <path to file> <scaling factor> <output path>\nExample: \n\t resize.exe \"C:\\image.jpg\" 1.3 \"C:\\out\\resized_image.jpg\"\n\n";
		exit(EXIT_FAILURE);
	}
	String imagePath = argv[1];
	Mat image = imread(imagePath);
	float scaling_factor = atof(argv[2]);
	String targetPath = argv[3];

	if (image.empty()) // Check for failure
	{
		cout << "Could not open or find the image" << endl;
		system("pause"); //wait for any key press
		return -1;
	}

	String windowName = "Original image"; //Name of the window

	namedWindow(windowName); // Create a window
	imshow(windowName, image); // Show our image inside the created window.
	waitKey(0); // Wait for any keystroke in the window
	destroyWindow(windowName); //destroy the created window

	cv::resize(image, image, cv::Size(round(image.cols * scaling_factor), round(image.rows * scaling_factor)), 0, 0, INTER_LINEAR);
	bool isSuccess = imwrite(targetPath, image);

	if (isSuccess == false)
	{
		cout << "Failed to save the image" << endl;
		cin.get();
		return -1;
	}

	cout << "Resized image successfully saved to a file" << endl;
	
	windowName = "Resized Image";
	namedWindow(windowName);
	imshow(windowName, image);
	waitKey(0);
	destroyWindow(windowName);

	return 0;
}
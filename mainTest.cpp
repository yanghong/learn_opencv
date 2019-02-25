#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char ** argv) {
	Mat img;
	string imgpath = argv[1];
	img = imread(imgpath, 1);
	imshow("img", img);
	waitKey(0);
	return 0;
}

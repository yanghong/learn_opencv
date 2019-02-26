#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char ** argv) {
	Mat srcImage = imread(argv[1]);

	if (srcImage.data){
		cout << "loading image success!" << endl;
	} else {
		cout << "loading image failed!" << endl;
		return -1;
	}

	namedWindow("srcImage",WINDOW_AUTOSIZE);
	imshow("srcImage", srcImage);
	
	Mat kern = (Mat_<char>(3,3)<<0,-1,0,-1,5,-1,0,-1,0);
	Mat dstImage;
	filter2D(srcImage, dstImage,srcImage.depth(),kern);
	namedWindow("dstImage",WINDOW_AUTOSIZE);
	imshow("dstImage",dstImage);
	waitKey(0);
	return 0;
}

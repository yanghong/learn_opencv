#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


void salt(Mat &image,int n){
	for (int k=0;k<n;k++) {
		int i = rand()%image.cols;
		int j = rand()%image.rows;
		if (image.channels() == 1){
			image.at<uchar>(j,i) = 255;
		} else if(image.channels() == 3) {
			image.at<cv::Vec3b>(j,i)[0] = 255;
			image.at<cv::Vec3b>(j,i)[1] = 255;
			image.at<cv::Vec3b>(j,i)[2] = 255;
		}
	}
}

int main(int argc, char ** argv) {
	Mat image = imread(argv[1]);
	salt(image,image.size().height);
	namedWindow("Image");
	imshow("Image",image);
	waitKey(0);
	return 0;
}

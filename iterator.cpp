#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int getDistance(const cv::Vec3b& color,const cv::Vec3b& target){
	return abs(color[0]-target[0])+
		abs(color[1]-target[1])+
		abs(color[2]-target[2]));
}

int main(int argc, char ** argv) {
	Mat image = imread(argv[1]);
	Mat result;
	int minDist = 50;
	Vec3b target = [120,120,120];
	// get iterator
	cv::Mat_<cv::Vec3b>::const_iterator it = image.begin<cv::Vec3b>();
	cv::Mat_<cv::Vec3b>::const_iterator itend = image.end<cv::Vec3b>();
	cv::Mat_<cv::Vec3b>::const_iterator itout = result.begin<cv::Vec3b>();

	// for every pixel
	for(;it != itend;++it,++itout) {
		// deal every pixel
		if(getDistance(*it,target)<minDist) {
			*itout = 255;
		} else {
			*itout = 0;
		}
	}


	namedWindow("result");
	imshow("result",result);
	waitKey(0);
	return 0;
}

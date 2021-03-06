#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void sharpen(const cv::Mat &image, cv::Mat &result) {
	result.create(image.size(),image.type());
	for(int j = 1;j<image.rows - 1;j++) {
		const uchar* previous = image.ptr<const uchar>(j-1);
		const uchar* current = image.ptr<const uchar>(j);
		const uchar* next = image.ptr<const uchar>(j+1);
		uchar* output = result.ptr<uchar>(j);
		for(int i=1;i<image.cols-1;i++) {
			*output++ = cv::saturate_cast<char>(
					5*current[i]-current[i-1]
					-current[i+1]-previous[i]-next[i]);
		}
	}
	result.row(0).setTo(cv::Scalar(0));
	result.row(result.rows-1).setTo(cv::Scalar(0));
	result.col(0).setTo(cv::Scalar(0));
	result.col(result.cols-1).setTo(cv::Scalar(0));
}

int main(int argc, char ** argv) {
	Mat image = imread(argv[1]);
	Mat result;
	sharpen(image,result);
	namedWindow("result");
	imshow("result",result);
	waitKey(0);
	return 0;
}

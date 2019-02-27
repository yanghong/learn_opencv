#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void colorReduce(cv::Mat &image, int div=64) {
	int nl = image.rows; 
    int nc = image.cols*image.channels();			    
	for(int j=0;j<nl;j++) {
		uchar* data = image.ptr<uchar>(j);
		for (int i=0;i<nc;i++) {
		data[i] = data[i]/div*div+div/2;
		}
	}
}

int main(int argc, char ** argv) {
	Mat image = imread(argv[1]);
	colorReduce(image);
	namedWindow("Image");
	imshow("Image",image);
	waitKey(0);
	return 0;
}

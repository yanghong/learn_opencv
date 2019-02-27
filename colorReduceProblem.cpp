#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// this code has Segmetation fault error.
// maybe in break one code has nullpoint.

void colorReduce(cv::Mat &image, int div=64) {
	int nl = image.rows; 
    int nc = image.cols*image.channels();			   
	if(image.isContinuous()){
		nc = nc* nl;
		nl = 1;
	}
	int n = static_cast<int>(
		log(static_cast<double>(div))/log(2.0));
	
	uchar mask = 0xFF<<n; // e.g.for div=16, mask=0xF0
	cout << "mask: " << mask << endl;

	//for all pixels
	for(int j=0;j<nl;j++) {
		cout << "j: " << j << endl;
		uchar *data = image.ptr<uchar>(j);
		for (int i=0;i<nc;i++) {
			cout <<"i: " << i << "*data: " << *data << endl;
			// break one
			*data++ = *data&mask + div/2;
			*data++ = *data&mask + div/2;
			*data++ = *data&mask + div/2;
		}
	}
	cout << "Done " << endl;
}

int main(int argc, char ** argv) {
	Mat image = imread(argv[1]);
	colorReduce(image);
	namedWindow("Image");
	imshow("Image",image);
	waitKey(0);
	return 0;
}

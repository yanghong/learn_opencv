#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char ** argv) {
	Mat M1(3,2,CV_8UC3,Scalar(0,0,255));
	cout << "M1=" <<endl << " " << M1 << endl;

	Mat M2(Size(2,3), CV_8UC3,Scalar(1,2,3));
	cout << "M2=" << endl << " " << M2 << endl;

	Mat M3(M2);
	cout << "M3=" << endl << " " << endl;

	Mat M4(M2,Range(1,2), Range(1,2));
	cout << "M4=" << endl << " " << M4 << endl;
	
	waitKey(0);
	return 0;
}

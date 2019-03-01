#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class Histogram1D{
	private:
		int histSize[1]; // item num
		float hranges[2]; // pixel max or min
		const float*ranges[1];
		int channels[1]; // only use channel one
	public:
		Histogram1D() {
			// prepare argv
			histSize[0] = 256;
			hranges[0] = 0.0;
			hranges[1] = 255.0;
			ranges[0] = hranges;
			channels[0] = 0;
		}
		cv::MatND getHistogram(const cv::Mat &image) {
			cv::MatND hist;
			cv::calcHist(&image,
					1, // cal single photo hist
					channels, // channel num
					cv::Mat(), // mask
					hist, // return histogram
					1, // 1D
					histSize, // item num
					ranges // range of pixel
					);
		}

};


int main(int argc, char ** argv) {
	Mat image = imread(argv[1],0); // open it in white and black

	// histogram object
	Histogram1D h;
	cv::MatND result = h.getHistogram(image);
	namedWindow("result");
	imshow("result",result);
	waitKey(0);
	return 0;
}

#include <iostream>
#include <opencv2/opencv.hpp>
#include "NonNorm.h"

using namespace cv;
using namespace std;


MatInfo NONNORM(Mat &D,float rho,Mat T0,float gamma){
	    Mat U,S,V,outputT,outputPow;
	    MatInfo getMatInfo;
	    MatInfo returnMatInfo;
	    // SVD -> D
		 SVD::compute(D, S, U, V);
		 for (int i = 1; i< 101; i++) {
			getMatInfo = DCInner(S,rho,T0,gamma,U,V);
			subtract(getMatInfo.T,T0,outputT);
			pow(outputT,2,outputPow);
			float err = sum(outputPow);
			if(err < 1e-6){
			break;
			}
			T0 = getMatInfo.T;
		 }
		 Mat T = getMatInfo.T;
		 returnMatInfo.X = getMatInfo.X;
		 returnMatInfo.T = getMatInfo.T;
		 return returnMatInfo;
}
		 
MatInfo DCInner(Mat &S, float rho, Mat J , float epislon, Mat &U, Mat &V) {
	    MatInfo matInfo;
        float lambda = 0.5/rho;
		Mat zeroMat = Mat::zeros(J.rows,J.cols, CV_32FC1);
		Mat outputGrad;

	    Mat S0 = Mat::diag(S); 
		exp(-J/epislon,outputGrad);
		Mat grad = 	outputGrad/epislon;
	    Mat t = max(S0 - lambda*grad,zeroMat);
	    Mat X = U * Mat::diag(t) * V.t();
	    matInfo.X = X;
	    matInfo.T = t;
	    return matInfo;
}


float sum(Mat &mat)
{
	float s=0.0f;
	for(int row=0;row<mat.rows;row++) {
		uchar* data = mat.ptr<uchar>(row);
		for(int col=0;col<mat.cols;col++){
			s = s + data[col];
		}
	}
    return s;
}


int main(int argc, char ** argv) {

    Mat image = imread("2.jpg", 0);//以灰度图打开一张360X480的image.jpg
    Mat temp(image.size(), CV_32FC1, Scalar(0));
    image.convertTo(image, CV_32FC1);
    Mat U, W, V;
    SVD::compute(image, W, U, V);//opencv得到的V与MATLAB相比已经经过转置了，要想再转置一遍可以用V=V.t();
    image.convertTo(image, CV_8UC1);
    imshow("0", image);
    Mat w(360, 360, CV_32FC1, Scalar(0));//opencv进行SVD分解后得到的奇异值不是放入对角矩阵，而是一个列向量中，所以需要自己将其变换为对角矩
	W = Mat::diag(W);
	cout << W.rows << " " << W.cols << endl;

	cout << V.rows << " " << V.cols << endl;
    temp = U*W*V;
    temp.convertTo(temp, CV_8UC1);
    imshow("1", temp);
    waitKey(6000);

	return 0;
}

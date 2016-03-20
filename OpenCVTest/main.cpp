#include <iostream>

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/cudafilters.hpp"
#include "opencv2/cudaimgproc.hpp"
#include "opencv2/cudaarithm.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main(int argc, const char* argv[])
{
	
	cout << getBuildInformation() << endl;
	
	while (1)
	{
		if (waitKey(25) == 27)
			break;
	}
	
	return 0;
	
}
/*
cuda bilateral with histogram equalization

cuda::GpuMat d_src, d_dst_bi,d_dst_he,d_dst_bihe,d_tmp;
vector<cuda::GpuMat> d_vec;
Mat I = imread("baboon.jpg");
if (I.empty())
return -1;
d_src.upload(I);
cuda::bilateralFilter(d_src, d_dst_bi, -1, 50, 7);
cuda::cvtColor(d_dst_bi, d_tmp, CV_BGR2YCrCb);
cuda::split(d_tmp, d_vec);
cuda::equalizeHist(d_vec[0], d_vec[0]);
cuda::merge(d_vec, d_dst_bihe);
cuda::cvtColor(d_dst_bihe, d_dst_bihe, CV_YCrCb2BGR);

cuda::cvtColor(d_src, d_tmp, CV_BGR2YCrCb);
cuda::split(d_tmp, d_vec);
cuda::equalizeHist(d_vec[0], d_vec[0]);
cuda::merge(d_vec, d_dst_he);
cuda::cvtColor(d_dst_he, d_dst_he, CV_YCrCb2BGR);



Mat dst_bi(d_dst_bi);
Mat dst_he(d_dst_he);
Mat dst_bihe(d_dst_bihe);
namedWindow("bilateral", WINDOW_AUTOSIZE);
namedWindow("hist eq", WINDOW_AUTOSIZE);
namedWindow("hist eq after bilateral", WINDOW_AUTOSIZE);
namedWindow("source", WINDOW_AUTOSIZE);
imshow("bilateral", dst_bi);
imshow("hist eq", dst_he);
imshow("hist eq after bilateral", dst_bihe);

imshow("source", I);
if (cvWaitKey() == 27)
return 0;
*/
/// CUDA bilateral + histogram equalizatoin
//VideoCapture cap(0);
//// if not success, exit program
//if (!cap.isOpened())
//{
//	cout << "Cannot open the video file" << endl;
//	return -1;
//}
//const char* pzOriginalWindowName = "Original Video";
//const char* pzProccesedWindowName = "Proccessed Video";
//namedWindow(pzOriginalWindowName, CV_WINDOW_AUTOSIZE);
//namedWindow(pzProccesedWindowName, CV_WINDOW_AUTOSIZE);
//cuda::GpuMat d_src, d_dst_bi, d_dst_he, d_dst_bihe, d_tmp;
//vector<cuda::GpuMat> d_vec;
//Mat frame;
//while (1)
//{
//	// read a new frame from video
//	bool bSuccess = cap.read(frame);
//	//if not success, break loop
//	if (!bSuccess)
//	{
//		cout << "Cannot read the frame from video file" << endl;
//		break;
//	}
//	
//	imshow(pzOriginalWindowName, frame);
//	d_src.upload(frame);
//	cuda::bilateralFilter(d_src, d_dst_bi, -1, 15, 7);
//	cuda::cvtColor(d_dst_bi, d_tmp, CV_BGR2YCrCb);
//	cuda::split(d_tmp, d_vec);
//	cuda::equalizeHist(d_vec[0], d_vec[0]);
//	cuda::merge(d_vec, d_dst_bihe);
//	cuda::cvtColor(d_dst_bihe, d_dst_bihe, CV_YCrCb2BGR);
//	d_dst_bihe.download(frame);
//	//d_dst_bi.download(frame);
//	imshow(pzProccesedWindowName, frame);
//	//wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
//	if (waitKey(25) == 27)
//	{
//		cout << "esc key is pressed by user" << endl;
//		break;
//	}
//}
//return 0;
//
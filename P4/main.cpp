#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
int main() {
	Mat src, dst;
	src = imread("C:\\Users\\Administrator\\Desktop\\Í·Ïñ\\a.jpg");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image");
	imshow("input image", src);

	int cols = (src.cols-1) * src.channels();
	int offsetx = src.channels();
	int rows = src.rows;

	dst = Mat::zeros(src.size(), src.type());
	for (int row = 1; row < (rows - 1); row++) {
		const uchar* previous = src.ptr<uchar>(row - 1);
		const uchar* current = src.ptr<uchar>(row);
		const uchar* next = src.ptr<uchar>(row + 1);
		uchar* output = dst.ptr<uchar>(row);
		for (int col = offsetx; col < cols; col++) {
			output[col] = saturate_cast<uchar>(5 * current[col] - (current[col- offsetx] + current[col+ offsetx] + previous[col] + next[col]));
		}
	}
	namedWindow("contrast image demo");
	imshow("contrast image demo", dst);


	waitKey(0);
	return 0;
}
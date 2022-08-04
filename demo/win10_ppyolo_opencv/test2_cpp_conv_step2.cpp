#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include "mmdet/tensor.h"
#include "mmdet/convolution.h"

void pretty_print(cv::Mat& img, int max_h = 6, int max_w = 6) {
    double t0 = (double)cv::getTickCount();
    int H = img.rows;
    int W = img.cols;
    int C = img.channels();
    printf("H:%d\t", H);
    printf("W:%d\t", W);
    printf("C:%d\n", C);
    for (int y = 0; y < H; y++) {
        const uchar* ptr = img.ptr(y);
        for (int x = 0; x < W; x++) {
            int a = ptr[0];
            int b = ptr[1];
            int c = ptr[2];
            if ((x < max_w) && (y < max_h)) {
                printf("[%d, %d, %d] ", a, b, c);
            }
            if ((x == max_w) && (y < max_h)) {
                printf("...");
            }
            ptr += 3;
        }

        if (y < max_h) {
            printf("\n");
        }
        else if (y == max_h) {
            printf("...\n");
        }
    }
    printf("------------------------\n");
    double time = ((double)cv::getTickCount() - t0) / cv::getTickFrequency();
    printf("Time for pretty_print: %f\n", time);
}


void pretty_print4D(cv::Mat& img, int* shape, int max_h = 6, int max_w = 6) {
    int N = *shape;
    int C = *(shape + 1);
    int H = *(shape + 2);
    int W = *(shape + 3);
    printf("N: %d\t", N);
    printf("C: %d\t", C);
    printf("H: %d\t", H);
    printf("W: %d\n", W);
    int n, c, h, w, id;
    for (n = 0; n < N; n++) {
        for (c = 0; c < C; c++) {
            for (h = 0; h < H; h++) {
                for (w = 0; w < W; w++) {
                    id = img.step[0] * n + img.step[1] * c + img.step[2] * h + w * img.step[3];
                    //cout << id << endl;
                    float* p = (float*)(img.data + id);
                    printf("%f ", *p);
                }
            }
        }
    }
    printf("\n------------------------\n");
}

void print_shape(cv::Mat& img) {
    int H = img.rows;
    int W = img.cols;
    int C = img.channels();
    printf("H:%d\t", H);
    printf("W:%d\t", W);
    printf("C:%d\n", C);
}

/***************** Matתvector **********************/
template<typename _Tp>
vector<_Tp> convertMat2Vector(const cv::Mat& mat)
{
    return (vector<_Tp>)(mat.reshape(1, 1));//ͨ�������䣬����תΪһ��
}

/****************** vectorתMat *********************/
template<typename _Tp>
cv::Mat convertVector2Mat(vector<_Tp> v, int channels, int rows)
{
    cv::Mat mat = cv::Mat(v);//��vector��ɵ��е�mat
    cv::Mat dest = mat.reshape(channels, rows).clone();//PS������clone()һ�ݣ����򷵻س���
    return dest;
}

int main(int argc, char** argv)
{
    // ��python��opencvһ������������ͼƬ��BGR��ʽ��
	cv::Mat image = cv::imread("../../assets/dog.jpg");
	if (image.empty())
	{
		printf("could not load image��\n");
		return -1;
	}
    pretty_print(image);
	//cv::namedWindow("test opencv setup");
	//cv::imshow("test opencv setup", image);

    // https://blog.csdn.net/qq_31112205/article/details/105364025

    /**cv::Mat kern = (cv::Mat_<char>(3, 3) << 0, -1, 0,
        -1, 5, -1,
        0, -1, 0);**/
    int shape[4] = { 1, 3, 3, 3 };
    cv::Mat imm(4, shape, CV_32FC1, cv::Scalar(255.0));         // ������άMat����32F��ʾ32λ��������
    mmdet::Tensor* input_tensor = new mmdet::Tensor(imm, shape);
    pretty_print4D(input_tensor->mat, input_tensor->shape);

    int kernel_shape[4] = { 2, 3, 1, 1 };
    cv::Mat kernel_(4, kernel_shape, CV_32FC1, cv::Scalar(3.2));         // �����
    mmdet::Tensor* kernel = new mmdet::Tensor(kernel_, kernel_shape);


    mmdet::Convolution* conv = new mmdet::Convolution(kernel, 1, 0);
    mmdet::Tensor* dstImage = conv->forward(input_tensor);
    pretty_print4D(dstImage->mat, dstImage->shape);

    //cv::Mat dstImage;


    //cv::filter2D(image, dstImage, image.depth(), kern);
    //cv::imshow("dstImage", dstImage);
    //cv::waitKey(0);
	return 0;
}

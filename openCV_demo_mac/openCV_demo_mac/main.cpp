//
//  main.cpp
//  openCV_demo_mac
//
//  Created by Yuan Le on 2018/8/30.
//  Copyright © 2018年 Yuan Le. All rights reserved.
//

#include <iostream>

//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

//案例一：测试
//int main( int argc, char** argv ){
//    string imageName("/Users/yuanle/Desktop/image1.png");
//
//    Mat image = imread(imageName.c_str(), IMREAD_COLOR);
//    if( image.empty() ){
//        cout <<  "Could not open or find the image" << std::endl ;
//        return -1;
//    }
//    namedWindow( "Display window", WINDOW_AUTOSIZE );
//    imshow( "Display window", image );
//    waitKey(0);
//
//    return 0;
//}

//案例二：两张图图片叠加
//int main( int argc, char** argv ){
//    //注意事项：两张叠加，必需有一张图片大于另外一张图片
//    //类似于给我们图片打水印
//    //第一步：准备两种图片
//    //imread函数：读取文件->返回一个Mat矩阵(是OpenCV框架最基本数据类型)
//    Mat mat_image_src = imread("/Users/yuanle/Desktop/image2.jpeg");
//    Mat mat_image_dst = imread("/Users/yuanle/Desktop/image1.png");
//
//    //第二步：创建叠加区域->开辟了一块内存空间
//    Mat mat_roi = mat_image_src(Rect2i((mat_image_src.cols-mat_image_dst.cols)/2, (mat_image_src.rows-mat_image_dst.rows)/2, mat_image_dst.cols, mat_image_dst.rows));
//
//    //第三步：图片叠加->加水印->合并之后覆盖原来的图片
//    //参数一：第一个图片数组
//    //参数二：第一个图片数组->权重
//    //参数三：第二个图片数组
//    //参数四：第二个图片数组->权重
//    //参数五：权重和基础之上标量值
//    //参数六：输出数组->输出目标
//    //dst = src1*alpha + src2*beta + gamma;
//    //伪代码：mat_roi * 0 + mat_image_dst * 1 + 0
//    addWeighted(mat_roi, 0.5, mat_image_dst, 1, 0, mat_roi);
//    //第四步：显示图片
//    namedWindow("叠加图片");
//    imshow("叠加图片", mat_image_src);
//
//    //第五步：窗口暂停->等待状态
//    waitKey(0);//0表示一直等待。这里的单位是毫秒
//
//    return 0;
//
//}

//案例三：输出新的叠加图片
//int main( int argc, char** argv ){
//    //注意事项：两张叠加，必需有一张图片大于另外一张图片
//    //类似于给我们图片打水印
//    //第一步：准备两种图片
//    //imread函数：读取文件->返回一个Mat矩阵(是OpenCV框架最基本数据类型)
//    Mat mat_image_src = imread("/Users/yuanle/Desktop/image2.jpeg");
//    Mat mat_image_dst = imread("/Users/yuanle/Desktop/image1.png");
//
//    //第二步：创建叠加区域->开辟了一块内存空间
//    Mat mat_roi = mat_image_src(Rect2i((mat_image_src.cols-mat_image_dst.cols)/2, (mat_image_src.rows-mat_image_dst.rows)/2, mat_image_dst.cols, mat_image_dst.rows));
//
//    //第三步：图片叠加->加水印->合并之后覆盖原来的图片
//    //参数一：第一个图片数组
//    //参数二：第一个图片数组->权重
//    //参数三：第二个图片数组
//    //参数四：第二个图片数组->权重
//    //参数五：权重和基础之上标量值
//    //参数六：输出数组->输出目标
//    //dst = src1*alpha + src2*beta + gamma;
//    //伪代码：mat_roi * 0 + mat_image_dst * 1 + 0
//    addWeighted(mat_roi, 0.5, mat_image_dst, 1, 0, mat_roi);
//
//
//    //第四步：输入图片
//    namedWindow("输出图片");
//    imwrite("/Users/yuanle/Desktop/output.png", mat_image_src);
//
//    return 0;
//
//}

//案例四：图片腐蚀
//int main( int argc, char** argv ){
//
//    //第一步：加载图片
//    //imread函数：读取文件->返回一个Mat矩阵(是OpenCV框架最基本数据类型)
//    Mat mat_image_src = imread("/Users/yuanle/Desktop/image1.jpg");
//
//    /**
//     第二步：进行腐蚀操作
//
//     @参数一  腐蚀方式
//     @参数二  腐蚀范围（width,height）
//     @参数三  返回腐蚀范围的矩阵
//     */
//    Mat erode_mat =  getStructuringElement(MORPH_CROSS, Size(5, 5));
//
//    //开始腐蚀
//    Mat result_img;
//
//    /**
//     参数一、要腐蚀的图片
//     参数二、腐蚀后的图片
//     参数三、腐蚀的范围
//     */
//    erode(mat_image_src, result_img, erode_mat);
//
//    //显示结果
//    imwrite("/Users/yuanle/Desktop/res.jpg", result_img);
//
//    return 0;
//
//}

//案例五：图片模糊
//int main( int argc, char** argv ){
//
//    //第一步：加载图片
//    //imread函数：读取文件->返回一个Mat矩阵(是OpenCV框架最基本数据类型)
//    Mat mat_image_src = imread("/Users/yuanle/Desktop/image1.jpg");
//
//    //第二步：将图片进行灰度处理
//    Mat mat_gary_img;
//    cvtColor(mat_image_src,mat_gary_img, COLOR_BGR2GRAY);
//
//    //第三步：使用3*3降噪处理
//    Mat mat_edge_img;
//    blur(mat_gary_img, mat_edge_img, Size(3,3));
//    //第四步：算子（一种算法）处理
//    Canny(mat_edge_img, mat_edge_img, 3, 9,3);
//
//    //第五步：显示图片
//    imshow("result", mat_edge_img);
//    waitKey();
//
//    return 0;
//
//}


//案例六：访问图像像素
void colorSpaceReduce(Mat &mat_image_in, Mat &mat_image_out, int div);
int main(int argc, const char * argv[]) {

    //第一步：创建一张图片
    Mat mat_image_src = imread("/Users/yuanle/Desktop/image1.jpg");

    //第二步：按照原始图片创建一张新的图片
    Mat mat_image_dst;
    mat_image_dst.create(mat_image_src.rows,
                         mat_image_src.cols,
                         mat_image_src.type());

    //记录开始时间
    //getTickCount()函数表示：返回CPU自某个事件以来走过的时间周期数(纳秒，非常小的时间单位)
    //例如：电脑启动、电脑休眠等等...
    double time_start = static_cast<double>(getTickCount());

    //第三步：颜色空间缩减
    colorSpaceReduce(mat_image_src, mat_image_dst, 100);

    //记录结束时间
    double time_end = static_cast<double>(getTickCount());
    //getTickFrequency()函数表示：返回CPU一秒钟所有的时间周期数，这样的话是不是我就能够按照秒单位计算出耗时
    double time = (time_end - time_start) / getTickFrequency();
    printf("耗时%f秒", time);


    //第三步：显示图片
    namedWindow("图片");
    imshow("pic", mat_image_dst);
    waitKey();
    return 0;
}


//第一类：指针访问
void colorSpaceReduce(Mat &mat_image_in, Mat &mat_image_out, int div){
    mat_image_out = mat_image_in.clone();
    int rows = mat_image_out.rows;
    int cols = mat_image_out.cols;
    //通道数量->2种颜色，3种颜色（每一个像素点，有多少个颜色）
    int channels = mat_image_out.channels();
    //获取每一行元素个数->RGB个数
    int colsSize = cols * channels;

    //循环缩减颜色通道
    for (int i = 0; i < rows; i++) {
        //获取第i行->指针访问像素点
        uchar* data = mat_image_out.ptr<uchar>(i);
        for (int j = 0; j < colsSize; j++) {
            //指针位移
            //data[j]->表示一个颜色值
            //data[j] = 100
            //div = 24
            //data[j] = 100 / 24 * 24 = 96
            //data[j] = 96 + 24 / 2 = 108
            //这只是一个公式而已(随便你改)->想怎么玩就怎么玩->随心所欲
            data[j] = data[j] / div * div;
        }
    }
}

//第二类：迭代器访问->封装东西比较多(根据场景)
//void colorSpaceReduce(Mat &mat_image_in, Mat &mat_image_out, int div){
//    mat_image_out = mat_image_in.clone();
//    Mat_<Vec3b>::iterator it_start = mat_image_out.begin<Vec3b>();
//    Mat_<Vec3b>::iterator it_end = mat_image_out.end<Vec3b>();
//
//    //循环缩减颜色通道
//    for (; it_start != it_end; it_start++) {
//        //(*it_start)像素点
//        //(*it_start)[0]：表示获取像素点值->蓝色->B值
//        (*it_start)[0] = (*it_start)[0] / div * div;
//        (*it_start)[1] = (*it_start)[1] / div * div;
//        (*it_start)[2] = (*it_start)[2] / div * div;
//    }
//}

//第三类：动态地址计算
//void colorSpaceReduce(Mat &mat_image_in, Mat &mat_image_out, int div){
//    mat_image_out = mat_image_in.clone();
//    int rows = mat_image_out.rows;
//    int cols = mat_image_out.cols;
//
//    for (int i = 0; i < rows; i ++) {
//        for (int j = 0; j < cols; j++) {
//            mat_image_out.at<Vec3b>(i, j)[0] = mat_image_out.at<Vec3b>(i, j)[0] / div * div;
//            mat_image_out.at<Vec3b>(i, j)[1] = mat_image_out.at<Vec3b>(i, j)[1] / div * div;
//            mat_image_out.at<Vec3b>(i, j)[2] = mat_image_out.at<Vec3b>(i, j)[2] / div * div;
//        }
//    }
//}

//案例七：ROI感兴趣区域
//int main(int argc, const char * argv[]) {
//
//    //第一步：创建一张图片
//    Mat mat_image_src = imread("/Users/yuanle/Desktop/image2.jpg");
//    Mat mat_image_logo = imread("/Users/yuanle/Desktop/image3.jpg");
//
//    //第二步：灰度处理->加载一张灰度图片
//    Mat mat_image_mask = imread("/Users/yuanle/Desktop/image3.jpg");
//
//    //第三步：定义ROI区域
//    //根据原始图片->得到src图片一块内存地址(指针)
//    Mat mat_image_roi = mat_image_src(Rect2i(0, 0, mat_image_logo.cols, mat_image_logo.rows));
//
//    //第三步：拷贝到ROI区域
//    //参数一：ROI区域
//    //参数二：需要填充图片(水印)
//    mat_image_logo.copyTo(mat_image_roi, mat_image_mask);
//
//    //第三步：显示图片
//    namedWindow("图片");
//    imshow("图片", mat_image_src);
//    waitKey();
//    return 0;
//}

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
int main( int argc, char** argv ){
    //注意事项：两张叠加，必需有一张图片大于另外一张图片
    //类似于给我们图片打水印
    //第一步：准备两种图片
    //imread函数：读取文件->返回一个Mat矩阵(是OpenCV框架最基本数据类型)
    Mat mat_image_src = imread("/Users/yuanle/Desktop/image2.jpeg");
    Mat mat_image_dst = imread("/Users/yuanle/Desktop/image1.png");
    
    //第二步：创建叠加区域->开辟了一块内存空间
    Mat mat_roi = mat_image_src(Rect2i((mat_image_src.cols-mat_image_dst.cols)/2, (mat_image_src.rows-mat_image_dst.rows)/2, mat_image_dst.cols, mat_image_dst.rows));
    
    //第三步：图片叠加->加水印->合并之后覆盖原来的图片
    //参数一：第一个图片数组
    //参数二：第一个图片数组->权重
    //参数三：第二个图片数组
    //参数四：第二个图片数组->权重
    //参数五：权重和基础之上标量值
    //参数六：输出数组->输出目标
    //dst = src1*alpha + src2*beta + gamma;
    //伪代码：mat_roi * 0 + mat_image_dst * 1 + 0
    addWeighted(mat_roi, 0.5, mat_image_dst, 1, 0, mat_roi);
    
    
    //第四步：输入图片
    namedWindow("输出图片");
    imwrite("/Users/yuanle/Desktop/output.png", mat_image_src);
    
    return 0;
    
}

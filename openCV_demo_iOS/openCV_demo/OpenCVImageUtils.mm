//
//  OpenCVImageUtils.m
//  Dream_20171207_OpenCV_iOS_Demo
//
//  Created by Dream on 2017/12/7.
//  Copyright © 2017年 Tz. All rights reserved.
//

#import "OpenCVImageUtils.h"

@implementation OpenCVImageUtils

+(UIImage*)opencvImage:(UIImage*)srcImage dst:(UIImage*)dstImage{
    //第一步：准备两种图片
    Mat mat_image_src;
    UIImageToMat(srcImage, mat_image_src);
    Mat mat_image_dst;
    UIImageToMat(dstImage, mat_image_dst);
    
    //第二步：创建叠加区域->开辟了一块内存空间
    Mat mat_roi = mat_image_src(Rect2i(0, 0, mat_image_dst.cols, mat_image_dst.rows));
    
    //第三步：图片叠加->加水印->合并之后覆盖原来的图片
    //参数一：第一个图片数组
    //参数二：第一个图片数组->权重
    //参数三：第二个图片数组
    //参数四：第二个图片数组->权重
    //参数五：权重和基础之上标量值
    //参数六：输出数组->输出目标
    //dst = src1*alpha + src2*beta + gamma;
    //伪代码：mat_roi * 0 + mat_image_dst * 1 + 0
    addWeighted(mat_roi, 0, mat_image_dst, 1, 0, mat_roi);
    
    //第四步：将Mat图片->iOS图片
    return MatToUIImage(mat_image_src);
}

@end

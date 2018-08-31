//
//  OpenCVImageUtils.h
//  Dream_20171207_OpenCV_iOS_Demo
//
//  Created by Dream on 2017/12/7.
//  Copyright © 2017年 Tz. All rights reserved.
//

#import <UIKit/UIKit.h>

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
//支持iOS平台图片转换
#include <opencv2/imgcodecs/ios.h>

using namespace cv;

@interface OpenCVImageUtils : NSObject

+(UIImage*)opencvImage:(UIImage*)srcImage dst:(UIImage*)dstImage;

@end

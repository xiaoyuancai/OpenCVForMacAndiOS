//
//  ViewController.m
//  openCV_demo
//
//  Created by Yuan Le on 2018/8/30.
//  Copyright © 2018年 Yuan Le. All rights reserved.
//

#import "ViewController.h"
#import "OpenCVImageUtils.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIImageView *imageView;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (IBAction)clickNormal:(id)sender {
    _imageView.image = [UIImage imageNamed:@"image2.jpeg"];
}

- (IBAction)clickMosaic:(id)sender {
    UIImage* srcPath = [UIImage imageNamed:@"image2.jpeg"];
    UIImage* dstPath = [UIImage imageNamed:@"image1.png"];
    _imageView.image = [OpenCVImageUtils opencvImage:srcPath dst:dstPath];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end

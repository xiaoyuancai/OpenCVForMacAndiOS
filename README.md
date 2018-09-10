#####mac项目中：
注意替换项目中涉及到的图片文件，不然会出错
#####iOS项目中：
注意添加opencv2.framework，添加方式已经在[博客](https://www.jianshu.com/p/c54c887dc2f7)中说明，由于文件太大，我这里没有上传。

#####学习OpenCV基本结构->Mat结构
1. 我们可以简单认为Mat是OpenCV中的图片
2. 矩阵数据结构
3. Mat同时是一个C++类

#####总结一下->Mat结构创建方式有哪些
######方式一：创建Mat->构造方法创建
1. Mat mat_image_dst(mat_image_src.rows, mat_image_src.cols, CV_8UC3);
2. Mat mat_image_dst(Size(mat_image_src.rows, mat_image_src.cols), CV_8UC3);
3. Mat mat_image_dst(200, 200, CV_8UC3, Scalar(255, 0, 0));
4. Mat mat_image_dst(Size(300, 300), CV_8UC3, Scalar(255, 0, 0));
5. Mat mat_image_dst(mat_image_src);
6. Mat mat_image_dst(mat_image_src, Rect(0, 0, 100, 100));
######方式二：创建Mat->create成员函数（方法）代码如下
Mat mat(100, 100, CV_8UC3, Scalar(0, 0, 255));
mat.create(50, 50, CV_8UC(3));
```
运行结果：发现一片漆黑，没有任何颜色（存在问题）注意事项：这个create函数起始不能够为Mat矩阵设置初始值，但是可以在尺寸发生改变的时候重新为矩形数据开辟内存空间
```

######方式三：创建Mat->Matlab初始化（库）代码如下
Mat mat = Mat::eye(100, 100, CV_64F);
Mat mat = Mat::ones(100, 100, CV_64F);
Mat mat = Mat::zeros(100, 100, CV_64F);
eye：表示缩放操作
ones：表示任何一个数组然后初始化Mat
zeros：表示用这个函数可以创建一个作为参数的一个矩阵初始化器->初始化器（默认值：0）
######方式四：对小Mat矩阵通过逗号分隔符方式初始化
Mat mat = (Mat_<int>(2, 2) << 0, 3, -1, 0);
######方式五：通过clone函数和copyTo函数作为一个已经存在Mat对象，创建一个新的Mat对象
Mat mat_image_clone = mat_image_src.clone();
Mat mat_image_clone;
mat_image_src.copyTo(mat_image_clone);

#####3. OpenCV开发中->常用数据结构
1. 第一个->Point类->表示点
	第一种：二维点
	Point2f p2f(100, 100);
	
	第二种：三维点
	Point3f p3f(100, 100, 100);
2. 第二个->Scalar类->常用于表示颜色
	RGB值，就是三个参数代码如下
	Scalar(0, 0, 255);
	参数一：蓝色->B
	参数二：绿色->G
	参数三：红色->R			
```
Scalar基是Matx: Matx设计目的：用于存储小图片（像素点->RGB、BGR）->小矩阵（轻量级Mat）
做OpenCV开发将Mat->Matx，Matx->Mat
```
3. 第三个->Size类->表示尺寸大小（说白了：表示图片大小）Size(100, 100); 
4. 第四个->Rect类->矩形类型（长方形、正方形等等…）
	Rect rect(0, 0, 100, 100);
	常用函数
rect.size()->返回矩形宽高（区域）
rect.area()->返回矩形面积->width * height
rect.contains()->判断某个点是否在矩形范围之内
rect.tl()->返回左上角点的坐标
rect.br()->返回右下角点的坐标
rect1 & rect2 ->表示两个矩形交集
ect1 | rect2 ->表示两个矩形并集
ect + Point(50, 50)->表示矩形平移操作
rect + Size(50, 50)->表示矩形缩放操作


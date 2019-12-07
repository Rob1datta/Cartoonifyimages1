//
// Created by rob on 1/10/17.
//

#include "Cartoonify.h"


Mat cartoonify::loadimage(Mat image)

{
    string path="";
   cout<<"Enter the path of image"<<endl;
    cin>>path;
    image=imread(path);
    return image;
}

Mat cartoonify::cartoonifyimages(Mat image)
{
    Mat oriimage;
    image=loadimage(oriimage);

    Mat gray;//The container for gray
    cvtColor(image,gray,COLOR_BGR2GRAY);
    int median_blur_filter_size=7;
    medianBlur(gray,gray,median_blur_filter_size);

    //Going to the laplacian kernel
     int Laplacian_ksize=7;
    Mat edges;
     Laplacian(gray,edges,CV_8UC1,Laplacian_ksize);
// Mat tmp;
    threshold(edges,edges,80,255,THRESH_BINARY_INV);
    Size size=image.size();
    Size smallsize;
    smallsize.width=size.width/2;
    smallsize.height=size.height/2;
    Mat smallimg=Mat(smallsize,CV_8UC3);
    resize(image,smallimg,smallsize,0,0,INTER_LINEAR);
    Mat tmp=Mat(smallsize,CV_8UC3);
    for(int i=0;i<7;i++) {
        bilateralFilter(smallimg, tmp, 9, 12, 7, BORDER_DEFAULT);
        bilateralFilter(tmp,smallimg,9,9,7,BORDER_DEFAULT);
    }
    resize(image,image,Size(500,500));
    imshow("The image",smallimg);
    imwrite("/home/rob/Downloads/new.jpg",smallimg);


    return edges;

}
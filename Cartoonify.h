//
// Created by rob on 1/10/17.
//

#include "opencv2/opencv.hpp"
#include "iostream"

using namespace cv;
using namespace std;

class cartoonify
{
public:
    cartoonify()
    {
        cout<<"ok now constructing your class"<<endl;
    }

public:
    Mat loadimage(Mat);
    Mat cartoonifyimages(Mat);

public:
    ~cartoonify()
    {
        cout<<"ok bye bye"<<endl;
    }

};


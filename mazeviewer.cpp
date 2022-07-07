#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>


using namespace cv;
using namespace std;
int main() {
    
    Mat img2(180,457,CV_8UC3,Scalar(255,255,255));
    Mat img = imread("yo/3.png");
    cout<<img.cols<<" "<<img.rows<<endl;
    for(int x=0;x<457;x++){
        for(int y=0;y<180;y++){
            Vec3b pixel = img.at<Vec3b>(Point(x,y));
            if(pixel[0]==230){
                Vec3b p = img2.at<Vec3b>(Point(x,y));
                p[0]=0;
                p[1]=0;
                p[2]=0;
                img2.at<Vec3b>(Point(x,y))=p;
            }
        }
    }
    
    imwrite("yo/themaze.png",img2);
    imshow("",img2);
    waitKey(0);
    return 0;
}

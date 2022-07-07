#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>


using namespace cv;
using namespace std;

//421 143
Mat img2(180,457,CV_8UC3,Scalar(255,255,255));
Mat ans = imread("yo/themaze.png");

bool okay(int x,int y){
    
    imshow("solved",ans);
    waitKey(1);
    
    int k=4;
    for(int n=0-k;n<k+1;n++){
    if(ans.at<Vec3b>(Point(x+k,y+n))[0]==0){return 0;}
    if(ans.at<Vec3b>(Point(x-k,y+n))[0]==0){return 0;}
    if(ans.at<Vec3b>(Point(x+n,y+k))[0]==0){return 0;}
    if(ans.at<Vec3b>(Point(x+n,y-k))[0]==0){return 0;}
    }
    
    Vec3b pixel4 = ans.at<Vec3b>(Point(x,y));
    if(pixel4[1]!=255){return 0;}
    
    return 1;
}

bool found(int x,int y){
    
    if(x>420&&y>130){return 1;}
    Vec3b pixel = ans.at<Vec3b>(Point(x,y));
    Vec3b pixel2 = img2.at<Vec3b>(Point(x,y));
    pixel[1]=0;
    pixel[2]=0;
    pixel2[1]=0;
    pixel2[2]=0;
    ans.at<Vec3b>(Point(x,y))=pixel;
    img2.at<Vec3b>(Point(x,y))=pixel2;
    
    if(okay(x+1,y)){
        if(found(x+1,y)){
            return 1;
        }
    }
    if(okay(x,y-1)){
        if(found(x,y-1)){
            return 1;
        }
    }
    if(okay(x-1,y)){
        if(found(x-1,y)){
            return 1;
        }
    }
    if(okay(x,y+1)){
        if(found(x,y+1)){
            return 1;
        }
    }
    
    pixel[2]=255;
    pixel[1]=254;
    pixel2[2]=255;
    pixel2[1]=254;
    ans.at<Vec3b>(Point(x,y))=pixel;
    img2.at<Vec3b>(Point(x,y))=pixel2;
    return 0;
    
}


int main() {
    found(54,145);
    imshow("solved",img2);
    imwrite("yo/solvedmaze2.png",ans);
    imwrite("yo/mazecode.png",img2);
    waitKey(0);
    return 0;
}

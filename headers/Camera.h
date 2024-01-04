#pragma once
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class Camera{
    public:
        int resolucao[2];
        double scale;
        bool tryflip;
        Mat frame;
        

        Camera();
        void drawCapture(Mat imagem);
};
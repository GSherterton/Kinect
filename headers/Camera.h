#pragma once
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include "Mouse.h"

using namespace std;
using namespace cv;

class Camera{
    public:
        int resolucao[2];
        double scale;
        bool tryflip;
        Mat frame;
        

        Camera(int telaResolucao);
        void drawCapture(Mat imagem, Mouse& mouse);
};
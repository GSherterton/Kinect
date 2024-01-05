#pragma once
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class Mouse{
    public:
        int posicao[2];

        string fistCascadeName;
        string leftCascadeName;
        string lpalmCascadeName;
        string rightCascadeName;
        string rpalmCascadeName;

        CascadeClassifier fistCascade;
        CascadeClassifier leftCascade;
        CascadeClassifier lpalmCascade;
        CascadeClassifier rightCascade;
        CascadeClassifier rpalmCascade;

        Mouse();

        void detectAndDisplay(Mat frame);//isso vai alterar a posicao do mouse e desenhar no comeco no frame como um debug
};
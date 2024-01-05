#pragma once
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include "Mouse.h"

using namespace std;
using namespace cv;

class Tela{
    public:
        Mat background;
        Mat imagem;
        int resolucao[2];
        Mouse mouse;

        Tela();
};
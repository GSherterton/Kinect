#include "Camera.h"

using namespace std;

Camera::Camera(){
    tryflip = 1;
    VideoCapture capture;
    Mat frame;

    cout << "Configurando camera\n";
    //cout << "Tentei abrir a camera\n";

    if(!capture.open(0)){
        cout << "Capture from camera #0 didn't work" << endl;
        return;
    }else{
        capture.read(frame);
        resolucao[0] = frame.cols;
        resolucao[1] = frame.rows;

        if(capture.isOpened()){
            //cout << "Fechei a camera\n";
            capture.release();
        }
    }
}

void Camera::drawCapture(Mat imagem){
    if(!frame.empty()){
        double fx = 1 / scale;
        resize(frame, frame, Size(), fx, fx, INTER_LINEAR_EXACT);
        if(tryflip){
            flip(frame, frame, 1);
        }

        frame.copyTo(imagem(Range(0, 0+frame.rows), Range(0, 0+frame.cols)));//depois ver se precisa subtrair 1
    }
}
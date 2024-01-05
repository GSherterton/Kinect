#include "Camera.h"

using namespace std;

Camera::Camera(int telaResolucao){
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

    scale = (resolucao[1]/telaResolucao) * 6;//o ultimo numero eh o fator de conversao
}

void Camera::drawCapture(Mat imagem, Mouse& mouse){
    if(!frame.empty()){
        resize(frame, frame, Size(), 0.5, 0.5, INTER_LINEAR_EXACT);
        mouse.detectAndDisplay(frame);
        
        double fx = 2 / scale;
        resize(frame, frame, Size(), fx, fx, INTER_LINEAR_EXACT);
        if(tryflip){
            flip(frame, frame, 1);
        }

        int posicaoX = (imagem.cols/2) - (frame.cols/2);
        int posicaoY = (imagem.rows-frame.rows);

        //mouse.detectAndDisplay(frame);
    
        frame.copyTo(imagem(Range(posicaoY, posicaoY+frame.rows), Range(posicaoX, posicaoX+frame.cols)));//depois ver se precisa subtrair 1
    }
}
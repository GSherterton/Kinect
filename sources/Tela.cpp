#include "Tela.h"

using namespace std;

Tela::Tela(){
    //iniciar as configuracoes iniciais com uma resolucao inicial de 720p
    resolucao[0] = 1280;
    resolucao[1] = 720;
    background = imread("imagens/background1080.png", IMREAD_UNCHANGED);
    cvtColor(background, background, COLOR_BGRA2BGR);
    resize(background, background, Size(), 2.0/3.0, 2.0/3.0, INTER_LINEAR_EXACT);
}
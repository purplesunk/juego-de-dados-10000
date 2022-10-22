#include <iostream>
#include <ctime>
#include "rlutil.h"
#include "dibujardados.h"

void drawSqrTop() {
    std::cout << R"(▀)";
}

void drawSqrBottom() {
    std::cout << R"(▄)";
}

void drawUno(int posx, int posy) {
    rlutil::locate(posx+3,posy+1);
    drawSqrTop();
}

void drawDos(int posx, int posy) {
    rlutil::locate(posx+1,posy);
    drawSqrBottom();
    rlutil::locate(posx+5,posy+1);
    drawSqrBottom();
}

void drawTres(int posx, int posy) {
    drawUno(posx, posy);
    drawDos(posx, posy);
}

void drawCuatro(int posx, int posy) {
    drawDos(posx, posy);
    rlutil::locate(posx+5,posy);
    drawSqrBottom();
    rlutil::locate(posx+1,posy+1);
    drawSqrBottom();
}

void drawCinco(int posx, int posy) {
    drawUno(posx, posy);
    drawCuatro(posx, posy);
}

void drawSeis(int posx, int posy) {
    drawCuatro(posx, posy);
    rlutil::locate(posx+3,posy);
    drawSqrBottom();
    rlutil::locate(posx+3,posy+1);
    drawSqrBottom();
}

void elegirNumero(int posx, int posy, int num) {
    switch (num) {
        case 1:
            drawUno(posx, posy);
            break;
        case 2:
            drawDos(posx, posy);
            break;
        case 3:
            drawTres(posx, posy);
            break;
        case 4:
            drawCuatro(posx, posy);
            break;
        case 5:
            drawCinco(posx, posy);
            break;
        case 6:
            drawSeis(posx, posy);
            break;
    }
}

void drawHalfLine(int cantx, int posy, int inicio,  bool top = false) {
    for (int i=inicio; i<=cantx; i++) {
        rlutil::locate(i,posy);
        if (top) {
            drawSqrTop();
        }
        else {
            drawSqrBottom();
        }
    }
}

void drawBlankLine(int cantx, int posy, int inicio) {
    for (int i=inicio; i<=cantx; i++) {
        rlutil::locate(i,posy);
        std::cout << " " << "\n";
    }
}

void dibujarDado(int posx, int posy, int num) {
    // forma principal:
    rlutil::setBackgroundColor(rlutil::CYAN);
    rlutil::locate(posx,posy);
    std::cout << "       " << "\n";
    rlutil::locate(posx,posy+1);
    std::cout << "       " << "\n";
    rlutil::locate(posx,posy+2);
    std::cout << "       " << "\n";

    // sombra:
    rlutil::setBackgroundColor(rlutil::CYAN);
    rlutil::setColor(rlutil::BLACK);
    drawHalfLine(posx,posy+2,posx);

    rlutil::setColor(rlutil::BLUE);
    drawHalfLine(posx+7,posy+2,posx+1);

    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::locate(posx+7,posy);
    drawSqrBottom();

    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::locate(posx+7,posy+1);
    std::cout << " ";
    rlutil::locate(posx+7,posy+2);
    std::cout << " ";


    // numero del dado:
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::CYAN);
    elegirNumero(posx, posy, num);

    // resetear los colores:
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
}

void dibujarDados(int vec[], int tam) {
    int x=rlutil::tcols()/(tam*3);
    for (int i=0; i<tam; i++) {
        dibujarDado(rand()%x+5+(x+7)*i,rand()%3+10,vec[i]);
    }
}

/* PRUEBA DE DADOS
int main() {
    rlutil::hidecursor();
    srand(time(NULL));

    while (true) {
        int x=rlutil::tcols()/18;
        for (int i=0; i<6; i++) {
            dibujarDado(rand()%x+5+(x+7)*i,rand()%3+10,rand()%6+1);
        }

        rlutil::anykey();

        for (int i=10; i<16; i++) {
            drawBlankLine(x*18,i,5);
        }

        rlutil::anykey();
        //rlutil::cls();
    }


    return 0;
}
*/

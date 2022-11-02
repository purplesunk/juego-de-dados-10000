#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "interfaz.h"
#include "dibujardados.h"
#include "funciones.h"
#include "menu.h"

void dibujarLinea(int posx, int posy, int tam, char forma) {
    for (int i=posx; i<posx+tam; i++) {
        rlutil::locate(i,posy);
        std::cout << forma;
    }
}

void mostrarPuntaje (int indicePuntaje, int puntaje) {
    rlutil::locate(3,19);
    switch (indicePuntaje) {
        case 0:
            std::cout << "OBTUVISTE UN SEXTETO!";
            break;
        case 1:
            std::cout << "OBTUVISTE UN TRIO 1 AMPLIADO! +" << puntaje << " PUNTOS";
            break;
        case 2:
            std::cout << "OBTUVISTE UN TRIO 1 AMPLIADO! +" << puntaje << " PUNTOS";
            break;
        case 3:
            std::cout << "OBTUVISTE UNA ESCALERA LARGA! +" << puntaje << " PUNTOS";
            break;
        case 4:
            std::cout << "OBTUVISTE UN TRIO 1! +" << puntaje << " PUNTOS";
            break;
        case 5:
            std::cout << "OBTUVISTE UN TRIO " << puntaje/100 << "++! +" << puntaje << " PUNTOS";
            break;
        case 6:
            std::cout << "OBTUVISTE UN JUEGO DE UNO! +" << puntaje << " PUNTOS";
            break;
        case 7:
            std::cout << "OBTUVISTE UN JUEGO DE UNO! +" << puntaje << " PUNTOS";
            break;
        case 8:
            std::cout << "OBTUVISTE UN JUEGO DE CINCO! +" << puntaje << " PUNTOS";
            break;
        case 9:
            std::cout << "OBTUVISTE UN JUEGO DE CINCO! +" << puntaje << " PUNTOS";
            break;
        case 10:
            std::cout << "NO OBTUVO NADA, Perdio el puntaje acumulado en esta ronda.";

            break;
    }
}

/*
bool continuarLanzando() {

    int centro = rlutil::tcols()/2;

    char pregunta[] = "CONTINUAR LANZANDO? (S/N)";

    int mitadPregunta = strlen(pregunta)/2;

    rlutil::locate(centro - mitadPregunta , 22);
    std::cout << pregunta;
    do {
        switch (rlutil::getkey()) {
            case 115:  // s o S
            case 83:
                return true;
                break;
            case 110:  // n o N
            case 78:
                return false;
                break;
        }
    } while (true);
}
*/

void teclaParaContinuar(int posy) {

    int centro = rlutil::tcols()/2;

    char aviso[] = "Presione una tecla para continuar.";

    int mitadAviso = strlen(aviso)/2;

    rlutil::locate(centro - mitadAviso , posy);
    std::cout << aviso;

    rlutil::anykey();

}

bool continuarLanzando(int posy) {

    int centro = rlutil::tcols()/2;

    char pregunta[] = "CONTINUAR LANZANDO?";

    int mitadPregunta = strlen(pregunta)/2;

    rlutil::locate(centro - mitadPregunta , posy);
    std::cout << pregunta;


    int x = 2;

    do {

        mostrarOpcion("  SI  ", centro-10, posy+1, x == 1);
        mostrarOpcion("  NO  ", centro+5, posy+1, x == 2);


        switch (rlutil::getkey()) {

            case rlutil::KEY_LEFT:
            case 68:
                x = 1;
                break;

            case rlutil::KEY_RIGHT:
            case 67:
                x = 2;
                break;

            case rlutil::KEY_ENTER:
            case 10:
                setDefault();
                switch (x) {
                    case 1:
                        return true;
                        break;
                    case 2:
                        return false;
                        break;
                }
        }

    } while (true);
}



void ingreseNombre(char *nombre, char *nombreJugador, int numJugador) {
    int centrox = rlutil::tcols()/2;
    int centroy = rlutil::trows()/2;

    if (numJugador==0) {
        rlutil::locate(centrox-13, centroy-1);
        std::cout << "Ingrese nombre del jugador: ";
    }
    else {
        rlutil::locate(centrox-14, centroy-1);
        std::cout << "Ingrese nombre del jugador " << numJugador << ": ";
    }

    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);
    dibujarLinea(centrox-13, centroy+1, 27, char(32));

    rlutil::locate(centrox-12, centroy+1);
    rlutil::showcursor();

    cargarCadena(nombreJugador, 30);

    setDefault();

    separarNombre(nombreJugador, nombre, 15);

    rlutil::hidecursor();
    rlutil::cls();

}

void dibujarCaja(int posx, int posy, int ancho, int alto) {

    for (int i=posx; i<=posx+ancho; i++) {

        rlutil::locate(i,posy);

        if (i==posx) {

            std::cout << char(201);

        }
        else if (i==posx+ancho) {

            std::cout << char(187);

        }
        else {

            std::cout << char(205);

        }
    }

    for (int i=posx; i<=posx+ancho; i++) {

        rlutil::locate(i,posy+alto);

        if (i==posx) {

            std::cout << char(200);

        }
        else if (i==posx+ancho) {

            std::cout << char(188);

        }
        else {

            std::cout << char(205);

        }
    }

    for (int i=posy+1; i<posy+alto; i++) {

        rlutil::locate(posx,i);

        std::cout << char(186);
    }

    for (int i=posy+1; i<posy+alto; i++) {

        rlutil::locate(posx+ancho,i);

        std::cout << char(186);
    }

}

void dibujarCajaTitulo(int posx, int posy, int ancho, int alto, const char* titulo) {
    int anchoTitulo = strlen(titulo);
    int mitadTitulo = (posx+ancho)/2 - anchoTitulo/2;

    if (anchoTitulo > ancho) {
        ancho=anchoTitulo+1;
    }

    if (anchoTitulo > ancho/2) {
        mitadTitulo=posx+1;
    }

    dibujarCaja(posx, posy, ancho, alto+3);

    dibujarLinea(posx, posy+2, 1, char(204));

    dibujarLinea(posx+1, posy+2, ancho-1, char(205));

    dibujarLinea(posx+ancho, posy+2, 1, char(185));

    rlutil::locate(mitadTitulo,posy+1);
    std::cout << titulo;
}

void dibujarCajaInfo(char *nombre, int tamConsola) {

    char titulo[30] = "TURNO DE ";

    strcat(titulo, nombre);

    dibujarCajaTitulo(1, 1, tamConsola-1, 3, titulo);

    int altura = rlutil::trows();

    dibujarCaja(1, 18, tamConsola-1, altura - 18);

}

void borrarResultado() {

    int anchoCaja = rlutil::tcols() - 2;

    for (int i = 19; i<=23; i++) {
        dibujarLinea(2, i, anchoCaja,char(32));
    }

}

void dibujarDatos(int posx, int posy, const char* texto, int dato, const char* texto2, int dato2) {

    rlutil::locate(posx, posy);
    std::cout << texto;

    int posdato = posx + strlen(texto);

    dibujarLinea(posdato,posy,5,char(32));
    rlutil::locate(posdato, posy);
    std::cout << dato;

    rlutil::locate(posx, posy+2);
    std::cout << texto2;

    int posdato2 = posx + strlen(texto2);

    dibujarLinea(posdato2,posy+2,5,char(32));
    rlutil::locate(posdato2, posy+2);
    std::cout << dato2;
}

void mostrarPuntajeObtenido(int posx, int posy, char *nombreJugador, int puntaje, int  ronda, int lanzamiento, const char *texto) {
    rlutil::cls();

    char titulo[80] = {};

    strcat(titulo, texto);

    strcat(titulo, nombreJugador);

    posx-= strlen(titulo)/2;
    posy-= 3;

    dibujarCajaTitulo(posx, posy, strlen(titulo)+2, 3, titulo);

    rlutil::locate(posx+2, posy+3);
    std::cout << "PUNTAJE: " << puntaje;

    rlutil::locate(posx+2, posy+4);
    std::cout << "RONDA: " << ronda;

    rlutil::locate(posx+2, posy+5);
    std::cout << "LANZAMIENTO: " << lanzamiento;

    teclaParaContinuar((posy+3)*2+1);

    rlutil::cls();
}

void entreRonda (int posx, int posy, int ronda, const char *nombre, int puntaje) {

    dibujarCaja(posx-15, posy-2, 30, 4);

    rlutil::locate(posx-13, posy-1);
    std::cout << "RONDA SIGUIENTE: " << ronda;

    rlutil::locate(posx-13, posy);
    std::cout << "JUGADOR: " << nombre;

    rlutil::locate(posx-13, posy+1);
    std::cout << "PUNTAJE TOTAL: " << puntaje;

}

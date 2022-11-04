#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "gameplay.h"
#include "interfaz.h"
#include "funciones.h"
#include "menu.h"

enum Opciones {
    MODO_UN_JUGADOR = 0,
    MODO_DOS_JUGADORES = 1,
    MEJOR_PUNTAJE = 2,
    SALIR = 3
};

void mostrarOpcion(const char* texto, int posx, int posy, bool seleccionado) {
    if (seleccionado) {
        ponerColores(rlutil::MAGENTA, rlutil::BLACK);
        rlutil::locate(posx-2,posy);
        std::cout << " " << (char)62 << texto << (char)60 << " ";
        ponerColores(rlutil::BLACK, rlutil::WHITE);
    }
    else {
        ponerColores(rlutil::BLACK, rlutil::WHITE);
        rlutil::locate(posx-2,posy);
        std::cout << "  " << texto << "  ";
    }
    rlutil::setColor(rlutil::BLACK);
}


void mostrarMejorPuntaje(int mejorPuntaje[], char* nombreMejorPuntaje) {
    rlutil::cls();

    int centrox = rlutil::tcols()/2;
    int centroy = rlutil::trows()/2;

    if (nombreMejorPuntaje[0] == '\0') {

        char aviso[] = "No se ha jugado ninguna partida.";

        rlutil::locate(centrox - (strlen(aviso)/2), centroy);
        std::cout << aviso;

        teclaParaContinuar(centroy+1);

        rlutil::cls();

    }
    else {

        mostrarPuntajeFinal(nombreMejorPuntaje, mejorPuntaje[0], mejorPuntaje[1], mejorPuntaje[2], " MEJOR PUNTAJE POR ");

    }
}

int menu() {
    rlutil::cls();
    int y = 0;

    int centroH = rlutil::tcols()/2;
    int centroV = rlutil::trows()/2;

    int centrox = centroH-12;
    int centroy = centroV-2;

    // 0 = puntaje, 1 = ronda, 2 = lanzamiento
    int mejorPuntaje[3] {};
    char nombreMejorPuntaje[30] = {};

    do {
        ponerColores(rlutil::BLACK, rlutil::WHITE);
        rlutil::hidecursor();

        mostrarOpcion("   MODO UN JUGADOR      ", centrox, centroy,   y == 0);
        mostrarOpcion("   MODO DOS JUGADORES   ", centrox, centroy+1, y == 1);
        mostrarOpcion("   MEJOR PUNTAJE        ", centrox, centroy+2, y == 2);
        mostrarOpcion("   SALIR                ", centrox, centroy+3, y == 3);


        switch (rlutil::getkey()) {

            case 15:  // ABAJO
            case 66:  //
                y++;

                if (y>3) {

                    y=3;

                }
                break;

            case 14:  // ARRIBA
            case 65:  //
                y--;

                if (y<0) {

                    y=0;

                }
                break;

            case 1:  // ENTER
            case 10: //
                rlutil::cls();
                ponerColores(rlutil::BLACK, rlutil::WHITE);
                switch(y){
                    case Opciones::MODO_UN_JUGADOR: {

                        modoUnJugador(mejorPuntaje, nombreMejorPuntaje);

                    }
                    break;

                    case Opciones::MODO_DOS_JUGADORES: {

                        modoDosJugadores(mejorPuntaje, nombreMejorPuntaje);

                    }
                    break;

                    case Opciones::MEJOR_PUNTAJE: {

                        mostrarMejorPuntaje(mejorPuntaje, nombreMejorPuntaje);

                    }

                    break;

                    case Opciones::SALIR: {
                        ponerColores(rlutil::BLACK, rlutil::WHITE);
                        rlutil::cls();
                        return 0;
                    }
                    break;
                }
                break;
        }

    } while (true);
}

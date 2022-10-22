#include <iostream>
#include "rlutil.h"
#include "funciones.h"
#include "menu.h"
#include "gameplay.h"

void setDefault() {
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
}

void opcionElegida(int opcion) {
    switch (opcion) {
        case 1:
            modoUnJugador();
            break;
        case 2:
            std::cout << "ModoDosJugadores\n";
            break;
        case 3:
            std::cout << "Mejores Puntajes\n";
            break;
    }
}

void mostrarOpcion(const char* texto, int posx, int posy, bool seleccionado) {
    if (seleccionado) {
        rlutil::setBackgroundColor(rlutil::MAGENTA);
        rlutil::setColor(rlutil::BLACK);
        rlutil::locate(posx-2,posy);
        std::cout << " " << (char)62 << texto << (char)60 << " " << std::endl;
        setDefault();
    }
    else {
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::locate(posx-2,posy);
        std::cout << "  " << texto << "  " << std::endl;
    }
}

void menu() {
    int opcion = 1, y = 0;
    int centrox = (rlutil::tcols()/2)-12;
    int centroy = (rlutil::trows()/2)-2;

    do {
        setDefault();
        rlutil::hidecursor();

        mostrarOpcion("   MODO UN JUGADOR      ", centrox, centroy, y == 0);
        mostrarOpcion("   MODO DOS JUGADORES   ", centrox, centroy+1, y == 1);
        mostrarOpcion("   MEJORES PUNTAJES     ", centrox, centroy+2, y == 2);
        mostrarOpcion("   SALIR                ", centrox, centroy+3, y == 3);


        switch (rlutil::getkey()) {
            case 15:  // DOWN
            case 66:  // DOWN
                y++;
                if (y>3) {
                    y=3;
                }
                break;
            case 14:  // ARRIBA
            case 65:  // ARRIBA
                y--;
                if (y<0) {
                    y=0;
                }
                break;
            case 1:  // ENTER
            case 10: // ENTER
                switch(y){
                    case 0:
                        opcion=1;
                        opcionElegida(opcion);
                        rlutil::cls();
                        break;
                    case 1:
                        opcion=2;
                        opcionElegida(opcion);
                        rlutil::cls();
                        break;
                    case 2:
                        opcion=3;
                        opcionElegida(opcion);
                        rlutil::cls();
                        break;
                    case 3:
                        opcion=0;
                        break;
                }
                break;
        }

    } while (opcion!=0);
}

#include <iostream>
#include "rlutil.h"
#include "menu.h"
#include "gameplay.h"

void setDefault() {
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
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

int menu() {
    int opcion = 1;
    int y = 0;
    int centrox = (rlutil::tcols()/2)-12;
    int centroy = (rlutil::trows()/2)-2;

    int mejorPuntaje = 0;
    int rondaMejorPuntaje = 0;
    char nombreMejorPuntaje[10];
    char apellidoMejorPuntaje[10];

    do {
        setDefault();
        rlutil::hidecursor();

        mostrarOpcion("   MODO UN JUGADOR      ", centrox, centroy, y == 0);
        mostrarOpcion("   MODO DOS JUGADORES   ", centrox, centroy+1, y == 1);
        mostrarOpcion("   MEJORES PUNTAJES     ", centrox, centroy+2, y == 2);
        mostrarOpcion("   SALIR                ", centrox, centroy+3, y == 3);

        switch (rlutil::getkey()) {
            case 15:  // ABAJO
            case 66:  // ABAJO
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
                        modoUnJugador();
                        break;
                    case 1:
                        rlutil::cls();
                        std::cout << char(220);
                        rlutil::anykey();
                        break;
                    case 2:
                        std::cout << "Mejores Puntajes\n";
                        break;
                    case 3:
                        setDefault();
                        rlutil::cls();
                        return 0;
                        break;
                }
                break;
        }

    } while (true);
}

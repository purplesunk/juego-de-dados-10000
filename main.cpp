#include <iostream>
#include <ctime>
#include <string>
#include "rlutil.h"
#include "funciones.h"
#include "menu.h"
#include "gameplay.h"

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));
    menu();
    return 0;
}

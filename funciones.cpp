#include <iostream>
#include <cstring>
#include "funciones.h"

void cargarVectorRandom(int vec[], int tam, int limite) {

    for (int i=0; i<tam; i++) {

        vec[i]=(rand()%limite)+1;

    }

}

void mostrarVec(int vec[], int tam) {
    for (int i=0; i<tam; i++) {

        std::cout << vec[i] << "\t";

    }

    std::cout << "\n";
}

int maxVector(int vec[], int tam) {
    int maximo = vec[0];

    for (int i=1; i<tam; i++) {

        if (vec[i]>maximo) {

            maximo=vec[i];
        }

    }

    return maximo;
}

int posMaxVector(int vec[], int tam) {

    int maximo = vec[0];
    int pos = 1;

    for (int i=1; i<tam; i++) {

        if ( vec[i] > maximo) {

            maximo=vec[i];

            pos=i+1;

        }
    }

    return pos;
}

bool hayCeros(int vec[], int tam){

    bool hayCero = false;

    for (int i=0;i<tam;i++) {

        if(vec[i]==0) {

            hayCero = true;

        }

    }

    return hayCero;

}

void cargarCadena(char *palabra, int tamano) {

    int i=0;

    fflush(stdin);

    for (i=0; i<tamano; i++){

        palabra[i]=std::cin.get();

        if (palabra[i]=='\n'){

            break;

        }

    }

    palabra[i]='\0';

    fflush(stdin);

}

void separarNombre(char *nombreCompleto, char *nombre, int tamNombre, char *apellido, int tamApellido) {

    int j=0;

    for (int i=0; i<tamNombre; i++) {

        nombre[i] = nombreCompleto[j];

        j++;

        if (nombreCompleto[j] == char(32)) {

            j++;

            nombre[i]=='\0';

            break;
        }


    }

    for (int i=0; i<tamApellido; i++) {

        apellido[i] = nombreCompleto[j];

        j++;

        if (nombreCompleto[j]=='\n'){

            apellido[i]=='\0';

            break;

        }
    }
}

void mostrarCadena(char *palabra, int tamano) {

    for (int i=0; i<tamano; i++) {

        std::cout << palabra[i];

        if (palabra[i]=='\0'){

            break;

        }

    }

    std::cout << "\n";
}

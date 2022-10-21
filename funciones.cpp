#include <iostream>
#include "funciones.h"

void linea() {
    std::cout << "---------------------------------------------------\n";
}

void cargarVectorRandom(int vec[], int tam, int tope) {
    for (int i=0; i<tam; i++) {
        vec[i]=(rand()%tope)+1;
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
        if (vec[i]>maximo) {
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

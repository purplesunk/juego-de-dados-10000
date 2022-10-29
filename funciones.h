#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void cargarCadena(char *palabra, int tamano);
void cargarVectorRandom(int vec[], int tam, int limite);
void mostrarVec(int vec[], int tam);
int maxVector(int vec[], int tam);
int posMaxVector(int vec[], int tam);
bool hayCeros(int vec[], int tam);
void separarNombre(char *nombreCompleto, char *nombre, int tamNombre, char *apellido, int tamApellido);
void mostrarCadena(const char *palabra);

#endif // FUNCIONES_H_INCLUDED

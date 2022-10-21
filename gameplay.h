#ifndef GAMEPLAY_H_INCLUDED
#define GAMEPLAY_H_INCLUDED

std::string ingreseNombre();
int comprobarMas3Num(int vec[], int tam, int puntaje);
int comprobarCantDado(int vec[], int pos, int cant, int puntaje);
int comprobarEscalera(int vec[], int tam, int puntaje);
int sacarPuntaje(int vec[], int tam);
int cantNumDados(int vec[], int tam);
int lanzamiento(int ronda, int puntajeTotal, std::string nombreJug);
bool continuarLanzando();
void tiradaDados(int vec[],int tam);
void modoUnJugador();
void interfazUnJugador(std::string nombreJug, int ronda, int puntajeTotal, int puntosRonda, int nroLanzamiento);

#endif // GAMEPLAY_H_INCLUDED

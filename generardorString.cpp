#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

string generarStringAleatorioConRistra(int longitud, char caracter, int posicion, int numeroDeRepeticiones) {

    const string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"; // se puede lograr lo mismo con char c = (char)random(123); pero asi queda mas claro
    srand(time(nullptr));

    string resultado;
    resultado.reserve(longitud);

    for (int i = 0; i < longitud; ++i) {
        if (i >= posicion && i < (posicion + numeroDeRepeticiones)){
            resultado += caracter;
        }
        else {
            resultado += caracteres[rand() % caracteres.size()];
        }
    }

    return resultado;
}

string generarStringAleatorioConCaracteresLimitados(int longitud, string caracteres) {

    srand(time(nullptr));

    string resultado;
    resultado.reserve(longitud);

    for (int i = 0; i < longitud; ++i) {
        resultado += caracteres[rand() % caracteres.size()];
    }

    return resultado;
}
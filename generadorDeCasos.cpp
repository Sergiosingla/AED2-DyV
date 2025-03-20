#include "generadorDeCasos.h"

generadorDeCasos::generadorDeCasos()
{
    //ctor
}

generadorDeCasos::~generadorDeCasos()
{
    //dtor
}


string generarStringAleatorio(int longitud) {

    const string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"; // se puede lograr lo mismo con char c = (char)random(123); pero asi queda mas claro
    srand(time(nullptr));

    string resultado;
    resultado.reserve(longitud);

    for (int i = 0; i < longitud; ++i) {
        resultado += caracteres[rand() % caracteres.size()];
    }

    return resultado;


    // Este lo dejo por si hay que mirar algo o cambiar algo pero siempre da el mismo resultado (si pones 200 en el tamaño, m = 10 y C = o, da siempre el mismo valor)
    /*
    const string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, caracteres.size() - 1);

    string resultado;
    resultado.reserve(longitud);

    for (int i = 0; i < longitud; ++i) {
        resultado += caracteres[distrib(gen)];
    }

    return resultado;
    */


    //Este deberia funcionar y en teoria es mejor pero da un error y no se porque
    /*
    //randomize();        // Reinicia el generedor de números aleatorios
    char cadena[longitud];
    int last = longitud - 1;
    cadena[last]=0;
    for(int i=0; i<last;){
        char c = (char)random(123); // ASCII 122 = z
        if(!isalnun (c)) continue;
        cadena[i] = c;
        i++;
    }
    */
}



string generarStringAleatorioConRistra(int longitud, char caracter, int posicion, int numeroDeRepeticiones) {

    const string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"; // se puede lograr lo mismo con char c = (char)random(123); pero asi queda mas claro
    srand(time(nullptr));

    string resultado;
    resultado.reserve(longitud);

    for (int i = 0; i < longitud; ++i) {
        if (i >= posicion && < posicion + numeroDeRepeticiones){
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

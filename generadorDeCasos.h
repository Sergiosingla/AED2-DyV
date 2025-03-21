#ifndef GENERADORDECASOS_H
#define GENERADORDECASOS_H


using namespace std;

class generadorDeCasos
{
    public:
        string generarStringAleatorio(int longitud);

        string generarStringAleatorioConRistra(int longitud, char caracter, int posicion, int numeroDeRepeticiones) ;

        string generarStringAleatorioConCaracteresLimitados(int longitud, string caracteres);

};



#endif // GENERADORDECASOS_H

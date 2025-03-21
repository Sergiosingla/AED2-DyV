#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include "generadorDeCasos.cpp"
//#include "generadorDeCasos.h"




typedef struct dataStruct
{
    int index;
    int nOcu;
}Data;



Data contarCcons(string A,int i, int n, char C){
    Data res ={-1,0};

    int cont=0;
    int index=-1;

    for(int j=i;j<n+i;j++){
        if(A[j]==C){
            if(cont==0){
                index=j;
            }
            cont++;
        }
        else{
            if(cont>res.nOcu){
                res.nOcu=cont;
                res.index=index;
            }
            cont=0;
        }

    }
    if (cont>0) {
        res.nOcu=cont;
        res.index=index;
    }
    return res;

}


Data combinar(string A, int n, int m, char C, Data X, int finX, Data Z){

    // Seleccion de la mejor solucion de ambas partes
    Data firstAttempt;
    if (X.nOcu > Z.nOcu) {
        firstAttempt = X;
    } else {
        firstAttempt = Z;
    }


    // Busqueda de una posible mejor solucion en el centro de ambas partes

    // Si donde temina la primera parte o donde empieza la segunda parte no son C, la mejor solucion es firstAttempt
    if (finX >= A.length() || A[finX-1]!=C || A[finX]!=C) {
        return firstAttempt;
    }
    else {          // Si la primera parte termina y la segunda parte empiezan en C se busca una posible solucion

        // Avanzamos hacia atras hasta dejar de encontrar C
        int j=finX-1;

        // Contador de C consecutivas hacia atras en la primera parte
        int secondAttemptCont = 0;
        while(j>=0&&A[j]==C) {
            secondAttemptCont++;
            j--;
        }

        // Indice de inicio de la posible solucion
        int indexIniSecondAttempt=j+1;

        // Valoracion del resultado
        int necesaryC = firstAttempt.nOcu-secondAttemptCont;
        if (necesaryC > Z.nOcu) {
            // En este punto no habria una mejor solucion que la que ya tenemos
            return firstAttempt;
        } else {
            // Contador de C consecutivas hacia adelante en la segunda parte
            int k = finX;
            while (k < m && A[k] == C) {
                secondAttemptCont++;
                k++;
            }

            // Si la nueva cantidad de C consecutivas es mayor, actualizamos el resultado
            if (secondAttemptCont > firstAttempt.nOcu) {
                return {indexIniSecondAttempt,min(m,secondAttemptCont)};
            }
            return firstAttempt;
        }
    }


}


/*
//  string A -> string de entrada para anlizar
//  i -> indice inicio de analisis de A
//  n -> longuid del string a analizar
//  m -> longuitud de la subcadena a buscar
//  C -> caracter que se desea buscar
*/
Data DyV_algorithm(string A, int i, int n, int m, char C){

    if(m<1){
        exit(1);
    }
    if(n<=m){       // Solucion directa
        return contarCcons(A,i,n,C);
    }
    else{           // Recursividad
        int div = n/2;
        return combinar(A,n,m,C,DyV_algorithm(A,i,div,m,C),i+div,DyV_algorithm(A,i+div,n-div,m,C));
    }

}


int main(){
    //Indice de inicio de busqueda, se inicializa siempre en 0
    const int i = 0;

    // Generamos string aleatorio
    int longitud;
    cout << "Ingrese la longitud del string aleatorio: ";
    cin >> longitud;
    string A = generadorDeCasos.generarStringAleatorio(longitud);
    const long n = A.length();
    printf("Se ha podido crear satisfactoriamente un String aleatorio de %d caracteres\n", n);

    //Pedimos el tamaño del substring a buscar
    const int m = 10;
    /*
    int m;
    cout << "Ingrese la longitud del substring a buscar: ";
    cin >> m;
    */

    //Pedimos el caracter a buscar
    const char C = 'o';
    /*
    char C;
    cout << "Ingrese la letra a buscar en el array: ";
    cin >> C;
    */


    Data restul = DyV_algorithm(A,i,n,m,C);
    printf("Inicio=%d\nApariciones=%d\n",restul.index+1,restul.nOcu);
}


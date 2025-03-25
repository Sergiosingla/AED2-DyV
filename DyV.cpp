#include <stdlib.h>
#include <iostream>
#include <string>
#include "generardorString.cpp"

using namespace std;


// Struct usado para devolver los datos necesarios para comparar soluciones y resolver el problema
typedef struct dataStruct
{
    int index;
    int nOcu;
}Data;



// Funcion que resuelve el problema de manera directa
// Cuenta las ocurrencias de C consecutivas y devuelve el indice donde esta ocurrencia comienza y cuantas ocurrencias hay
/*
//  string A -> string de entrada para anlizar
//  i -> indice inicio de analisis de A
//  n -> longuid del string a analizar
//  C -> caracter que se desea buscar
*/
Data contarCcons(string A,int i, int n, char C){

    Data res ={-1,0};   // Variable que se ira actualizando para almacenar la posible solucion

    int cont=0;         // Contador temporal de ocurrencias
    int index=-1;       // Indice de donde comienza la posible solucion

    for(int j=i;j<n+i;j++){

        if(A[j]==C){
            if(cont==0){    // Primera iteracion sobre una nueva ocurrencia de C, se acutaliza index
                index=j;
            }
            cont++;
        }
        else{
            if(cont>res.nOcu){  // Si la solucion actual es mejor que la que teniamos anteriormete se actualiza la mejor solucion
                res.nOcu=cont;
                res.index=index;
            }
            cont=0;
        }
        
    }
    if (cont>0) {               // En caso de que la subcadena analizada termine con C y estemos ante la mejor solucion, res no se actualizario
        res.nOcu=cont;          // por eso hacer falta actualizarlo aqui
        res.index=index;
    }
    return res;

}

// Función para combinar las soluciones y buscar una posible mejor solucion en la combinacion de ambas subpartes
/*
//  string A -> string de entrada para anlizar
//  n -> longuid del string a analizar
//  m -> longuitud de la subcadena a buscar
//  C -> caracter que se desea buscar
//  X -> mejor solucion de la primera subparte
//  finX -> division de las dos subpartes
//  Z -> mejor solucion de la segunda subparte
*/
Data combinar(string A, int n, int m, char C, Data X, int finX, Data Z){
    
    // Seleccion de la mejor solucion de ambas partes, primer intento de mejor solucion
    Data firstAttempt;
    if (X.nOcu > Z.nOcu) {
        firstAttempt = X;
    } else {
        firstAttempt = Z;
    }
    

    // Busqueda de una posible mejor solucion en el centro de ambas partes

    // Si donde temina la primera parte o donde empieza la segunda parte no son C, o que estemos ya ante la ultima combinacion, la mejor solucion es firstAttempt
    if (finX >= A.length() || A[finX-1]!=C || A[finX]!=C) {
        return firstAttempt;
    }
    else {          // Si la primera parte termina y la segunda parte empiezan en C se busca una posible solucion
        
        // Avanzamos hacia atras hasta dejar de encontrar C
        // Se utiliza j como iterador que ira retrocediendo en la primera subparte
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

        // En el caso de que las C consecutivas necesarias para una mejor solucion sea mayor que el numero de ocurrencias de la mejor solucion
        // de dicha parte, no existiria una mejor solucion.
        if (necesaryC > Z.nOcu) {
            // En este punto no habria una mejor solucion que la que ya tenemos
            return firstAttempt;
        } else {    // En este punto puede haber una mejor solucion en la combinacion de las dos subpartes
            // K como iterador para contar las C consecutivas desde la division de las dos subpartes hacia delante
            int k = finX;
            while (k < A.length() && A[k] == C) {
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


// Este programa busca en la cadena A una subcadena de tamaño m donde aparzezcan en mayor numero de caracteres C consecutivos
int main(int argc, char* argv[]){
    const int i = 0;                            // Indice que marca el inicio del String A
    const int m = 100;                           // Tamaño de las subcadenas solucion
    const char C = 'a';                         // Caracter que deber aparecer consecutivo
    
    long n = strtol(argv[1], nullptr, 10);
    
    string A = generarStringAleatorioConCaracteresLimitados(n,"a");

    string B = "hooola";
    
                      // Longuitud de la cadena A

    Data result = DyV_algorithm(A,i,n,m,C);

    //printf("Inicio=%d\nNº apariciones=%d\n",result.index+1,result.nOcu);

}


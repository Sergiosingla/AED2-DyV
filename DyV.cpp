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
    * string A -> string de entrada para anlizar
    *  i -> indice inicio de analisis de A
    *  n -> longuid del string a analizar
    *  C -> caracter que se desea buscar
    */
Data contarCcons(string A,int i, int n, int m, char C){

    Data res ={-1,0};   // Variable que se ira actualizando para almacenar la posible solucion

    int cont=0;         // Contador temporal de ocurrencias
    int index=-1;       // Indice de donde comienza la posible solucion

    for(int j=i;j<n+i ;j++){

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
    if (cont>0 && cont>res.nOcu) {               // En caso de que la subcadena analizada termine con C y estemos ante la mejor solucion, res no se actualizario
        res.nOcu=cont;          // por eso hacer falta actualizarlo aqui
        res.index=index;
    }
    return res;

}

// Función para combinar las soluciones y buscar una posible mejor solucion en la combinacion de ambas subpartes
    /*
    *  string A -> string de entrada para anlizar
    *  i -> indice de donde empieza 
    *  n -> longuid del string a analizar
    *  m -> longuitud de la subcadena a buscar
    *  C -> caracter que se desea buscar
    *  X -> mejor solucion de la primera subparte
    *  finX -> division de las dos subpartes
    *  Z -> mejor solucion de la segunda subparte
    */
Data combinar(string A, int i, int n, int m, char C, Data X, int finX, Data Z) {
    // Tomamos la mejor de las dos mitades como base
    Data res = (X.nOcu >= Z.nOcu) ? X : Z;

    // Indices de cada subparte
    int izq = finX - 1;
    int der = finX;

    // Contar caracteres C consecutivos hacia atrás desde la división
    int contadorIzq = 0;
    while (izq >= i && A[izq] == C && contadorIzq < m) {
        contadorIzq++;
        izq--;
    }

    // Contar caracteres C consecutivos hacia adelante desde la división
    int contadorDer = 0;
    while (der < i + n && A[der] == C && (contadorIzq + contadorDer) < m) {
        contadorDer++;
        der++;
    }

    int total = contadorIzq + contadorDer;

    // Solo considerar si hay una subcadena válida de tamaño m
    if (total > res.nOcu && total <= m) {
        int inicio = finX - contadorIzq;
        res = {inicio, total};
    }

    return res;
}
// Algoritmo encargado de dividir, combinar o solucionar de manera directa
    /*
    *  string A -> string de entrada para anlizar
    *  i -> indice inicio de analisis de A
    *  n -> longuid del string a analizar
    *  m -> longuitud de la subcadena a buscar
    *  C -> caracter que se desea buscar
    */
Data DyV_algorithm(string A, int i, int n, int m, char C){

    if(m<1){
        exit(1);
    }
    if(n<=m){    // Solucion directa
        return contarCcons(A,i,n,m,C);
    }
    else{           // Recursividad
        int div = n/2;
        return combinar(A,i,n,m,C,DyV_algorithm(A,i,div,m,C),i+div,DyV_algorithm(A,i+div,n-div,m,C));
    }

}


// Este programa busca en la cadena A una subcadena de tamaño m donde aparzezcan en mayor numero de caracteres C consecutivos aplicando la tecnica de Divide y Venceras
int main(int argc, char* argv[]){
    const int i = 0;                            // Indice que marca el inicio del String A
    const int m = 60;                           // Tamaño de las subcadenas solucion
    const char C = 'a';                         // Caracter que deber aparecer consecutivo
    
    //string C= generarStringAleatorioConCaracteresLimitados(n,"a");
    string A = string(50, 'x') + string(32, 'a') + string(40, 'x');
    string B = "xxxxaaaxxaaaaxxxx";
    long n = A.length();
    
                      // Longuitud de la cadena A

    Data result = DyV_algorithm(A,i,n,m,C);

    printf("Inicio=%d\nNº apariciones=%d\n",result.index+1,result.nOcu);

}


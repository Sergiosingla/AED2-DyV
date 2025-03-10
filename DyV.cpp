#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;


typedef struct dataStruct
{
    int index;
    int nOcu;
}Data;



Data DyV_algorithm(string A, int i, int n, int m, char C){

    if(m<1){
        exit(1);
    }
    if(n<=m){       // Solucion directa
        return contarCcons(A,i,n,C);
    }
    else{           // Recursividad
        int div = n/2;
        return combinar(A,n,m,C,DyV_algorithm(A,i,div,m,C),DyV_algorithm(A,i+div,n-div,m,C));
    }

}

Data contarCcons(string A,int i, int n, char C){
    int max=-1;
    int index_max=-1;
    int cont=0;
    int index=-1;

    for(i;i<i+n;i++){
        if(A[i]==C){
            cont++;
            if(cont==0){
                index=i;
            }
            if(cont>max){
                max=cont;
                index_max=index;
            }
        }
        else{
            cont=0;
        }
        
    }

}

Data combinar(string A, int n, int m, char C, Data X, Data Z){

}




int main(){
    const int i = 0;

    Data a;

}


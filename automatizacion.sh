#!/bin/bash

#file='FILENAME'    #Rellenar con el nombre de fichero para la salida
#rm $file

for n in {500..1000000..10000}; do
    echo "n=$n" >> $file
    # Tu comando aquí 
    ((time ./output/DyV $n) 2>&1 | grep "user" | cut -f2 | cut -f2 -d'm' | tr -d "s") >> $file
done


Data solucionDirecta(string A, char C){
    Data res = {-1,0};

    int cont = 0;
    int index = -1;

    for(int j=0;j<A.length();j++){
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
#!/bin/bash

#file='FILENAME'    #Rellenar con el nombre de fichero para la salida
#rm $file

for n in {500..1000000..10000}; do
    echo "n=$n" >> $file
    # Tu comando aquí 
    ((time ./output/DyV $n) 2>&1 | grep "user" | cut -f2 | cut -f2 -d'm' | tr -d "s") >> $file
done

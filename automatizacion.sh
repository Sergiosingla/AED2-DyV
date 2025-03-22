#!/bin/bash

rm time.txt

for n in {500..100000..500}; do
    echo "n=$n" >> time.txt
    for i in {1..5}; do
        # Tu comando aquí 
        ((time ./output/DyV $n) 2>&1 | grep "user" | cut -f2 | cut -f2 -d',' | tr -d "s") >> time.txt
        sleep 0.01
    done
done

python3 lector.py
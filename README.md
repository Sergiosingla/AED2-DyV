# AED2-DyV

Trabajo de practicas DyV de la asignatura Algoritmos y Estructuras de Datos 2 (AED-2) - Universidad de Murcia

Problema nº6:
6) Dada una cadena A de longitud n, un natural m  n y un carácter C, hay que
encontrar B, la subcadena de A de tamaño m con más apariciones
consecutivas del carácter C. Devolver el índice p de comienzo de la solución B
y el número de veces que aparece el C consecutivamente en B. En caso de
empate, será válida cualquiera de las soluciones óptimas.
Ejemplo: n=10, m=5, C=c
A= c d d a b c d a c c
Solución: B, posición de inicio igual a 6, y número de apariciones consecutivas
igual a 2.

Para ello hemos creado un programa capaz de resolver dicho problema aplicando DyV.

📦 DyV
├── DyV.cpp               # Codigo del algoritmo
├── automatizacion.sh     # Script bash para extracion de tiempo de ejecucion del algortimo para un n creciente (500-->1.000.000) y volcarlos en un txt
├── dibujarGraficas.py    # Scrpit de python para leer tiempos de un fichero txt y generar la grafica
|── Enunciado P1          # Enunciado Practicas
├── generadorString.cpp   # Funciones para generar caso de prueba para el algoritmo
├── README.md             # Este archivo
|── pseudo.txt            # Pseudo-codigo del algoritmo
├── .gitignore            # Archivos y carpetas a excluir de Git
├── tiempo*               # Graficas del tiempo de ejecucion del algoritmo
└── time*                 # Fichero .txt que almacenan los tiempos en funcion de n

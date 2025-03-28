# 📌 AED2-DyV

Trabajo de prácticas DyV de la asignatura Algoritmos y Estructuras de Datos 2 (AED-2) - Universidad de Murcia.

## 📖 Problema nº6

Dada una cadena A de longitud n, un natural m ≤ n y un carácter C, hay que encontrar B, la subcadena de A de tamaño m con más apariciones consecutivas del carácter C. 

Se debe devolver el índice p de comienzo de la solución B y el número de veces que aparece el C consecutivamente en B. En caso de empate, será válida cualquiera de las soluciones óptimas.

### 🔹 Ejemplo

**Entrada:**
```
n = 10, m = 5, C = c
A = c d d a b c d a c c
```
**Salida:**
```
B, posición de inicio igual a 6, y número de apariciones consecutivas igual a 2.
```

Para ello, hemos creado un programa capaz de resolver dicho problema aplicando el paradigma de Divide y Vencerás (DyV).

## 📂 Estructura del Proyecto

```
📦 DyV
├── DyV.cpp               # Código del algoritmo
├── automatizacion.sh     # Script Bash para extracción de tiempo de ejecución del algoritmo para un n creciente (500 → 1.000.000) y volcado en un archivo .txt
├── dibujarGraficas.py    # Script en Python para leer tiempos desde un archivo .txt y generar la gráfica
├── Enunciado_P1          # Enunciado de las prácticas
├── generadorString.cpp   # Funciones para generar casos de prueba para el algoritmo
├── README.md             # Este archivo
├── pseudo.txt            # Pseudocódigo del algoritmo
├── .gitignore            # Archivos y carpetas a excluir de Git
├── tiempo/               # Gráficas del tiempo de ejecución del algoritmo
└── time/                 # Archivos .txt que almacenan los tiempos en función de n
```

## 🚀 Instalación

Pasos para instalar el proyecto:

```bash
# Clonar el repositorio
git clone https://github.com/usuario/repo.git

# Ingresar al directorio del proyecto
cd repo

# Compilar el código (si aplica)
g++ -o DyV DyV.cpp
```

## 🛠 Uso

Instrucciones para ejecutar el proyecto:

```bash
./DyV
```

## 📊 Automatización y Gráficos

Para obtener y visualizar los tiempos de ejecución:

```bash
# Ejecutar la automatización
automatizacion.sh

# Generar gráficos
dibujarGraficas.py
```



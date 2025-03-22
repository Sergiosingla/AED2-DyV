

import re
import matplotlib.pyplot as plt
import numpy as np

def leer_tiempos(filename):
    tiempos = {}
    n_actual = None

    with open(filename, 'r') as file:
        for line in file:
            match_n = re.match(r'n=(\d+)', line)
            if match_n:
                n_actual = int(match_n.group(1))
                tiempos[n_actual] = []
            else:
                match_time = re.match(r'(\d+(\.\d+)?)', line)
                if match_time and n_actual is not None:
                    tiempos[n_actual].append(float(match_time.group(1)))  

    return tiempos

def main():
    filename = 'time.txt'
    tiempos = leer_tiempos(filename)

    ns = sorted(tiempos.keys())
    tiempos_promedio = [sum(tiempos[n]) / len(tiempos[n]) for n in ns]

    # Calcular funciones teóricas sin normalizar
    n_log_n = np.array(ns) * np.log2(np.array(ns))  # O(n log n)
    n_lineal = np.array(ns)  # O(n)

    # Graficar O(n) y O(n log n)
    plt.figure(figsize=(10, 6))
    plt.plot(ns, n_log_n, linestyle='--', color='r', label=r'$O(n \log n)$')
    plt.plot(ns, n_lineal, linestyle='--', color='g', label=r'$O(n)$')

    # Graficar los tiempos experimentales como puntos
    plt.scatter(ns, tiempos_promedio, color='b', label='Tiempos experimentales')

    plt.xlabel('n')
    plt.ylabel('Tiempo de ejecución (s)')
    plt.title('Comparación de tiempos con O(n) y O(n log n)')
    plt.legend()
    plt.grid(True)
    
    plt.savefig('tiempos_plot.png')
    plt.show()

if __name__ == "__main__":
    main()

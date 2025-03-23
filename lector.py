import re
import matplotlib.pyplot as plt
import numpy as np

def leer_tiempos(filename):
    tiempos = {}
    n_actual = None

    with open(filename, 'r') as file:
        for line in file:
            line = line.strip()
            match_n = re.match(r'n=(\d+)', line)
            if match_n:
                n_actual = int(match_n.group(1))
                tiempos[n_actual] = []
            else:
                line = line.replace(',', '.')  # Reemplazar coma por punto decimal
                match_time = re.match(r'(\d+(\.\d+)?)', line)
                if match_time and n_actual is not None:
                    tiempos[n_actual].append(float(match_time.group(1)))  # En ms

    return tiempos

def main():
    filename = 'time1M.txt'
    tiempos = leer_tiempos(filename)

    # Ordenar n y calcular tiempos promedio
    ns = sorted(tiempos.keys())
    tiempos_promedio = np.array([sum(tiempos[n]) / len(tiempos[n]) for n in ns])

    # Calcular funciones teóricas
    n_log_n = np.array(ns) * np.log2(np.array(ns))  # O(n log n)
    n_lineal = np.array(ns)  # O(n)

    # Ajuste automático del factor de escala
    factor_nlogn = 0.00000015
    factor_n = 0.00000015

    # Aplicar los factores de escalado
    n_log_n_scaled = n_log_n * factor_nlogn
    n_lineal_scaled = n_lineal * factor_n

    # Configurar la figura
    plt.figure(figsize=(12, 6))  

    # Graficar las funciones teóricas reescaladas
    plt.plot(ns, n_log_n_scaled, '--r', label=r'$O(n \log n)$ (reescalado)')
    plt.plot(ns, n_lineal_scaled, '--g', label=r'$O(n)$ (reescalado)')

    # Graficar los tiempos experimentales
    plt.scatter(ns, tiempos_promedio, color='b', label='Tiempos experimentales', zorder=3)

    # Etiquetas y leyenda
    plt.xlabel('Tamaño de entrada (n)')
    plt.ylabel('Tiempo de ejecución (s)')
    plt.title('Comparación de tiempos con O(n) y O(n log n)')
    plt.legend()
    plt.grid(True)

    # Guardar y mostrar
    plt.savefig('tiempos_plot.png')
    plt.show()

if __name__ == "__main__":
    main()

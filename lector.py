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
    time_M = 'time_M.txt'
    time_p = 'time_p.txt'
    tiempos_M = leer_tiempos(time_M)
    tiempos_p = leer_tiempos(time_p)

    # Ordenar n y calcular tiempos promedio
    ns_p = sorted(tiempos_p.keys())
    tiempos_promedio = np.array([sum(tiempos_p[n]) / len(tiempos_p[n]) for n in ns_p])

    ns_M = sorted(tiempos_M.keys())
    tiempos_peor = np.array([sum(tiempos_M[n]) / len(tiempos_M[n]) for n in ns_M])

    # Calcular funciones teóricas
    n_log_n = np.array(ns_M) * np.log2(np.array(ns_M))  # O(n log n)
    n_lineal = np.array(ns_M)  # O(n)

    # Ajuste automático del factor de escala utilizando la mediana
    factor_nlogn = np.mean(tiempos_promedio) / np.mean(n_log_n)
    factor_n = np.mean(tiempos_promedio) / np.mean(n_lineal)

    # Aplicar los factores de escalado
    n_log_n_scaled = n_log_n * factor_nlogn
    n_lineal_scaled = n_lineal * factor_n

    # Ajuste por mínimos cuadrados para tiempos_peor
    coef = np.polyfit(ns_M, tiempos_peor, 2)  # Ajuste polinómico de grado 2
    poly_fit = np.poly1d(coef)
    tiempos_peor_fit = poly_fit(ns_M)
    # Crear el plot
    plt.figure(figsize=(12, 6))
    plt.scatter(ns_p, tiempos_promedio, color='b', label='Tiempos promedio', zorder=3)
    plt.scatter(ns_M, tiempos_peor, color='m', label='Tiempos peor caso', zorder=3)
    #plt.plot(ns_M, tiempos_peor_fit, '-k', label='Ajuste por mínimos cuadrados')
    plt.xlabel('Tamaño de entrada (n)')
    plt.ylabel('Tiempo de ejecución (s)')
    plt.title('Comparación de tiempos con O(n) y O(n log n)')
    plt.legend()
    plt.grid(True)
    plt.savefig('tiempos.png')
    plt.show()

if __name__ == "__main__":
    main()

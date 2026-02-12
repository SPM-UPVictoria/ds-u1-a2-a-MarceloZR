#include <iostream>
#include <iomanip>
#include <cmath>
#include "Carga.hpp"
#include "Campo.hpp"

int main() {
    // Cambia este tipo si tu profe quiere probar con int, float, etc.
    typedef double T;

    const int FILAS = 10;
    const int COLS  = 10;

    // Constante simplificada
    const T k = (T)9.0;

    // Cargas de ejemplo (x, y, q). Puedes cambiar/añadir más.
    const int N = 3;
    Carga<T> cargas[N] = {
        Carga<T>(2, 2, (T) 5.0),
        Carga<T>(7, 7, (T)-3.0),
        Carga<T>(5, 1, (T) 2.0)
    };

    // Matriz estática 10x10
    T placa[FILAS][COLS];

    // Para evitar división entre cero cuando el punto coincide con una carga:
    // físicamente tendería a infinito, aquí usamos un epsilon chiquito.
    const T EPS = (T)0.5;

    // Calcular campo total en cada celda
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {

            T total = (T)0;

            for (int c = 0; c < N; c++) {
                int dx = i - cargas[c].getX();
                int dy = j - cargas[c].getY();

                T d = (T)std::sqrt((T)(dx * dx + dy * dy));

                if (d == (T)0) {
                    d = EPS;
                }

                total += calcularCampo<T>(k, cargas[c].getQ(), d);
            }

            placa[i][j] = total;
        }
    }

    // Imprimir matriz final (tabular)
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Campo electrico total (10x10)\n";
    std::cout << "k = " << k << " | Cargas: ";
    for (int c = 0; c < N; c++) {
        std::cout << "(" << cargas[c].getX() << "," << cargas[c].getY()
                  << ", q=" << cargas[c].getQ() << ")";
        if (c < N - 1) std::cout << ", ";
    }
    std::cout << "\n\n";

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << std::setw(8) << placa[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}

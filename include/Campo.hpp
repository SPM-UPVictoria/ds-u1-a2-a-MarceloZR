#ifndef CAMPO_HPP
#define CAMPO_HPP

// E = k * q / (d^2)
// Nota: d debe ser > 0. Si d == 0, el que llama debe manejar ese caso.
template <typename T>
T calcularCampo(T k, T q, T d) {
    return (k * q) / (d * d);
}

#endif

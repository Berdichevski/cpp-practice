#pragma once

struct LinearSystem {
    double** coefficients;
    double* constants;
    double* solution;
    int size;
    bool solveSystemKramer();
};
#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <array>
#include "Dims.h"


class Mandelbrot
{
public:
    Mandelbrot(double p_min_new=-2.25, double p_max_new=0.75, double q_min_new=-1.5, double q_max_new=1.5, int M_new=2, int K_new=150);
    ~Mandelbrot();
    void fixpunktIteration();
    void print();
    std::array<std::array<int,WIDTH>,HEIGHT> * getMatrix();

private:

    double p_min;
    double p_max;
    double q_min;
    double q_max;
    int M;
    int K;

    /*
    StandardWerte

    X-Achse
    const double p_min = -2.25;
    const double p_max = 0.75;

    //Y-Achse
    const double q_min= -1.5;
    const double q_max = 1.5;

    //Schwellenwert M
    const int M = 2;

    //max Iterationen K
    const int K = 150;*/

    const int rx = WIDTH;
    const int ry = HEIGHT;

    std::array<std::array<int,WIDTH>,HEIGHT> * matrix;

};

#endif // MANDELBROT_H

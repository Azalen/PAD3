#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <array>
#include <complex>
#include <iostream>
#include "datentyp.h"


class Mandelbrot {
private:

    // attributes

    std::array<std::array<unsigned int, cucks::AnzahlPixel>, cucks::AnzahlPixel>* arr;

public:

    // Object related

    Mandelbrot() {
        arr = new std::array<std::array<unsigned int, cucks::AnzahlPixel>, cucks::AnzahlPixel>();
    }

    ~Mandelbrot() {
        delete arr;
    }


    // Calcuates the pixelvalues for the selected part of the mandelbrotset
    void calculate(const double Rmin, const double Rmax, const double Imin, const double Imax, const unsigned int K, const unsigned int M) {

        const double RSw = (Rmax - Rmin) / (cucks::AnzahlPixel - 1);
        const double ISw = (Imax - Imin) / (cucks::AnzahlPixel - 1);

        for (int i = 0; i < cucks::AnzahlPixel; i++) {
            for (int j = 0; j < cucks::AnzahlPixel; j++) {

                unsigned int k = 0;
                std::complex<double> zOld = 0, z = 0;
                unsigned int erg = 0;
                std::complex<double> c = (Rmin + i * RSw) + (1i * (Imax - j * ISw));

                bool finished = false;
                while (k < K) {
                    zOld = z;
                    z = zOld * zOld + c;
                    k++;

                    if (abs(z) > M) { (*arr)[i][j] = k % 16 + 1; finished = true; break; }
                }
                if (!finished) (*arr)[i][j] = 0;
            }
        }

    }

    std::array<std::array<unsigned int, cucks::AnzahlPixel>, cucks::AnzahlPixel>* getMatrix() const { return arr; }


};

#endif // MANDELBROT_H

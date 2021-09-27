#ifndef BILD_H
#define BILD_H

#include "mandelbrot.h"
#include "colormap.h"
#include <string>
#include <fstream>
#include "farbe.h"

class Bild {
private:
    const std::string FILENAME = "bild.ppm";

public:
    Bild() {}

    void saveBild(const double Rmin, const double Rmax, const double Imin, const double Imax, const unsigned short K, const unsigned short M) {
        Mandelbrot m;
        const std::array<Farbe, 17> farbe = Colormap<17>::HOT.getMap();

        std::ofstream writer(FILENAME);
        writer << "P3\n" << std::to_string(cucks::AnzahlPixel) << " " << std::to_string(cucks::AnzahlPixel) << "\n255\n";

        m.calculate(Rmin, Rmax, Imin, Imax, K, M);

        const std::array<std::array<unsigned int, cucks::AnzahlPixel>, cucks::AnzahlPixel>* arr = m.getMatrix();

        for (unsigned int i = 0; i < cucks::AnzahlPixel; i++) {
            for (unsigned int j = 0; j < cucks::AnzahlPixel; j++) {
                const Farbe fa = farbe[(*arr)[j][i]];
                for (int f = 0; f < 3; f++) { // writes rgb vals

                    writer << std::to_string(fa[f]) << " ";

                }
            }
            writer << "\n";
        }

        writer.close();
    }
};

#endif // BILD_H

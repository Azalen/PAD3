#ifndef BILD_H
#define BILD_H

#include "mandelbrot.h"
#include "colormap.h"
#include <string>
#include "Dims.h"

class Bild
{
private:
    std::array<std::array<std::string,WIDTH>,HEIGHT> * image;
public:
    Bild();
    ~Bild();
    void matrixToImage(std::array<std::array<int,WIDTH>,HEIGHT> * matrix);
    void renderPPM();
};

#endif // BILD_H

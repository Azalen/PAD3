#include "bild.h"
#include <fstream>

Bild::Bild()
{
    image = new std::array<std::array<std::string,WIDTH>,HEIGHT>();
}

Bild::~Bild()
{
    delete image;
}

void Bild::renderPPM(){
    std::ofstream file;
    file.open("mandelbrot.ppm");

    file << "P3\n";
    file << WIDTH << " " << HEIGHT << "\n";
    file << "255\n";

    for(int np = 0; np < WIDTH; np++){
        for(int nq = 0; nq < HEIGHT; nq++){
            file << (*image)[np][nq];
        }
        file << "\n";
    }
    file.close();
}

void Bild::matrixToImage(std::array<std::array<int,WIDTH>,HEIGHT> * matrix){
    //Colormap cmap = Colormap::HOT;
    Colormap cmap("green");

    for(int np = 0; np < WIDTH; np++){
        for(int nq = 0; nq < HEIGHT; nq++){
            int index = (*matrix)[np][nq];
            //std::cout << index << " ";
            Farbe f = cmap.getFarbeAt(index);
            //std::cout << f << std::endl;
            (*image)[np][nq] = std::to_string(f.getRed()) + " " + std::to_string(f.getGreen()) + " " + std::to_string(f.getBlue()) + " ";
        }
    }
}

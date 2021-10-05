#ifndef COLORMAP_H
#define COLORMAP_H

#include "farbe.h"
#include <iostream>
#include <string>
#include <fstream>

const static int cmap_size = 17;

class Colormap
{
public:
    Colormap();
    Colormap(std::string s);
    static Colormap HOT;
    Farbe getFarbeAt(int i);
private:
    Farbe map[cmap_size];
    void hot();
};

#endif // COLORMAP_H

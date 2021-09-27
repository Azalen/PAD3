#ifndef COLORMAP_H
#define COLORMAP_H

#include <array>
#include <sstream>
#include "farbe.h"
#include <cmath>

const std::string HOT_STRING = "0.00000,0.00000,0.00000;0.16667,0.00000,0.00000;0.33333,0.00000,0.00000;0.50000,0.00000,0.00000;0.66667,0.00000,0.00000;0.83333,0.00000,0.00000;1.00000,0.00000,0.00000;1.00000,0.16667,0.00000;1.00000,0.33333,0.00000;1.00000,0.50000,0.00000;1.00000,0.66667,0.00000;1.00000,0.83333,0.00000;1.00000,1.00000,0.00000;1.00000,1.00000,0.25000;1.00000,1.00000,0.50000;1.00000,1.00000,0.75000;1.00000,1.00000,1.00000";


template<const int AnzahlFarben>
class Colormap {
private:

    // attributes

    std::array<Farbe, AnzahlFarben> map;

    // methods

    /// @brief Creates the map-array from a string
    void initFromString(const std::string& s) {
        const char COLOR_SEPARATOR = ';';
        const char VALUE_SEPARATOR = ',';

        std::stringstream ss(s);
        std::string data;

        for (int i = 0; i < AnzahlFarben; i++) {
            std::getline(ss, data, COLOR_SEPARATOR);

            float rf, gf, bf;

            std::string val;
            std::stringstream ss_val(data);

            for (int i = 0; i < 3; i++) {
                std::getline(ss_val, val, VALUE_SEPARATOR);
                switch (i) {
                case 0: rf = std::stof(val); break;
                case 1: gf = std::stof(val); break;
                case 2: bf = std::stof(val); break;
                default: throw std::invalid_argument("Error in Colormap::initFromString()");
                }
            }

            const int r = (int) round(255 * rf);
            const int g = (int) round(255 * gf);
            const int b = (int) round(255 * bf);

            map[i] = Farbe(r, g, b);
        }
    }

public:

    // Static

    static const Colormap<AnzahlFarben> DEFAULT;
    static const Colormap<AnzahlFarben> HOT;

    // Object related
    Colormap<AnzahlFarben>(const std::string& fromString) { initFromString(fromString); }

    const std::array<Farbe, AnzahlFarben>& getMap() const { return map; }
};

template<const int AnzahlFarben>
const Colormap<AnzahlFarben> Colormap<AnzahlFarben>::HOT(HOT_STRING);

#endif // COLORMAP_H

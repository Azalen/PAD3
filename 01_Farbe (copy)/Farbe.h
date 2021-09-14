#ifndef FARBE_H
#define FARBE_H

#include <iostream>
#include <iomanip>

class Farbe
{
private:
    short r, g, b, a;

    static short sichereEingabe(const std::string &);

public:
    // Objektunabhängige Klassen-Variablen
    static const short DEF_MIN      = 0;
    static const short DEF_MAX      = 255;
    static short       DEF_ALPHA;

    static const Farbe SCHWARZ, WEISS, ROT, BLAU, GRUEN;
    static Farbe GRAU;

    // Default-Konstruktor
    Farbe();
    // Standard-Konstruktor - Datentyp int gewählt um Implementierung mit short zu verschleiern
    Farbe(int, int, int, int);
    // Typumwandlungskonstruktor - unsigned int
    Farbe(unsigned int);

    // UTILITY
    unsigned int rgba() const;

    void eingabe();
    void ausgabe() const;

    static Farbe darker(const Farbe &);

    // GET & SET
    inline short getR() const { return r; }
    inline void setR(short r) { this->r = r; }
    inline short getG() const { return g; }
    inline void setG(short g) { this->g = g; }
    inline short getB() const { return b; }
    inline void setB(short b) { this->b = b; }
    inline short getA() const { return a; }
    inline void setA(short a) { this->a = a; }
    
};

bool operator==(const Farbe &, const Farbe &);
bool operator!=(const Farbe &, const Farbe &);

std::ostream & operator<<(std::ostream & ausgabe, const Farbe & f);


#endif
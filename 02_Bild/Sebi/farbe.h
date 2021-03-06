#ifndef FARBE_H
#define FARBE_H

#include "datentyp.h"
#include <iostream>

class Farbe
{
private:
    byte red;
    byte green;
    byte blue;
    byte alpha;

    static byte checkValue(int value);

public:
    static const Farbe WHITE;
    static const Farbe BLACK;
    static const Farbe RED;
    static const Farbe GREEN;
    static const Farbe BLUE;
    static const byte MAX_VAL = 255;
    static const byte MIN_VAL = 0;
    static const byte DEFAULT_RGB = 255;

    static byte DEFAULT_ALPHA;
    static Farbe GREYSCALE;
    static Farbe darker(const Farbe &f);
    friend bool operator<(const Farbe &f1, const Farbe &f2);

    Farbe(int r, int g, int b, int a = DEFAULT_ALPHA);
    Farbe(unsigned int rgba); //Typumwandlung
    Farbe();
    Farbe(double r, double g, double b, int a = DEFAULT_ALPHA);

    byte getRed() const;
    void setRed(int newRed);

    byte getGreen() const;
    void setGreen(int newGreen);

    byte getBlue() const;
    void setBlue(int newBlue);

    byte getAlpha() const;
    void setAlpha(int newAlpha);

    int rgba() const;
    void output() const;
    void input();

    Farbe darker() const;

    void operator=(const Farbe& f2);
    bool operator==(const Farbe& f2) const;
    bool operator!=(const Farbe& f2) const;
    bool operator<=(const Farbe& f2) const;
    bool operator>(const Farbe& f2) const;
    bool operator>=(const Farbe& f2) const;
    friend void operator--(Farbe& f,int); //Darker
    friend std::ostream & operator<<(std::ostream & ausgabe, const Farbe & f);
    friend void operator>>(std::istream & eingabe, Farbe & f);
};

#endif // FARBE_H

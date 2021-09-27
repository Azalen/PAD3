#ifndef FARBE_H
#define FARBE_H

#include <iostream>
#include "datentyp.h"


class Farbe {
private:

    // Object Attributes
    byte r, g, b, a;


    // Static Methods:

    static bool RGBAValuesAreOk(const int r, const int g, const int b, const int a) {
        if (r > (int) MAX_VAL || g > (int) MAX_VAL || b > (int) MAX_VAL || a > (int) MAX_VAL || r < (int) MIN_VAL || g < (int) MIN_VAL || b < (int) MIN_VAL || a < (int) MIN_VAL) return false;
        return true;
    }


public:

    // Static:

    constexpr static const byte MAX_VAL = 255;
    constexpr static const byte MIN_VAL = 0;
    constexpr static const byte DEFAULT_ALPHA = MAX_VAL;

    static const Farbe WHITE;
    static const Farbe BLACK;
    static const Farbe RED;
    static const Farbe GREEN;
    static const Farbe BLUE;
    static Farbe grey;


    // Static Methods:

    static Farbe eingabe() {
        std::cout << "Gib einen R-Wert ein: ";
        std::string eingabe_r;
        std::cin >> eingabe_r;
        const int r = std::stoi(eingabe_r);

        std::cout << "Gib einen G-Wert ein: ";
        std::string eingabe_g;
        std::cin >> eingabe_g;
        const int g = std::stoi(eingabe_g);

        std::cout << "Gib einen B-Wert ein: ";
        std::string eingabe_b;
        std::cin >> eingabe_b;
        const int b = std::stoi(eingabe_b);

        std::cout << "Gib einen A-Wert ein ('D' == default): ";
        std::string eingabe_a;
        std::cin >> eingabe_a;
        int a;
        if (eingabe_a[0] == 'D') a = DEFAULT_ALPHA;
        else a = std::stoi(eingabe_a);

        if (RGBAValuesAreOk(r, g, b, a)) return Farbe(r, g, b, a);
        else return Farbe();
    }

    static Farbe darker(const Farbe& f) { return f.darker(); }


    // Object related:

    Farbe(): r(0), g(0), b(0), a(DEFAULT_ALPHA) {}
    Farbe(const unsigned int rgba) {
        const unsigned int MAX_VAL = 256;
        unsigned int zw = rgba;

        unsigned int b = zw;
        while (b > MAX_VAL) b -= MAX_VAL;
        zw -= b;
        zw /= MAX_VAL;

        unsigned int g = zw;
        while (g > MAX_VAL) g -= MAX_VAL;
        zw -= g;
        zw /= MAX_VAL;

        unsigned int r = zw;
        while (r > MAX_VAL) r -= MAX_VAL;
        zw -= r;
        zw /= MAX_VAL;

        unsigned int a = zw;
        while (a > MAX_VAL) a -= MAX_VAL;

        if (!RGBAValuesAreOk(r, g, b, a)) throw std::invalid_argument("NEIN!");

        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;

    }
    Farbe(const byte& r, const byte& g, const byte& b, const byte& a = DEFAULT_ALPHA): r(r), g(g), b(b), a(a) {}


    const byte& R() const { return r; }
    const byte& G() const { return g; }
    const byte& B() const { return b; }
    const byte& A() const { return a; }

    unsigned int RGBA() const { return a*16777216 + r*65536 + g*256 + b; }

    Farbe darker() const {
        const float MULT_FACTOR = 0.7;

        return Farbe((unsigned short) r * MULT_FACTOR, (unsigned short) g * MULT_FACTOR, (unsigned short) b * MULT_FACTOR, a);
    }

    void ausgabe() const { std::cout << "R: " << (unsigned short) r << ", G: " << (unsigned short) g << ", B: " << (unsigned short) b << ", A: " << (unsigned short) a << std::endl; }

    void R(const byte& r) { if (RGBAValuesAreOk(r, MIN_VAL, MIN_VAL, MIN_VAL)) this->r = r; }
    void G(const byte& g) { if (RGBAValuesAreOk(MIN_VAL, g, MIN_VAL, MIN_VAL)) this->g = g; }
    void B(const byte& b) { if (RGBAValuesAreOk(MIN_VAL, MIN_VAL, b, MIN_VAL)) this->b = b; }
    void A(const byte& a) { if (RGBAValuesAreOk(MIN_VAL, MIN_VAL, MIN_VAL, a)) this->a = a; }

    friend bool operator<(const Farbe& f1, const Farbe& f2);

    Farbe operator--() { // Pre
        const Farbe f = darker();
        r = f.R();
        g = f.G();
        b = f.B();
        return f;
    }

    /// @brief Calls the darker function
    Farbe operator--(int) { // Post
        const Farbe f = *this;
        --(*this);
        return f;
    }

    int operator[](const int i) const {
        switch (i) {
        case 0: return (int) r;
        case 1: return (int) g;
        case 2: return (int) b;
        default: return -1;
        }
    }

};

const byte Farbe::MAX_VAL;
const byte Farbe::MIN_VAL;
const byte Farbe::DEFAULT_ALPHA;

const Farbe Farbe::WHITE = Farbe(MAX_VAL, MAX_VAL, MAX_VAL);
const Farbe Farbe::BLACK = Farbe(MIN_VAL, MIN_VAL, MIN_VAL);
const Farbe Farbe::RED = Farbe(MAX_VAL, MIN_VAL, MIN_VAL);
const Farbe Farbe::GREEN = Farbe(MIN_VAL, MAX_VAL, MIN_VAL);
const Farbe Farbe::BLUE = Farbe(MIN_VAL, MIN_VAL, MAX_VAL);
Farbe Farbe::grey = Farbe(128, 128, 128);


bool operator==(const Farbe& f1, const Farbe& f2) { return f1.RGBA() == f2.RGBA(); }

bool operator!=(const Farbe& f1, const Farbe& f2) { return !operator==(f1, f2); }

bool operator<=(const Farbe& f1, const Farbe& f2) { return operator<(f1, f2) || operator==(f1, f2); }

bool operator>(const Farbe& f1, const Farbe& f2) { return !operator<=(f1, f2); }

bool operator>=(const Farbe& f1, const Farbe& f2) { return !operator<(f1, f2); }


// Junge.... friend-Mechanismus zur Hölle
bool operator<(const Farbe& f1, const Farbe& f2) {
    if (f1.r < f2.r) return true;
    if (f1.r > f2.r) return false;
    if (f1.g < f2.g) return true;
    if (f1.g > f2.g) return false;
    if (f1.b < f2.b) return true;
    if (f1.b > f2.b) return false;
    if (f1.a < f2.a) return true;
    if (f1.a > f2.a) return false;
    return false;
}

std::ostream& operator<<(std::ostream& out, const Farbe& f) {
    return out << "R: " << (unsigned short) f.R() << ", G: " << (unsigned short) f.G() << ", B: " << (unsigned short) f.B() << ", A: " << (unsigned short) f.A();
}

void operator>>(std::istream& in, Farbe& f) { f = Farbe::eingabe(); }

#endif // FARBE_H

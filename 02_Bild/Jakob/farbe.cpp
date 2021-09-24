#include "farbe.h"
#include <iostream>

//---- Datenelemente ---


const Farbe Farbe::WHITE = Farbe(0);
const Farbe Farbe::BLACK = Farbe(255);
const Farbe Farbe::RED = Farbe(255,0,0);
const Farbe Farbe::GREEN = Farbe(0,255,0);
const Farbe Farbe::BLUE = Farbe(0,0,255);

byte Farbe::DEFAULT_ALPHA = Farbe::MAX_VAL;
Farbe Farbe::GREYSCALE = Farbe(128);

//---- Konstruktoren ----


Farbe::Farbe(int r, int g, int b, int a)
    //Eigentlich war eine Parameterliste gedacht, aber die Überprüfung muss ja vorher geschehen
{
    red = checkValue(r);
    green = checkValue(g);
    blue = checkValue(b);
    alpha = checkValue(a);
}

Farbe::Farbe()
    :red(MAX_VAL),green(MAX_VAL),blue(MAX_VAL),alpha(DEFAULT_ALPHA) //Wenn überhaupt keine Parameter übergeben werden -> Schwarz so wie Kilians Seele
{
}

Farbe::Farbe(unsigned int rgba)
{
    byte b = rgba%256;
    unsigned int tmp = rgba/256;
    byte g = tmp%256;
    tmp = rgba / 65536;
    byte r = tmp%256;
    tmp = rgba / 16777216;
    byte a = tmp%256;

    red = r;
    green = g;
    blue = b;
    alpha = a;

}

//---- Utility Functions ----


Farbe Farbe::darker(const Farbe &f)
{
    return f.darker();
}

byte Farbe::checkValue(int value)
{
    if(value < MIN_VAL || value > MAX_VAL){
        std::cout << "Value shall not exceed 255, nor be smaller than 0"<< std::endl;
        return DEFAULT_RGB;
    }
    return value;
}

int Farbe::rgba() const
{
    return alpha*16777216 + red*65536 + green*256 + blue;
}

void Farbe::output() const
{
    std::cout << "r: "<< (unsigned short)red << " g: " << (unsigned short)green << " b: " << (unsigned short)blue << " a: " << (unsigned short)alpha << std::endl;
}

void Farbe::input()
{
    byte in;

    std::cout << "Enter Red-Value: ";
    std::cin >> in;
    setRed(in);

    std::cout << "\n";
    std::cout << "Enter Green-Value: ";
    std::cin >> in;
    setGreen(in);

    std::cout << "\n";
    std::cout << "Enter Blue-Value: ";
    std::cin >> in;
    setBlue(in);

    std::cout << "\n";
    std::cout << "Enter Alpha-Value: ";
    std::cin >> in;
    setAlpha(in);
}

Farbe Farbe::darker() const
{
    Farbe darker(red*0.7,green*0.7,blue*0.7,alpha);
    return darker;
}


//---- Operatoren ----


bool Farbe::operator==(const Farbe& f2) const {
    if(this->getRed() == f2.getRed() && this->getGreen() == f2.getGreen() && this->getBlue() == f2.getBlue() && this->getAlpha() == f2.getAlpha())
        return true;
    else
        return false;
}

/*bool operator==(const Farbe& f1, const Farbe& f2){
    if(f1.getRed() == f2.getRed() && f1.getGreen() == f2.getGreen() && f1.getBlue() == f2.getBlue() && f1.getAlpha() == f2.getAlpha())
        return true;
    else
        return false;
}
*/

bool Farbe::operator!=(const Farbe& f) const  {
    return !(*this == (f));
}

bool operator <(const Farbe & t, const Farbe & x) {
    if(t.red < x.red) {
        return true;
    } else if( t.red < x.red) {
        return false;
    } else {
            if(t.green < x.green) {
                return true;
            } else if(t.green > x.green) {
                return false;
            } else {
                if(t.blue < x.blue) {
                    return true;
                } else if(t.blue > x.blue) {
                    return false;
                } else {
                    if(t.alpha < x.alpha) {
                        return true;
                    } else {
                        return false;
            }
        }
    }
}
}
std::ostream & operator<<(std::ostream & ausgabe, const Farbe & f)
{
    ausgabe << "r: "<< (unsigned short)f.red << " g: " << (unsigned short)f.green << " b: " << (unsigned short)f.blue << " a: " << (unsigned short)f.alpha << std::endl;
    return ausgabe;
}

void operator>>(std::istream & eingabe, Farbe & f) {
    f.input();
}

bool operator>(const Farbe & f, const Farbe & t) {
    return (!(f < t) && f != t);
}
bool operator<=(const Farbe & f, const Farbe & t) {
    return (f < t);
}
bool operator>=(const Farbe & f, const Farbe & t) {
    return (!(f < t));
}

//---- Getter & Setter ----


byte Farbe::getRed() const
{
    return red;
}

void Farbe::setRed(int newRed)
{
    red = checkValue(newRed);
}

byte Farbe::getGreen() const
{
    return green;
}

void Farbe::setGreen(int newGreen)
{
    green = checkValue(newGreen);
}

byte Farbe::getBlue() const
{
    return blue;
}

void Farbe::setBlue(int newBlue)
{
    blue = checkValue(newBlue);
}

byte Farbe::getAlpha() const
{
    return alpha;
}

void Farbe::setAlpha(int newAlpha)
{
    alpha = checkValue(newAlpha);
}

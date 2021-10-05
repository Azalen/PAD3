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

Farbe::Farbe(double r, double g, double b, int a){
    red = r*255;
    green = g*255;
    blue = b*255;
    alpha = a;
   // std::cout << (int)red << " " << (int)green << " " << (int)blue << std::endl;
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
    std::cout << this << std::endl;
}

void Farbe::input()
{
    std::cin >> *this;
}

Farbe Farbe::darker() const
{
    Farbe darker(red*0.7,green*0.7,blue*0.7,alpha);
    return darker;
}


//---- Operatoren ----

void Farbe::operator=(const Farbe& f2)
{
    this->setRed(f2.getRed());
    this->setGreen(f2.getGreen());
    this->setBlue(f2.getBlue());
    this->setAlpha(f2.getAlpha());
}

bool Farbe::operator==(const Farbe& f2) const
{
    if(this->getRed() == f2.getRed() && this->getGreen() == f2.getGreen() && this->getBlue() == f2.getBlue() && this->getAlpha() == f2.getAlpha())
        return true;
    else
        return false;
}

bool Farbe::operator!=(const Farbe& f2) const
{
    return !(*this==(f2));
}

bool Farbe::operator<=(const Farbe& f2) const
{
    return ((*this==(f2))&& *this<f2);
}

bool Farbe::operator>(const Farbe& f2) const
{
    return (!(*this<f2) && !(*this==f2) );
}

bool Farbe::operator>=(const Farbe& f2) const
{
    return !(*this<f2);
}

void operator--(Farbe &f, int){
    f = f.darker();
}

std::ostream & operator<<(std::ostream & ausgabe, const Farbe & f)
{
    ausgabe << "r: "<< (unsigned short)f.red << " g: " << (unsigned short)f.green << " b: " << (unsigned short)f.blue << " a: " << (unsigned short)f.alpha;
    return ausgabe;
}

void operator>>(std::istream & eingabe, Farbe & f)
{
    int in;

    std::cout << "Enter Red-Value: ";
    eingabe>>in;
    f.setRed(in);

    std::cout << "\n";
    std::cout << "Enter Green-Value: ";
    eingabe >> in;
    f.setGreen(in);

    std::cout << "\n";
    std::cout << "Enter Blue-Value: ";
    eingabe >> in;
    f.setBlue(in);

    std::cout << "\n";
    std::cout << "Enter Alpha-Value: ";
    eingabe >> in;
    f.setAlpha(in);
}


bool operator<(const Farbe &f1, const Farbe &f2) //lexikografischer Vergleich
{
    if(f1.red<f2.red){
        return true;
    }
    else if(f1.red>f2.red){
        return false;
    }
    else{
        if(f1.green<f2.green){
            return true;
        }
        else if(f1.green>f2.green){
            return false;
        }
        else{
            if(f1.blue<f2.blue){
                return true;
            }
            else if(f1.blue>f2.blue){
                return false;
            }
            else{
                if(f1.alpha<f2.alpha){
                    return true;
                }
                else if(f1.alpha>f2.alpha){
                    return false;
                }
                else{
                    return false;
                }
            }
        }
    }

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



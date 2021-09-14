#ifndef FARBE_CPP
#define FARBE_CPP

#include "Farbe.h"
#include <cmath>
#include <iomanip>

using namespace std;


        short Farbe::DEF_ALPHA = 255;

        const Farbe Farbe::SCHWARZ  = Farbe(DEF_MAX, DEF_MAX, DEF_MAX, DEF_ALPHA);
        const Farbe Farbe::WEISS    = Farbe(DEF_MIN, DEF_MIN, DEF_MIN, DEF_ALPHA);
        const Farbe Farbe::ROT      = Farbe(DEF_MAX, DEF_MIN, DEF_MIN, DEF_ALPHA);
        const Farbe Farbe::GRUEN    = Farbe(DEF_MIN, DEF_MAX, DEF_MIN, DEF_ALPHA);
        const Farbe Farbe::BLAU     = Farbe(DEF_MIN, DEF_MIN, DEF_MAX, DEF_ALPHA);

        Farbe Farbe::GRAU = Farbe(128, 128, 128, DEF_ALPHA);


Farbe::Farbe() : r(DEF_MIN), g(DEF_MIN), b(DEF_MIN), a(DEF_MAX) {}

Farbe::Farbe(int r, int g, int b, int a) {
    if(r < DEF_MIN || r > DEF_MAX)
        throw invalid_argument("Farbe(int,int,int,int) : Rotanteil nicht im korrekten Wertebereich");
    if(g < DEF_MIN || g > DEF_MAX)
        throw invalid_argument("Farbe(int,int,int,int) : Gruenanteil nicht im korrekten Wertebereich");
    if(b < DEF_MIN || b > DEF_MAX)
        throw invalid_argument("Farbe(int,int,int,int) : Blaueanteil nicht im korrekten Wertebereich");
    if(a < DEF_MIN || a > DEF_MAX)
        throw invalid_argument("Farbe(int,int,int,int) : Anpha nicht im korrekten Wertebereich");

    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

Farbe::Farbe(unsigned int rgba) {

    b = rgba % (unsigned int) pow(2,8);

    rgba = rgba / pow(2,8);
    g = rgba % (unsigned int) pow(2,8);

    rgba = rgba / pow(2,8);
    r = rgba % (unsigned int) pow(2,8);

    rgba = rgba / pow(2,8);
    a = rgba % (unsigned int) pow(2,8);
}

unsigned int Farbe::rgba() const{
    return a*pow(2,24) + r*pow(2,16) + g*pow(2,8) + b;
}

short Farbe::sichereEingabe(const string & farbe){
    short temp = 0;
    bool korrekteEingabe = true;

    do{
        cout << farbe << "anteil = ";
        cin >> temp;
        if(temp > Farbe::DEF_MAX || temp < Farbe::DEF_MIN){
            cout << "  " << farbe << "anteil nicht im korrekten Wertebereich" << endl;
            korrekteEingabe = false;
        }
        else{
            return temp;
        }
    }while(korrekteEingabe == false);
    return -1;
}

void Farbe::eingabe(){
    r = sichereEingabe("Rot");
    g = sichereEingabe("Gruen");
    b = sichereEingabe("Blau");
    a = sichereEingabe("Alpha");
}

void Farbe::ausgabe() const {
    cout << "R:" << setw(3) << r << "  G:" << setw(3) << g << "  B:" << setw(3) << b << "  A:" << setw(3) << a << endl;
}

Farbe Farbe::darker(const Farbe & toDarkenFrom) {
    return Farbe(toDarkenFrom.getR()*0.7, toDarkenFrom.getG()*0.7, toDarkenFrom.getB()*0.7, toDarkenFrom.getA());
}

bool operator==(const Farbe & left, const Farbe & right){
    if(left.getR() != right.getR())
        return false;
    if(left.getG() != right.getG())
        return false;
    if(left.getB() != right.getB())
        return false;
    if(left.getA() != right.getA())
        return false;
    return true;
}

bool operator!=(const Farbe & left, const Farbe & right) {
    return !(left == right);
}

ostream & operator<<(ostream & ausgabe, const Farbe & f){
    ausgabe << "R:" << setw(3) << f.getR() << "  G:" << setw(3) << f.getG() << "  B:" << setw(3) << f.getB() << "  A:" << setw(3) << f.getA();
    return ausgabe;
}

#endif
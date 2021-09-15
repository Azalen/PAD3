#include "farbe.h"

string Farbe::getName() const
{
    return name;
}

void Farbe::setName(const string &value)
{
    name = value;
}

unsigned short Farbe::getRot() const
{
    return rot;
}

void Farbe::setRot(unsigned short value)
{
    rot = value;
}

unsigned short Farbe::getGruen() const
{
    return gruen;
}

void Farbe::setGruen(unsigned short value)
{
    gruen = value;
}

unsigned short Farbe::getBlau() const
{
    return blau;
}

void Farbe::setBlau(unsigned short value)
{
    blau = value;
}

unsigned short Farbe::getTransparenz() const
{
    return transparenz;
}

void Farbe::setTransparenz(unsigned short value)
{
    transparenz = value;
}

bool operator== (const Farbe & x, const Farbe & y) {
    if(x.getRot() == y.getRot() && x.getGruen() == y.getGruen() && x.getBlau() == y.getBlau() && x.getTransparenz() == y.getTransparenz()) {
        return true;
    }
    return false;
}

const Farbe Farbe::SCHWARZ("schwarz",0,0,0);
const Farbe Farbe::ROT("rot",255,0,0);
const Farbe Farbe::WEIß("weiss",255,255,255);
const Farbe Farbe::BLAU("blau",0,0,255);
const Farbe Farbe::GRUEN("gruen",255,255,0);
const Farbe Farbe::GRAUTON("gratuon",128,128,128);

std::ostream & operator<<(std::ostream & ausgabe, const Farbe & f)
{
   ausgabe << setw(10) <<f.name << " -> (" << setw(3) << f.rot << "," << setw(3) << f.gruen << "," << setw(3) << f.blau << ")"  << " | T = " << setw(3) << f.transparenz << endl;
   return ausgabe;
}

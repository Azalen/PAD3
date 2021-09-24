#include "farbe.h"
#include <iomanip>
#include <iostream>

using namespace std;

const Farbe SIENNA  = Farbe(160, 82, 45, Farbe::DEFAULT_ALPHA);

int main(){

    cout << boolalpha << (Farbe::BLACK == Farbe::BLACK) << endl;
    cout << boolalpha << (SIENNA == Farbe::BLUE) << endl;

    cout << setw(15) << "Sienna - ";
    SIENNA.output();

    Farbe darkSienna = Farbe::darker(SIENNA);
    cout << setw(15) << "Dark Sienna - ";
    darkSienna.output();
    cout << setw(15) << "Schwarz - ";
    Farbe::BLACK.output();

    unsigned int sienna = SIENNA.rgba();

    // IMPLIZITE TYPUMWANDLUNG
    Farbe c = sienna;
    c.output();

    // EXPLIZITE TYPUMWANDLUNG
    cout << (Farbe) sienna << endl;
}

#include <iostream>
#include <iomanip>
#include "farbe.h"


using namespace std;

const Farbe SIENNA(160, 82, 45);

int main() {
    cout << boolalpha << (Farbe::BLACK == Farbe::BLACK) << endl;
    cout << boolalpha << (SIENNA == Farbe::BLUE) << endl;

    cout << setw(15) << "Sienna - ";
    SIENNA.ausgabe();

    Farbe darkSienna = Farbe::darker(SIENNA);
    cout << setw(15) << "Dark Sienna - ";
    darkSienna.ausgabe();
    cout << setw(15) << "Schwarz - ";
    Farbe::BLACK.ausgabe();

    unsigned int sienna = SIENNA.RGBA();

    // IMPLIZITE TYPUMWANDLUNG
    Farbe c = sienna;
    c.ausgabe();

    // EXPLIZITE TYPUMWANDLUNG
    cout << (Farbe) sienna << endl;

    return 0;
}

#include "Farbe.h"
#include <iomanip>

using namespace std;

const Farbe SIENNA  = Farbe(160, 82, 45, Farbe::DEF_ALPHA);

int main(){

    cout << boolalpha << (Farbe::SCHWARZ == Farbe::SCHWARZ) << endl;
    cout << boolalpha << (SIENNA == Farbe::BLAU) << endl;

    cout << setw(15) << "Sienna - ";
    SIENNA.ausgabe();

    Farbe darkSienna = Farbe::darker(SIENNA);
    cout << setw(15) << "Dark Sienna - ";
    darkSienna.ausgabe();
    cout << setw(15) << "Schwarz - ";
    Farbe::SCHWARZ.ausgabe();

    unsigned int sienna = SIENNA.rgba();
    
    // IMPLIZITE TYPUMWANDLUNG
    Farbe c = sienna;
    c.ausgabe();

    // EXPLIZITE TYPUMWANDLUNG
    cout << (Farbe) sienna << endl;
}
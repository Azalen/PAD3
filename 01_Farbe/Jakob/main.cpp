#include "farbe.h"
#include "farbvector.h"
int main()
{

/*    Farbvector test;

    test.insert("schwarz",0,0,0);
    test.insert("weiss",255,255,255);
    test.insert("rot",255,0,0);
    test.insert("blau",0,0,255);
    test.insert("gelb",255,255,0);
    test.insert("sienna",160,82,45);


    test.menue();
    */


#include <iomanip>

using namespace std;

    Farbe SIENNA  = Farbe("sienna",160, 82, 45);


    cout << boolalpha << (Farbe::SCHWARZ == Farbe::SCHWARZ) << endl;
    cout << boolalpha << (SIENNA == Farbe::BLAU) << endl;

    cout << setw(15) << "Sienna - ";
    SIENNA.ausgabe();

   Farbe darkSienna = Farbe::darker(SIENNA);
    cout << setw(15) << "Dark Sienna - ";
    darkSienna.ausgabe();
    cout << setw(15) << "Schwarz - ";
    Farbe::SCHWARZ.ausgabe();

    unsigned int sienna = SIENNA.RGBA();

    // IMPLIZITE TYPUMWANDLUNG
    Farbe c = sienna;
    c.ausgabe();

    // EXPLIZITE TYPUMWANDLUNG
    cout << (Farbe) sienna << endl;


    return 0;
}

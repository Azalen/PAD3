#include "farbe.h"
#include "mandelbrot.h"
#include "bild.h"
#include <iomanip>

using namespace std;

int main(){

    double p_min;
    double p_max;
    double q_min;
    double q_max;
    int M;
    int K;

    cout << "Eingabe X-Achse p_min: ";
    cin >> p_min;
    cout << "\n";
    cout << "Eingabe X-Achse p_max: ";
    cin >> p_max;
    cout << "\n";
    cout << "Eingabe Y-Achse q_min: ";
    cin >> q_min;
    cout << "\n";
    cout << "Eingabe Y-Achse q_max: ";
    cin >> q_max;
    cout << "\n";
    cout << "Eingabe Schwellenwert M: ";
    cin >> M;
    cout << "\n";
    cout << "Eingabe Iterationen K: ";
    cin >> K;
    cout << "\n";

    Mandelbrot m(p_min,p_max,q_min,q_max,M,K);
    //Für "Standard" Mandelbrot Werte einfach leeren Konstruktor aufrufen
    //Mandelbrot m;
    m.fixpunktIteration();
    Bild b;
    b.matrixToImage(m.getMatrix());
    b.renderPPM();
    return 0;
}

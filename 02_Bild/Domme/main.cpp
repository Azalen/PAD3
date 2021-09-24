#include <iostream>
#include <iomanip>
#include "farbe.h"

using namespace std;

// X-Achse
const float p_min = -2.25;
const float p_max = 0.75;

// Y-Achse
const float q_min = -1.5;
const float q_max = 1.5;

// Schwellenwert M
const unsigned int M = 2;

// max Iterationen K
const unsigned int K = 150;

const unsigned int hoehe = 500;   // Pixel
const unsigned int breite = 500;  // Pixel

int main(){

    Farbe f;
    cin >> f;
    cout << f << endl;
    f--;
    cout << f << endl;

}

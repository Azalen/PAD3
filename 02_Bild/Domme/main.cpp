#include <iostream>
#include <iomanip>
#include "farbe.h"
#include "bild.h"


// X-Achse
const double p_min = -2.25;
const double p_max = 0.75;

// Y-Achse
const double q_min = -1.5;
const double q_max = 1.5;

// Schwellenwert M
const unsigned int M = 2;

// max Iterationen K
const unsigned int K = 1000;


int main() {
    Bild b;

    b.saveBild(p_min, p_max, q_min, q_max, K, M);
    return 0;
}

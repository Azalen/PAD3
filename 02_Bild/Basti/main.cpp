#include "Bild.h"

using namespace std;

const int WIDTH  = 1000;
const int HEIGHT = 1000;

int main(){

    Mandelbrot m(WIDTH,HEIGHT);
    Bild b(WIDTH, HEIGHT);
    b.baueMandelbrot(m);
    b.toPPM("mandel_hot");

}
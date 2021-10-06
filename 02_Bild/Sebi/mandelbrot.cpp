#include "mandelbrot.h"
#include <iostream>
#include <complex>
#include <cmath>
#include <iomanip>



Mandelbrot::Mandelbrot(double p_min_new, double p_max_new, double q_min_new, double q_max_new, int M_new, int K_new)
    :p_min(p_min_new),p_max(p_max_new),q_min(q_min_new),q_max(q_max_new),M(M_new),K(K_new)
{
    matrix = new std::array<std::array<int,WIDTH>,HEIGHT>();
    std::cout << std::setprecision(12) << "Starte Rendering mit Werten: p_min: " << p_min << ", p_max: " << p_max << ", q_min: " << q_min << ", q_max: " << q_max << ", M: " << M << ", K: " << K << "\n";
}

Mandelbrot::~Mandelbrot()
{
   delete matrix;
}

std::array<std::array<int,WIDTH>,HEIGHT> * Mandelbrot::getMatrix(){
    return matrix;
}

void Mandelbrot::print(){
    for(int np = 0; np < rx; np++){
        for(int nq = 0; nq < ry; nq++){
            std::cout << std::setw(3) << (*matrix)[np][nq];
        }
        std::cout<<std::endl;
    }
}

void Mandelbrot::fixpunktIteration(){
    double delta_p = (p_max - p_min)/(rx -1);
    double delta_q = (q_max - q_min)/(ry-1);

    for(int np = 0; np < rx; np++){
        for(int nq = 0; nq < ry; nq++){

            int k = 0;
            double p = p_min + np * delta_p;
            double q = q_min + nq * delta_q;

            using namespace std::complex_literals;
            std::complex<double> c = p + (1i)*q; //1i aus complex
            std::complex<double> z = 0;

            while(true){
                z = z*z + c;


                if(k == K){
                    (*matrix)[nq][np] = 0;
                    break;
                }
                if(abs(z) > M){
                    (*matrix)[nq][np] = (k % 16)+1;
                    break;
                }
                k++;
            }

        }
    }

}

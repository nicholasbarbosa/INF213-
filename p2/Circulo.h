
#ifndef __Circulo_h
#define __Circulo_h

#include <iostream>
#include "FigBase.h"
using namespace std;

class Circulo : public FigBase {
    friend ostream& operator<< (ostream &, const Circulo &);
    friend istream& operator>> (istream &, Circulo &);

    private:
        double raio;

    public:
        Circulo(double x=1, double y=1, double r=1, int esp =1, int c=1, int t=1);


        double getRaio() const;
        void setRaio(double);


        float area() const;
        float perimetro() const;
        void imprime() const;
        void le();
};

#endif

#ifndef SEGMENTO_H
#define SEGMENTO_H

#include <iostream>
#include "FigBase.h"

using namespace std;

class Segmento : public FigBase{
    friend ostream& operator<< (ostream &, const Segmento &);
    friend istream& operator>> (istream &, Segmento &);

    
    private:
        double x2;
        double y2;

    public:
        Segmento(double x=1, double y=1, double x2=1, double y2=1, int esp=1, int c=1, int t=1);
        double getX2() const;
        void setX2(double);

        double getY2() const;
        void setY2(double);

        float area() const;
        float perimetro() const;

        void imprime() const;
        void le();
};

#endif
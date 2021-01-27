#ifndef __Retangulo_h
#define __Retangulo_h

#include <iostream>
#include "FigBase.h"
using namespace std;

class Retangulo: public FigBase {
    friend ostream& operator<< (ostream &, const Retangulo &);
    friend istream& operator>> (istream &, Retangulo &);

    private:
        //double x, y;     // canto inferior esquerdo
        double largura, altura;


    public:
        Retangulo(double x=1, double y=1, double larg =1, double alt =1, int esp =1, int c=1, int t=1);
        
        void setLargura(double);
        double getLargura() const;
        
        void setAltura(double);
        double getAltura() const;
        
        float area() const;
        float perimetro() const;
        void imprime() const;
        void le();
};

#endif

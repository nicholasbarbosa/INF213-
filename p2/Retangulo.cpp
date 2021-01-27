
#include "Retangulo.h"
#include <iostream>
using namespace std; 

Retangulo::Retangulo(double x, double y, double larg, double alt,int esp, int c, int t) 
                     : FigBase(x, y, esp, c, t){

    setLargura(larg);
    setAltura(alt);
}


double Retangulo::getLargura() const {
    return largura;
}

void Retangulo::setLargura(double larg) {
    largura = larg;
}
double Retangulo::getAltura() const {
    return altura;
}

void Retangulo::setAltura(double alt) {
    altura = alt;
}

float Retangulo::area() const {
    return altura * largura;     
}      
          
float Retangulo::perimetro() const {
    return 2*(largura + altura);      
}

void Retangulo::imprime() const {
    cout << "--- [Retangulo] ---" << endl;
    FigBase::imprime();
    cout << " largura = " << getLargura() << " altura = " << getAltura() << endl;  
    cout << " area = " << area() << " perimetro = " << perimetro() << endl; 
}

void Retangulo::le(){
    double larg, alt, x, y;
    int e, c, t;

    cin >> larg >> x >> alt >> y;
    cin >> e >> c >> t;

    FigBase::setX(x);
    FigBase::setY(y);
    FigBase::setEspessura(e);
    FigBase::setCor(c);
    FigBase::setTipo(t);
    this-> largura = larg;
    this-> altura = alt;
}

ostream& operator<< (ostream& out, const Retangulo& x){
    x.imprime();

    return out;
}

istream& operator>> (istream& in, Retangulo& x){
    x.le();

    return in;
}
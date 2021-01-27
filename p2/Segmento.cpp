#include "Segmento.h"
#include <cmath>

using std::cout;
using std::endl;

Segmento::Segmento(double x, double y, double x2, double y2,
                   int esp, int cor, int tipo)
                   : FigBase(x, y, esp, cor, tipo){
    setX2(x2);
    setY2(y2);
}

double Segmento::getX2() const{
    return x2;
}

void Segmento::setX2(double x2){
    this-> x2 = x2;
}

double Segmento::getY2() const{
    return y2;
}

void Segmento::setY2(double y2){
    this-> y2 = y2;
}

float Segmento::area() const{
    return 0;
}

float Segmento::perimetro() const{
        return sqrt((this-> x2 - FigBase::getX()*(this-> x2 - FigBase::getX()) +
               (this-> y2 - FigBase::getY())*(this-> y2 - FigBase::getY())));
}

void Segmento::imprime() const{
    cout << "--- [Segmento] ---" << endl;
    FigBase::imprime();
    cout << " x2 = " << getX2(); 
    cout << " y2 = " << getY2() << endl;
    cout << " area = " << area() << " perimetro = " << perimetro() << endl; 
}
void Segmento::le(){
    double x, x2, y, y2;
    int e, c, t;

    cin >> x2 >> x >> y2 >> y;
    cin >> e >> c >> t;

    FigBase::setX(x);
    FigBase::setY(y);
    FigBase::setEspessura(e);
    FigBase::setCor(c);
    FigBase::setTipo(t);
    this-> x2 = x2;
    this-> y2 = y2;
}

ostream& operator<< (ostream& out, const Segmento& x){
    x.imprime();

    return out;
}

istream& operator>> (istream& in, Segmento& x){
    x.le();

    return in;
}
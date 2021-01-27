#include <iostream>
#include "Horario.h"

using namespace std;

Horario::Horario(int h, int m, int s){
    this->setHora(h);
    this->setMin(m);
    this->setSeg(s);
}

void Horario::setHora(int h){
    if (h < 0)
        this->h = 0;
    else if(h > 24)
        this->h= 24;
    else this->h = h;
}

void Horario::setMin(int m){
    if (m < 0)
        this->m = 0;
    else if (m > 59)
        this->m = 59;
    else this->m = m;
}

void Horario::setSeg(int s){
    if (s < 0)
        this->s = 0;
    else if (s > 59)
        this->s = 59;
    else this->s = s;
}

int Horario::getHora() const{
    return this-> h;
}

int Horario::getMin() const{
    return this->m;
}

int Horario::getSeg() const{
    return this->s;
}

int Horario::compHorario(const Horario &x) const{
    int resp = this->difSegundos(x);

    if(resp > 0)
        return 1;
    else if(resp < 0)
        return -1;
    else 
        return 0;
}

int Horario::difSegundos(const Horario &x) const{
    int t1, t2;
    
    t1 = 0;
    t2 = 0;

    t1 += 3600 * this-> h;
    t1 += 60 * this-> m;
    t1 += this-> s;

    t2 += 3600 * x.h;
    t2 += 60 * x.m;
    t2 += x.s;

    return t1 - t2;
}

istream &operator>>(istream &in, Horario &obj){
    int auxh, auxm, auxs;

    in >> auxh >> auxm >> auxs;

    obj.setHora(auxh);
    obj.setMin(auxm);
    obj.setSeg(auxs);

    return in;
}


ostream &operator<<(ostream &out, const Horario &obj){
    int auxh, auxm, auxs;

    auxh = obj.getHora();
    auxm = obj.getMin();
    auxs = obj.getSeg();
    
    out << auxh << " " << auxm << " " << auxs;
    
    return out;
}
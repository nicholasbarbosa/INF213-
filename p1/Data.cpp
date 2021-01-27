#include <iostream>
#include "Data.h"

using namespace std;

Data::Data(int d, int m, int a){
    setDia(d);
    setMes(m);
    setAno(a);
}

/* como não tem alocação, nao precisa de construtor por cópia
Data::Data(const Data &x){
    setDia(x.d);
    setMes(x.m);
    setAno(x.a)
}
*/

void Data::setDia(int d){
    if (d < 1)
        this->d = 1;
    else if (d > 30)
        this->d = 30;
    else
        this->d = d;
    
}

void Data::setMes(int m){
    if (m < 1)
        this-> m = 1;
    else if (m > 12)
        this->m = 12;
    else 
        this->m = m;
        
}

void Data::setAno(int a){
    if(a < 2018)
        this->a = 2018;
    else if (a > 2020)
        this-> a = 2020;
    else
        this->a = a;
}

int Data::getDia()const{
    return this-> d;
}

int Data::getMes()const{
    return this-> m;
}

int Data::getAno()const{
    return this-> a;
}

int Data::compData(const Data &x)const{
    // para evitar repetição de código, usar difDias();
    int resp = 0;

    resp = this->difDias(x);

    if (resp > 0)
        return 1;
    else if (resp < 0)
        return -1;
    else
        return 0;
}

int Data::difDias(const Data &x)const{
    int d1, d2, dif;
    d1 = 0;
    d2 = 0;
    dif = 0;

    d1 += 365 * this-> a;
    d1 += 30 * this-> m;
    d1 += this-> d;

    d2 += 365 * x.a;
    d2 += 30 * x.m;
    d2 += x.d;

    dif = d1 - d2;

    return dif;
}

void Data::imprime()const{
    cout << this->d << "/" << this->m << "/" << this->a << endl;
}

//não const pois é a entrada de dados
istream &operator>>(istream &in, Data &obj){
    int auxd, auxm, auxa;

    in >> auxd >> auxm >> auxa;

    obj.setDia(auxd);
    obj.setMes(auxm);
    obj.setAno(auxa);

    return in;
}

ostream &operator<<(ostream &out, const Data &obj){
    int auxd, auxm, auxa;
    
    auxd = obj.getDia();
    auxm = obj.getMes();
    auxa = obj.getAno();

    out << auxd << " " << auxm << " " << auxa;
    
    return out;
}
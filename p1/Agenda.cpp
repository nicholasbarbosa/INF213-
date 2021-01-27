#include <iostream>
#include "Agenda.h"


using namespace std;

void Agenda::inserirItem(const ItemAgenda &i){
    this->a[this->j] = i;
    this->j ++;
}

void Agenda::compromissosData(const Data &d) const{
    for(int i=0; i<this->j; i++)    
        if(d.compData(this->a[i].getData()) == 0){
            cout << this->a[i].getHorario() << " " << this->a[i].getDesc() << endl;
        }
}

ItemAgenda::ItemAgenda(){
    setDesc("");
    setData(Data());
    setHorario(Horario());
}

ItemAgenda::ItemAgenda(const string &s, const Data &d, const Horario &h):d(d),h(h){
    this->setDesc(s);
}

ItemAgenda::ItemAgenda(const ItemAgenda &x){
    *this = x;
} 

void ItemAgenda::setDesc(const string &s){
    this->descricao = s;
}

void ItemAgenda::setData(const Data &d){
    this->d = d;
}

void ItemAgenda::setHorario(const Horario &h){
    this->h = h;
}

string ItemAgenda::getDesc() const{
    return this->descricao;
} 

Data ItemAgenda::getData() const{
    return this->d;
}

Horario ItemAgenda::getHorario() const{
    return this->h;
}
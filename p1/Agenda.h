#ifndef AGENDA_H
#define AGENDA_H
#include <iostream>
#include <cstring>
#include "Data.h"
#include "Horario.h"

using namespace std;

class ItemAgenda{
    public:
        ItemAgenda();
        ItemAgenda(const string &, const Data &, const Horario &);
        ItemAgenda(const ItemAgenda &);
        void setDesc(const string &);
        void setData(const Data &);
        void setHorario(const Horario &);
        string getDesc() const;
        Data getData() const;
        Horario getHorario() const;
    private:
        string descricao;
        Data d;
        Horario h;
};

class Agenda{
    public:
        void inserirItem(const ItemAgenda &);
        void compromissosData(const Data &)const;
    private:
        ItemAgenda a[1000];
        int j = 0;
};


#endif
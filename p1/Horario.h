#ifndef HORARIO_H
#define HORARIO_H
#include <iostream>

using namespace std;

class Horario{
    public:
        Horario(int h = 0, int m = 0, int s = 0);
        //Horario(const Horario &);
        void setHora(int);
        void setMin(int);
        void setSeg(int);
        int getHora() const;
        int getMin() const;
        int getSeg() const;
        int compHorario(const Horario &x) const;
        int difSegundos(const Horario &x) const;
        void imprime() const;
        friend ostream& operator<<(ostream &, const Horario&);
        friend istream& operator>>(istream &, Horario &);

    private:
        int h;
        int m;
        int s;
};

#endif
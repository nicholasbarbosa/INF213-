#ifndef DATA_H
#define DATA_H
#include <iostream>

using namespace std;

class Data {
    public:
        Data(int d = 1, int m = 1, int a = 2018); //construtor com argumentos padrões
        //Data(const Data &); //construtor por cópia. O argumento é const pois eh o objeto que sera copiado para o novo e ele nao pode ser modificado
        void setDia(int); //atribui o valor ao membro de dado
        void setMes(int);
        void setAno(int);
        int getDia() const; //retorna o valor
        int getMes() const;
        int getAno() const;
        int compData(const Data &) const;
        int difDias(const Data &) const;
        void imprime() const;
        friend ostream& operator<<(ostream &, const Data&);
        friend istream& operator>>(istream &, Data &);
		

    private:
        int d;
        int m;
        int a;
};

#endif
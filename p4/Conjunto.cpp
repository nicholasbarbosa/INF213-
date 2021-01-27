#include <iostream>
#include "Conjunto.h"

using namespace std;

template <class T>
Conjunto<T>::Conjunto(){
    tam_array = 10;
    num_elementos = 0;
    v = new T[tam_array];
}

template <class T>
Conjunto<T>::Conjunto( int n ) : tam_array(n){
    num_elementos = 0;
    v = new T[tam_array];
}

template <class T>
Conjunto<T>::Conjunto(const Conjunto<T> &other){
    v = new T[other.tam_array];
    tam_array = other.tam_array;

    for(int i = 0; i < other.num_elementos; i++)
        v[i] = other.v[i];
}

template <class T>
Conjunto<T>::~Conjunto(){
    delete[] v;
}

template <class T>
Conjunto<T> & Conjunto<T>::operator=(const Conjunto<T> &other){
    if(&other == this) return *this;

    delete[] v;

    tam_array = other.tam_array;
    v = new T[tam_array];

    for(int i = 0; i < num_elementos; i++)
        v[i] = other.v[i];
    
    return *this;
}

template <class T>
bool Conjunto<T>::operator==(const Conjunto<T> &other) const{
    if(num_elementos != other.num_elementos) return false;

    for(int i = 0; i < num_elementos; i++)
        if(v[i] != other.v[i])
            return false;
    
    return true;
}

template <class T>
bool Conjunto<T>::pertence(const T n) const{
    for(int i = 0; i < num_elementos; i++)
        if(v[i] == n) 
            return true;

    return false;
}

template <class T>
bool Conjunto<T>::insere(T n){
    if(pertence(n)) return false;
    else if(num_elementos == tam_array) return false;

    for(int i = 0; i < num_elementos; i++)
        if(v[i] == n) return false;
    
    num_elementos += 1;
    
    v[num_elementos] = n;

    return true;
}

template <class T>
int Conjunto<T>::numelementos() const{
    return numelementos;
}

template <class T>
ostream &operator<<(ostream &out, const Conjunto<T> &other){
    for(int i = 0; i < other.num_elementos; i++)
        out << other.v[i] << endl;
    
    return out;
}

template <class T>
istream &operator>>(istream &in, Conjunto<T> &other){
    for(int i = 0; i < other.tam_array; i++)
        in >> other.tam_array[i];
    
    return in;
}
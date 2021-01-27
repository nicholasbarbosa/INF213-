#include <iostream>
#include "MyList2NewIterator.h"
using namespace std;

template <class T>
void reverse(MyList2<T> &lista) {
    MyList2<int>::iterator it = lista.begin();
    MyList2<int>::iterator it2 = lista.begin();

    int cont = 0;
    T aux;
    
    while( it != lista.end() ){
        it ++;
        cont ++;
        if(it != lista.end()) it2 ++;  //it2 vai apontar para o ultimo elementos 
    }

    if(it == lista.end())it --;
    cout << *it << endl;
    it = lista.begin(); //o it tava apontando ppra end()
        
    for(int i = 0; i < cont/2; i++){
        aux = *it;
        *it = *it2;
        *it2 = aux;

        it ++;
        it2 --;
    } 

}

int main(){
    MyList2<int> v;
	for(int i=0;i<4;i++) {
		v.push_back(i);
	}
    cout << v << endl;
    cout << v;
    reverse(v);
    cout << v;
    
    return 0;
}
#include <iostream>
using namespace std;

#include "FigBase.h"
#include "Retangulo.h"
#include "Circulo.h"
#include "Segmento.h"

int main(){
    Circulo c;
    Circulo c1;
    Retangulo r;
    Segmento s; 
    Segmento s1;
    

    FigBase *fPtr[5];

    fPtr[0] = &c;
    fPtr[1] = &c1;
    fPtr[2] = &r;
    fPtr[3] = &s;
    fPtr[4] = &s1;
    
    
    for(int i = 0; i < 5; i ++){
        fPtr[i]->ler();
        cout << endl;
    }

    for(int i = 0; i < 5; i ++){
        fPtr[i]->imprime();

        Circulo *cPtr = dynamic_cast < Circulo* >( fPtr[ i ] ); 

        if (cPtr != 0){
            cPtr->setRaio(2 * cPtr->getRaio());
            cout << "Com o raio dobrado, temos:" << endl;
            cPtr->imprime();
        }
    }

    return 0;
}
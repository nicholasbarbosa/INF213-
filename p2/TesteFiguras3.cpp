/* --------------- Arquivo|: TestaFiguras3.cpp -----------------
Testa as classes Retangulo, Circulo e Segemento usando heranca.

Inclui o teste das sobrecarga dos operadores >> e <<

Criado por Marcus V. A. Andrade - 21/03/2016
Atualizado por Marcus V. A. Andrade - 21/03/2016
*/

#include <cstdlib>
#include <iostream>
#include "Circulo.h"
#include "Retangulo.h"
#include "Segmento.h"

using namespace std;

int main(int argc, char *argv[]) {
    Retangulo r;
    Circulo c;
    Segmento s;
    Retangulo x;
    
    cin >> r;
    cout << "\n";
    cout << r << endl;

    FigBase *fPtr = &r;
    fPtr->imprime();

    Retangulo *rPtr = &r;
    rPtr->imprime();

    Retangulo *r2Ptr = &x;
    r2Ptr->imprime();
    

    return 0;
}


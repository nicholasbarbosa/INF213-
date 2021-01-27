#include <iostream>
using namespace std;

#include "FigBase.h"
#include "Retangulo.h"
#include "Circulo.h"
#include "Segmento.h"

int main() {

    Retangulo r(13, 7, 2, 4, 1, 1, 1);
    Circulo c(5, 2, 4, 2, 2, 2);
    Segmento s(3, 7, 8, 5, 3, 3, 3);

    r.imprime();
    c.imprime();
    s.imprime();

    cout << "-----------------------------------\n";
    cout << "           Usando apontadores      \n";
    cout << "-----------------------------------\n";

    FigBase *p[3];

    p[0]=&r;
    p[1]=&c;
    p[2]=&s;

    int i;
    for (i=0; i < 3; i++) {
       p[i]->imprime();
       cout << "-----------------------------------\n";
    }

    return 0;

} // fim de main


/* -----------------------------------------------------
                  RESULTADO ESPERADO
   -----------------------------------------------------

--- [Retangulo] ---
 Atributos da linha:
     Espessura = 1
     Cor       = 1
     Tipo      = 1
 x = 13 y = 7

 largura=2 altura=4
 area = 8 perimetro = 12

--- [Circulo] ---
 Atributos da linha:
     Espessura = 2
     Cor       = 2
     Tipo      = 2
 x = 5 y = 2

 raio=4
 area = 50.2655 perimetro = 25.1327

--- [Segmento] ---
 Atributos da linha:
     Espessura = 3
     Cor       = 3
     Tipo      = 3
 x = 3 y = 7

 x2 = 8 Y2 = 5
 area = 0 perimetro = 5.38516

-----------------------------------
           Usando apontadores
-----------------------------------
 Atributos da linha:
     Espessura = 1
     Cor       = 1
     Tipo      = 1
 x = 13 y = 7

-----------------------------------
 Atributos da linha:
     Espessura = 2
     Cor       = 2
     Tipo      = 2
 x = 5 y = 2

-----------------------------------
 Atributos da linha:
     Espessura = 3
     Cor       = 3
     Tipo      = 3
 x = 3 y = 7

-----------------------------------


*/

/*
os apontadores so usam a função da figbase, pq, apesar de estarem apontados para classes derivadas, o apontador eh da classe base
então ele so chama funções que ele conhecem, ou seja, funções da classe basica.
para resolver este problema deve-se usar polimorfismo, onde declaramos as funções da classe base como virtuais
e elas podem ser usadas por toda hierarquia das heranças, sendo osbrescritas para função correta.
*/

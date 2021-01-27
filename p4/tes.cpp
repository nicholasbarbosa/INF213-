#include <iostream>
#include "Conjunto.h"

using namespace std;

int main(){
    Conjunto<int> A(5), B(12);

    cin >> A >> B;
    cout << A << endl;
    cout << B << endl;


    return 0;
}
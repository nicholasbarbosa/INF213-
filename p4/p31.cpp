#include <iostream>
#include "Conjunto2.h"

using namespace std;

int main(){

    int n;

    cin >> n;

    Conjunto<int> A(n), B(n);

    for(int i = 0; i < n; i++){
        A.insere(i + 1);
        B.insere(i + 1);
    }
    Conjunto<int> C = A + B;

    cout << C.pertence(10) << endl;

    return 0;
}
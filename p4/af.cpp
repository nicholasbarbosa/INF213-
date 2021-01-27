#include <iostream>
#include "Conjunto2.h"

using namespace std;

int main(){
    Conjunto<int> a(5);
    Conjunto<int> b(10);
    Conjunto<int> c(10);
    cin >> a >> b;

  //  cout << a << endl;
    cout << a << b << endl;
  


    Conjunto<int> d = a + b;
    cout << a - b << endl;
    cout << d << endl;

    return 0;
}
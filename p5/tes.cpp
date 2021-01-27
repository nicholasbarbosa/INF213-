#include <iostream>
#include <cassert>
#include "MyVec.h"
using namespace std;

int main(){
    MyVec<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    cout << a << endl;
    cout << a.eraseMatchingElements('b') << endl;
    a.sortedInsert(3);
    
    cout << a << endl;
    return 0;
}
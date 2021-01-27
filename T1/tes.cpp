#include <iostream>
#include "MyMatrix.h"
using namespace std;




int main() {
    int v[] = {1, 3, 2, 2};
    MyMatrix<int> a(4, v, false);
    a.set(0,0,1);
    a.set(1,0,2);
    a.set(1,1,3);
    a.set(1,2,4);
    a.set(2,0,0);
    a.set(2,1,0);
    a.set(3,0,5);
    a.set(3,1,6);
    a.print();
    a.resizeRow(1,2);
    a.print();
    a.resizeRow(0,0);
    a.print();
    a.resizeRow(3,0);
    a.print();
    cout << "-----------" << endl;
    a.resizeRow(0,1);
    a.resizeRow(1,3);
    a.resizeRow(3,2);
    a.set(0,0,1);
    a.set(3,0,5);
    a.set(3,1,6); 
    a.set(1,2,4);
    a.print();
    cout << "-----------" << endl;
    a.resizeRow(1,2);
    a.print();
    a.resizeRow(0,0);
    a.print();
    a.resizeRow(3,0);
    a.print();
    return 0;
}

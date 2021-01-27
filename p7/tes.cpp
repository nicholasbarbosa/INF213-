#include <iostream>
#include "MyList2.h"
using namespace std;

int main(){
    MyList2<int>x;
   
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);
    x.push_back(6);
    cout << x;
    cout << x.size() << endl;
     x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);
    x.push_back(6);
    cout << x;
    cout << x.size() << endl;

  
    return 0;
}
#include <iostream>
#include <cstring>
#include "MyStack.h"
#include "MyQueue.h"
#include "MyQueue2.h"

using namespace std;

int main(){
    MyQueue<int> p1;
    MyQueue2<int> p2;

    for(int i = 0; i < 4; i ++){
        p1.push(i);
        p2.push(i);
    }
    for(int i = 0; i < 4; i ++){
        cout << p1.front() << " pilha1" << endl;
        p1.pop();
    }

    for(int i = 0; i < 4; i ++){
        cout << p2.front() << " pilha2" << endl;
        p2.pop();
    }
}
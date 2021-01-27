#include <iostream>
#include "MyMap.h"
#include "MyVecNewIterator.h"
#include <cstring>

using namespace std;

int main(){
    MyMap<string, int> dic;
    int cont = 0;
    int inicializa = -1;
    string str;
    
    while(cin>>str){
        pair<string,int> a = make_pair(str,inicializa);

        dic.insert(a);
        
        if(dic[str] == -1){
            dic[str] = cont;
            cont ++;

        }/*
        if(dic.size() == 0) {
            dic.insert(a);
            dic[str] = 0;
        }
        else{
            dic.insert(a);
            if(dic[str] == -1){
                dic[str] = cont;
                cont ++;
            }
        }*/

        cout << str << " " << dic[str] << endl;
    }



    return 0;
}
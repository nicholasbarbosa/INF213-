#include <iostream>
#include "MySet.h"
#include "MyVecNewIterator.h"
#include <cstring>

using namespace std;

int main( int argc, char *argv[ ] ){
    string arg = argv[1];
    if(arg == "myset"){ 
        int cont=0;
        string str;
        MySet<string> palavras;
        while(cin>>str){
            cont ++;
            palavras.insert(str);
        }

        cout << cont << " " << palavras.size() << endl;
    }
    else if(arg == "myvec"){
        int cont = 0;
        string str;
        MyVec<string> palavras;
        
        while(cin>>str){
            bool insere = true;
            cont ++;
            if(palavras.size() == 0) palavras.push_back(str);

            for(int i = 0; i < palavras.size(); i ++) 
                if(palavras[i] == str ) {insere = false; break;}

            if(insere) palavras.push_back(str);
        }

        cout << cont << " " << palavras.size() << endl;
    }
    return 0;
}
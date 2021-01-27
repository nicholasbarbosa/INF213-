#include "MyHashMap.h"
#include "MyVecNewIterator.h"
#include <string>
#include <iostream>

using namespace std;
//cpf tem 9 digitos + 2 digitos de verificação que serão calculados pela tabela hash

void hash1( string& cpf){
    //primeiro digito
    int s = 0;
    for(int i = 0; i < cpf.size(); i ++){
        s += (cpf[i] - '0') * (10-i);
    }
    s = (10 * s) % 11;
    auto aux =to_string(s);

    if(aux == "10") cpf += '0';
    else cpf += aux;

    s = 0;
    for(int i = 0; i < cpf.size(); i ++){
        s += (cpf[i] - '0') * (11-i);
    }
    s = (10 * s) % 11;
    aux =to_string(s);

    if(aux == "10") cpf += '0';
    else cpf += aux;

}

int main(){
    int n;
    cin >> n;

    MyVec<string> cpf;
    string num;

    for(int i = 0; i < n; i ++) {
        cin >> num;
        cpf.push_back(num);
    }

    for(int i = 0; i < n; i ++){
        hash1(cpf[i]);

        cout << cpf[i][cpf[i].size()-2] << cpf[i][cpf[i].size()-1] << endl;
    }
    return 0;
}
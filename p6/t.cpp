#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstring>
#include <algorithm>
#include <stdio.h> 
#include <stdlib.h>
using namespace std;

int main(){
    vector<map<pair<int,int>,int>> a;

    pair<int,int> b = make_pair(1,1);

    map<pair<int,int>,int> a1;
    for(int i = 0; i < 8; i++){
        a1[b] = i;
        b = make_pair(i+2, i+4);
        a.push_back(a1);
    }

    vector<int> maiores;
    int maior = a[0].begin()->second;

    for(int i = 0; i < a.size(); i ++){
        for(map<pair<int,int>,int>::iterator it = a[i].begin(); it != a[i].end(); it ++){
            if(it->second > maior) maior = it->second;
        }
        maiores.push_back(maior);
    }
    int menor = maiores[0];
    for(int i = 1; i < maiores.size(); i ++){

        if(menor > maiores[i]) menor = maiores[i]; 
    }

    cout << menor << endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int f( const map<string,double> & m1 ){
    int media = 0;
    for(map<string,double>::const_iterator it = m1.cbegin(); it != m1.end(); it ++){
        media += it->second;
    }

    return media/m1.size();
}

int f2( const map<string, double>& m1 ){
    int media = 0;
    for(auto elem:m1) media += elem.second;

    return media/m1.size();
}

int f3( const map<string, double>& m1 ){
    int media = 0;
}

int main(){
    map<string,double> m1;
    m1["a"] = 10;
    m1["b"] = 20;
    m1["c"] = 30;
    m1["d"] = 40;
    m1["e"] = 50;

    cout << f(m1) << " " << f2(m1) << endl;
    return 0;
}
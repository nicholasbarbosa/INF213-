#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand((unsigned)time(0));
    int n = rand()%10;
    if (n > 4) cout << "sim" << endl;
    else cout << "nao" << endl;
    return 0;
}
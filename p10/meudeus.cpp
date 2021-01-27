#include <iostream>
#include "Mediana.h"
using namespace std;

int main(){
   Mediana mediana;

	int n,elem;	
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> elem;
		mediana.insere(elem);
		cout << mediana.getMediana() << " ";
	}
	cout << endl;
    return 0;
}
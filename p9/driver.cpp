#include <iostream>
#include <string.h>
#include "MyStack.h"
#include "MyQueue.h"
#include "MyQueue2.h"
using namespace std;


// Insira aqui o codigo para a etapa 1....

//Voce pode adicionar includes como o abaixo...
//#include "MyStack.h"


void etapa1() {
	

	MyStack<int> pilha;
	MyQueue<int> fila;
	int elem;

	for(int i = 0; i < 6; i ++){
		cin >> elem;

		pilha.push(elem);
		fila.push(elem);
	}

	for(int i = 0; i < 6; i ++){
		cout << pilha.top() << " ";		//fala o elemento no top da pilha;
		pilha.pop();					//retira o elemento do topo da pilha
	}
	cout << endl;

	for(int i = 0; i < 6; i ++){
		cout << fila.front() << " ";		//fala o elemento de maior prioridade da fila;
		fila.pop();					//retira o elemento de maior prioridade da fila;
	}
	cout << endl;
}

//---------------------------------------

// Insira aqui o codigo para a etapa 2....

void etapa2() {
	MyStack<char> pilha;

	char c;

	while (cin >> c){
		if( c == '(' || c == '[' || c == '{' ) pilha.push(c);
		else if( c == ')'){
			if(pilha.empty() || pilha.top() != '('){cout << "Inconsistente" << endl; return;}
			else pilha.pop();
		}
		else if( c == '}'){
			if(pilha.empty() || pilha.top() != '{'){cout << "Inconsistente" << endl; return;}
			else pilha.pop();
		}
		else if( c == ']'){
			if(pilha.empty() || pilha.top() != '['){cout << "Inconsistente" << endl; return;}
			else pilha.pop();
		}

	}

	if(pilha.empty()) cout << "Consistente" << endl;
	else cout << "Inconsistente" << endl;
	
}

//---------------------------------------

// Na etapa 3 voce deve implementar MyQueue2.h e descomentar os codigos de teste abaixo...


//#include "MyQueue2.h"
void etapa3() {
	char operacao;
	MyQueue2<string> q;

	//le um arquivo contendo "comandos" para a fila e aplica-os a fila criada com sua classe...
	while(cin>> operacao) {
		if(operacao=='p') {
			string st;
			cin >> st;
			q.push(st); //insere um novo elemento na sua fila...
		} else if(operacao=='f') {
			cout << q.front() << "\n";
		} else if(operacao=='P') {
			q.pop();
		} else if(operacao=='e') {
			cout << ((q.empty())?"vazia":"cheia") << "\n";
		} else cout << q.size() << "\n";
	}	
}

//---------------------------------------

// Insira aqui o codigo para a etapa 4....


void etapa4() {
	int n;
	cin >> n;
	int x[n + 1];
	x[0] = n;
	
	for(int i = 1; i <= n; i ++){
		cin >> x[i];
	}

	int tam = x[0];
	int cont = x[1] + 1;
	bool flag = true;
	MyStack<int> s;

	for(int i = 1; i <= cont - 1; i++) s.push(i);

	for(int i = 2; i <= tam; i ++){
		if( cont <= x[i]){
			while(cont <= x[i]){
				s.push(cont);
				cont ++;
			}
		}
		if(s.empty()!=true && s.top() >= x[i]){
			while(s.empty()!=true && s.top() >= x[i]) s.pop();
		}
		else{
			flag = false;
		}
	}

	if(flag) cout << "SIM" << endl;
	else cout << "NAO" << endl;
}

//---------------------------------------


int main() {
	int etapa;
	cin >> etapa;
	switch(etapa) {
		case 1:
			cout << "Etapa 1" << endl;
			etapa1();
			break;
		case 2:
			cout << "Etapa 2" << endl;
			etapa2();
			break;
		case 3:
			cout << "Etapa 3" << endl;
			etapa3();
			break;
		case 4:
			cout << "Etapa 4" << endl;
			etapa4();
			break;
	}
}
#include <iostream>
#include "MyVec.h"
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


class ArvoreExpressao {
public:
	void imprimeArrays() const;
	void leArvore();
	void imprimeExpressao() const;
	int avaliaValor() const;
	int altura() const;
	int nivelMaisNodos() const;

private:
	//Nao adicione nenhum membro de dados na sua classe!!!!
	//Funcoes auxiliares podem ser adicionadas se necessario.
    void imprimeExpressao(int) const;
    int avaliaValor(int) const;
    int altura(int pos) const;
    void nivelMaisNodos(int pos, int *vec, int nivel) const;
	MyVec<int> filhoEsquerdo;
	MyVec<int> filhoDireito;
	MyVec<char> operador;
	int operate(int a, int b, char opr) const;
};

void ArvoreExpressao::imprimeArrays() const {
	for(int i=0;i<filhoEsquerdo.size();i++) cout << i << " "; cout << "\n";
	for(int i=0;i<filhoEsquerdo.size();i++) cout << filhoEsquerdo[i] << " "; cout << "\n";
	for(int i=0;i<filhoDireito.size();i++) cout << filhoDireito[i] << " "; cout << "\n";
	for(int i=0;i<operador.size();i++) cout << operador[i] << " "; cout << "\n";
}

/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/
//sua implementacao:


void ArvoreExpressao::leArvore() {
	int v;
	int fleft, frigth;
	int pos;
	char c;

	cin >> v;

	for(int i = 0; i < v; i ++){
		cin >> pos >> fleft >> frigth >> c;
		filhoEsquerdo.push_back(fleft);
		filhoDireito.push_back(frigth);
		operador.push_back(c);
	}
}

void ArvoreExpressao::imprimeExpressao() const {
    imprimeExpressao(0);
}

void ArvoreExpressao::imprimeExpressao(int pos) const {
    if((operador[pos] == '+' || operador[pos] == '-' || operador[pos] == '*') && pos!=0) cout<< "(";
    if(filhoEsquerdo[pos]!=-1) imprimeExpressao(filhoEsquerdo[pos]);
    cout<<operador[pos];
    if(filhoDireito[pos]!=-1) imprimeExpressao(filhoDireito[pos]);
    if((operador[pos] == '+' || operador[pos] == '-' || operador[pos] == '*') && pos!=0) cout<<")";
}

int ArvoreExpressao::avaliaValor() const {
	return avaliaValor(0);
}

int ArvoreExpressao::avaliaValor(int pos) const {
    if(!(operador[pos] == '+' || operador[pos] == '-' || operador[pos] == '*')) {return operador[pos]-'0';}
    else return operate(avaliaValor(filhoEsquerdo[pos]), avaliaValor(filhoDireito[pos]), operador[pos]);
}

int ArvoreExpressao::operate(int a, int b, char opr) const {
    if(opr=='+') return a+b;
    else if(opr=='*') return a*b;
    else return a-b;
}

int ArvoreExpressao::altura() const {
	return altura(0);
}

int ArvoreExpressao::altura(int pos) const {
    int ae = 0, ad = 0;
    if(filhoEsquerdo[pos]!=-1) ae = altura(filhoEsquerdo[pos]) + 1;
    else return 0;
    if(filhoDireito[pos]!=-1) ad = altura(filhoDireito[pos]) + 1;
    else return 0;
    if(ae > ad) return ae;
	else return ad;
}

int ArvoreExpressao::nivelMaisNodos() const {
    int alt = altura()+1;	

    int* vec = new int[alt];
    for(int i=0;i<alt;i++) vec[i] = 0;
    nivelMaisNodos(0,vec,0);
    int pos = 0;
    int maior = -1;
    for(int i=0;i<alt;i++)
        if(vec[i]>maior) {
            maior = vec[i];
            pos = i;
        }
    delete []vec;
    return pos+1;
}

void ArvoreExpressao::nivelMaisNodos(int pos, int *vec, int nivel) const {
    vec[nivel]++;
    if(filhoEsquerdo[pos]!=-1) nivelMaisNodos(filhoEsquerdo[pos],vec,nivel+1);
    if(filhoDireito[pos]!=-1) nivelMaisNodos(filhoDireito[pos],vec,nivel+1);
}





/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/

//Nao modifique aqui
//OBS: cada arquivo de teste começa com a descricao de uma arvore.
//A seguir, ha um numero indicando qual etapa sera testada...
int main() {
	ArvoreExpressao a;
	a.leArvore();

	int etapa;
	cin >> etapa;
	switch(etapa) {
		case 1:
			cout << "Etapa 1:" << endl;
			a.imprimeArrays();
			break;
		case 2:
			cout << "Etapa 2:" << endl;
			a.imprimeExpressao();
			cout << endl;
			break;
		case 4:
			cout << "Etapa 4:" << endl;
			cout << a.avaliaValor() << endl;
			break;
		case 5:
			cout << "Etapa 5:" << endl;
			cout << a.altura() << endl;
			cout << a.nivelMaisNodos() << endl;
			break;
		default:
			cout << "Erro! Etapa invalida" << endl;
			break;
	}

}
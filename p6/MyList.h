/*
TAD MyList
- Representa uma lista implementada por encadeamento simples
- Criado por Salles Magalhaes em 19/02/2018

*/

#ifndef MyList_H__
#define MyList_H__

#include <iostream>
#include <string>
#include <ostream>
using namespace std;


//Excessao usada pela classe MyList
class MyListException {
private:
	std::string msg;
public:
	MyListException (const std::string &msg0): msg(msg0) { }
	const std::string & what() const { return msg; }
};



template<class T>
class Node;

template<class T>
class Node { //a classe Node sera "escondida" quando trabalharmos com iteradores
	public:
		Node(const T&elem): data(elem), next(NULL) {}
		T data;
		Node<T> *next;
};

template<class T>
class MyList {
public:
	//decidimos utilizar o typedef com o objetivo de "abstrair" o conceito de iterador (a utilidade disso sera vista posteriormente)
	typedef Node<T> * iterator; //define um iterador, um tipo utilizado para percorrer uma estrutura de dados e "apontar" para os items armazenados nela

	template<class T2>
	friend std::ostream& operator<<(std::ostream &, const MyList<T2> &);

	//construtores/destrutures/etc
	MyList();
	MyList(int n, const T&init=T());

	//destrutor
	~MyList() { destroy(); };

	//Construtor de copia
	MyList(const MyList &);
	MyList & operator=(const MyList &);

	//funcoes de acesso
	void push_back(const T&);
	void push_front(const T&);
	void insert(const T&,iterator nodeBefore); //insere o primeiro argumento APOS o nodo apontado pelo segundo elemento
																					//isso sera melhorado no futuro (quando estudarmos iteradores)
	iterator erase( iterator ); //remove o elemento apontado por Elem
														//retorna o (apontador) para o elemento apos o removido
	int eraseMatchingElements( T );
	void reverse();
	void reverse( Node<T> *, Node<T> * );
	iterator begin() {return dataFirst;} //Exercicio: e se tivermos uma lista constante, como itera-la para, por exemplo, imprimir os elementos?
	iterator end() {return NULL;} //retorna um apontador para um nodo que estaria APOS o final da lista
	iterator  next(iterator curr);
	T& deref(iterator curr); //Retorna o elemento da lista apontado por curr (faz uma "derreferencia")
	

	//versoes constantes dos 4 metodos acima
	const iterator begin() const {return dataFirst;} //Exercicio: e se tivermos uma lista constante, como itera-la para, por exemplo, imprimir os elementos?
	const iterator end() const {return NULL;} //retorna um apontador para um nodo que estaria APOS o final da lista
	const iterator next(const Node<T> *curr) const;
	const T& deref(const iterator curr) const; //Retorna o elemento da lista apontado por curr

	void clear();

	//Exercicio: implementar as duas funcoes abaixo supondo que nao ha um membro de dados dataSize (o calculo do tamanho da lista seria dinamico)
	void empty() const {return size() == 0;};
	int size() const {return dataSize;}; // na STL List, a funcao size() calcula o tamanho da lista dinamicamente (exercicio: qual a ordem de complexidade?)

private:
	Node<T> *dataFirst, * dataLast;
	int dataSize; //quantos elementos ha na lista?

	void create();
	void destroy();
	void destroy( Node<T> * );
};


template<class T>
void MyList<T>::destroy() { 
	destroy( dataFirst );
	//Termine esta funcao...
}

template<class T>
void MyList<T>::destroy( Node<T> *l ) { 
	/*
	if( l == NULL) return;
	destroy( l->next );
	delete l;
	dataSize = 0;
	*/
	Node<T> *aux = dataFirst;
	for(int i = 0; i < dataSize; i++ ){
		aux = aux->next;
		delete dataFirst;
		dataFirst = aux;
	}
	//crio um auxiliar para apontar para o proximo elemento, assim, qnd deleto um elemento, nao perco o ponteiro pro proximo
}

template<class T>
void MyList<T>::create() {
	dataLast = dataFirst = NULL;
	dataSize = 0;
	//Termine esta funcao...
}

template<class T>
MyList<T>::MyList() {
	create();
}

template<class T>
MyList<T>::MyList(int n, const T&init) {
	create();
	for(int i=0;i<n;i++) push_back(init); //implementacao pode ser mais eficiente se evitar atualizar o apontador "dataLast" em cada iteracao
}


//Construtor de copia
template<class T>
MyList<T>::MyList(const MyList &other) {
	create(); //Crie um vetor vazio
	*this = other; 
}

template<class T>
MyList<T> & MyList<T>::operator=(const MyList &other) {
	if(this==&other) return *this; //auto-atribuição

	clear(); //Exercicio: por que precisamos disso? pois precisamos deletar os ponteiros, criar outros para depois poder fazer a atribuição
			 //pq se eles forem de tamanhos diferentes, por exemplo, vai adr errado

	if(other.dataFirst == NULL) {
		dataFirst = dataLast = NULL;
	} else {
		Node<T> *curr = other.dataFirst;
		while(curr!=NULL) { //equivalente a "while(curr)"
			push_back(curr->data);
			curr = curr->next; //avance para o proximo nodo
		}
	}
	return *this;
}


//---------------------------------------------------------------------------------------
//Funcoes de acesso

template<class T>
void MyList<T>::push_back(const T&elem) {
	if(dataFirst==NULL) { //caso especial: lista inicialmente vazia
		dataFirst = dataLast = new Node<T>(elem);
	} else {
		dataLast->next = new Node<T>(elem);
		dataLast = dataLast->next;
	}
	dataSize++;
}

template<class T>
void MyList<T>::push_front(const T&elem) {
	if(dataFirst==NULL) { //caso especial: lista inicialmente vazia
		dataFirst = dataLast = new Node<T>(elem);
	}
	else{
		Node<T> *ptr = new Node<T>(elem);
		ptr->next = dataFirst;
		dataFirst = ptr;
	}

	dataSize ++;
}





//insere o elemento na posicao APOS a posicao nodeBefore
template<class T>
void MyList<T>::insert(const T&elem, iterator nodeBefore) {
	if(nodeBefore == NULL) {
		throw MyListException("Erro, insercao em posicao invalida da lista");
	}

	iterator newNode = new Node<T>(elem);
	newNode->next = nodeBefore->next;
	nodeBefore->next = newNode;

	if(nodeBefore == dataLast) { //caso especial
		dataLast = newNode;
	}
	dataSize++;
}


template<class T>
void MyList<T>::clear() {
	destroy();
	create();
}

template<class T>
void MyList<T>::reverse(){
	Node<T> *aux = dataFirst;
	
	if( aux == NULL) return;
	if( aux->next == NULL ) return;
	if( aux->next->next == NULL) {
		Node<T>* aux2 = dataFirst;
		//aux->next->next = aux->next;O
		dataFirst = dataLast;
		dataLast = aux2;

		dataFirst->next = dataLast;
		dataLast->next = NULL;
		return;
	}
	
	aux = aux->next;
	
	reverse( dataFirst, aux );
}

template<class T>
void MyList<T>::reverse( Node<T> *l, Node<T> *aux ){
	if( aux == dataLast) {
		aux->next = l;
		return;
	}
	reverse( l->next, aux->next );
	
	if( l == dataFirst ) {
		Node<T> * aux2 = dataLast;
		dataLast = dataFirst;
		dataFirst = aux2;
		dataLast->next = NULL;
	}
	
	aux->next = l;
}


template<class T>
int MyList<T>::eraseMatchingElements(T elem){
	int cont = 0;
	if(dataFirst == NULL) return 0;

	else if(dataFirst == dataLast){ //um elemento
		if(dataFirst->data == elem){
			delete dataFirst;
			dataFirst = dataLast = NULL;
			dataSize --;
			return 1;
		}
		return 0;
	}

	else{
		Node<T> *aux = dataFirst;
		while (aux != NULL){
			if( dataFirst->data == elem){ // se ta no primeiro elemento
				aux = dataFirst->next;
				
				delete dataFirst;

				dataFirst = aux; 
				cont ++;
			}

			else if( aux->next == dataLast && elem == dataLast->data){
				delete dataLast;
				aux->next = NULL;
				dataLast = aux;
				cont ++;	 
			}
			else if(aux->next == NULL) break; //quando aux.next==null, aux.next.data da erro, por isso essa condição
			else if( aux->next->data == elem ){
				Node<T> *aux2;
				aux2 = aux->next;
				aux->next = aux->next->next;
				
				delete aux2;
				
				cont ++;
			}

			else {
				aux = aux->next;
			}
		}
		dataSize -= cont;
		return cont;
	}
}

//assumimos que elem seja um ponteiro valido para um nodo da lista
template<class T>
typename MyList<T>::iterator MyList<T>::erase(iterator elem) { //remove o elemento apontado por Elem
													       //retorna o (apontador) para o elemento apos o removido
	dataSize--;
	if(elem==dataFirst && elem==dataLast) { //exercicio: por que precisamos desse caso especial?
		//so ha um elemento na lista
		delete elem;
		dataFirst = dataLast = NULL;
		return NULL;
	}
	
	else if(elem==dataFirst) {		
		dataFirst = dataFirst->next;
		delete elem;
		return dataFirst;
	} 
	
	
	else {
		//o elemento a ser removido nao e' o primeiro.
		Node<T>* beforeElem = dataFirst;
		Node<T>* curr = dataFirst->next;

		while(curr != elem) {
			beforeElem = curr;
			curr = curr->next;
		}

		//agora curr aponta para elem e beforeElem aponta para um elemento antes de curr
		beforeElem->next = curr->next; 
		if(curr==dataLast) {
			dataLast = beforeElem;
		}
		delete curr; //mudei aqui
		return beforeElem->next;
	}
}

template<class T>
typename MyList<T>::iterator MyList<T>::next(iterator curr) {
	return curr->next;
}

template<class T>
T& MyList<T>::deref(iterator curr) { //Retorna o elemento da lista apontado por curr (faz uma "derreferencia")
	return curr->data;
}

template<class T>
const typename MyList<T>::iterator MyList<T>::next(const Node<T> *curr) const {
	return curr->next;
}

template<class T>
const T& MyList<T>::deref(const iterator curr) const { //Retorna o elemento da lista apontado por curr (faz uma "derreferencia")
	return curr->data;
}


template<class T2>
std::ostream& operator<<(std::ostream &out, const MyList<T2> &v) {
	out << "Size: " << v.size() << "\n";
	/* //usando iteradores para abstrairem a iteracao
	MyList<T2>::iterator it = v.begin();
	while(it!=v.end()) {
		 out << v.deref(it) << " ";
		 it = v.next(it);
	}
	*/
	Node<T2> *curr = v.dataFirst; //versao utilizando ponteiros...
	while(curr!=NULL) { // equivalente a while(curr)
		 out << curr->data << " ";
		 curr = curr->next;
	}

	out << "\n";

	return out;
}


#endif
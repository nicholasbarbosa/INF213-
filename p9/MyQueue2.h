#ifndef MyQueue2_H__
#define MyQueue2_H__

#include "MyStack.h"
#include <iostream>
using namespace std;

template<class T>
class MyQueue2 {
public:
	MyQueue2() {} 

	void push(const T&el);
	const T front() ; //Nesta implementacao vamos permitir retorno por copia...
	void pop() ;

	bool empty() ;
	int size() const {return pilha2.size() + pilha1.size();}

private:
	MyStack<T> pilha1; //nao mude nada nessa interface!!!
	MyStack<T> pilha2; //nao mude nada nessa interface!!!
	
};


/* Faca sua implementacao abaixo desta linha...*/
template<class T>
void MyQueue2<T>::push( const T &el ){
	/*
	if(empty()){
		pilha2.push(el);			//pilha um sempre vai estar vazia
	}
	else{
		while(pilha2.empty() != true){	// enquanto a pilha2 n for fazia
			pilha1.push(pilha2.top());
			pilha2.pop();
		}
		pilha1.push(el);
		while(pilha1.empty() != true){
			pilha2.push(pilha1.top());
			pilha1.pop();
		}
		
	}
	*/
	if(empty()) pilha2.push(el);

	else pilha1.push(el);
}
/* Faca sua implementacao abaixo desta linha...*/
template<class T>
bool MyQueue2<T>::empty(){
	if(pilha2.empty() && pilha1.empty()) return true;
	else return false;
}
/* Faca sua implementacao abaixo desta linha...*/
template<class T>
const T MyQueue2<T>::front(){
	return pilha2.top();
}
/* Faca sua implementacao abaixo desta linha...*/
template<class T>
void MyQueue2<T>::pop(){
	if(pilha2.empty() != true){ 
		pilha2.pop();
		if(pilha2.empty()){
			while (pilha1.empty() != true){
				pilha2.push(pilha1.top());
				pilha1.pop();
			}
		}
	}
	else{
		while (pilha1.empty() != true){
			pilha2.push(pilha1.top());
			pilha1.pop();
		}
		pilha2.pop();
	}
}


#endif
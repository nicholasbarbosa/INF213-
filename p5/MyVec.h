/*
TAD MyVec
- Representa uma lista implementada por contiguidade
- Interface similar a da classe Vector do STL
- Criado por Salles Magalhaes em 19/02/2018

*/

#ifndef MyVec_H__
#define MyVec_H__

#include <iostream>
#include <string>
#include <ostream>
using namespace std;


//Excessao usada pela classe MyVec
class MyVecException {
private:
	std::string msg;
public:
	MyVecException (const std::string &msg0): msg(msg0) { }
	const std::string & what() const { return msg; }
};


template<class T>
class MyVec {
public:
	template<class T2>
	friend std::ostream& operator<<(std::ostream &, const MyVec<T2> &);

	//construtores/destrutures/etc
	MyVec();
	MyVec(int n, const T&init=T());

	//destrutor
	~MyVec() { destroy(); };

	//Construtor de copia
	MyVec(const MyVec &);
	MyVec & operator=(const MyVec &);

	//funcoes de acesso
	T &operator[](int pos) {return data[pos];}
	const T &operator[](int pos) const {return data[pos];}
	void push_back(const T&);
	void resize(int newSize);
	void insert(const T&,int pos);
	void clear();
	int eraseMatchingElements( const T & );
	void sortedInsert( const T & );

	void empty() const {return size() == 0;};
	int size() const {return dataSize;};


private:
	T *data; //declare o membro de dados data, que devera armazenar os elementos da lista
	int dataSize; //quantos elementos ha na lista?
	int dataCapacity; //quantos elementos atualmente cabem na lista? 

	void create();
	void destroy();
	void resizeCapacity(int newCapacity);
};

template<class T>
void MyVec<T>::push_back(const T&elem) {
	if( dataSize == dataCapacity ){
		if( dataCapacity == 0 )	resizeCapacity( 1 );
		else resizeCapacity ( dataCapacity * 2 ); // o resize aumenta o tamanho de vetor e n perde os dados
	}
	data[ dataSize ] = elem;
	dataSize ++;
	//Implemente esta funcao! (nao reutilize a funcao "insere")
}

template<class T>
void MyVec<T>::resize(int newSize) {
	if( newSize >= dataCapacity ) { //primeiro temos que realocar o vector...
		resizeCapacity(newSize); //para o resize vamos usar o tamanho exato caso seja necessario realocar o vector..
	}
	for(int i=dataSize;i<newSize;i++) { //preencha a parte "extra" do vector com valores "em branco"
		data[i] = T();
	}
	dataSize = newSize;
}

//insere o elemento na posicao pos e move os elementos ja presentes no vetor
// pos pode ser:
//   uma posicao apos o final do vetor (para inserir na ultima posicao) 
//   ou uma posicao ja existente (nesse caso os elementos nessa posicao e apos ela serao movidos "para a frente")
template<class T>
void MyVec<T>::insert(const T&elem,int pos) {
	if(pos > dataSize || pos < 0) {
		throw MyVecException("Erro na funcao insert: posicao invalida");
	}

	if(dataSize == dataCapacity) { //preciso redimensionar?
		if(dataCapacity ==0) //Exercicio: Por que e' preciso testar isso? pq se datacapacity for 0, o resize(datacapcity*2) ainda eh zero, nao ia funcionar o codigo
			resizeCapacity(1);
		else
			resizeCapacity(dataCapacity*2);
	}	

	for(int i=dataSize;i>pos;i--) // vai colocando os dados pro lado ate chegar na posição pos e colocar o novo elemento
		data[i] = data[i-1];
	data[pos] = elem;
	dataSize++;
}


template<class T>
void MyVec<T>::clear() {
	destroy();
	create();
}


template<class T>
void MyVec<T>::resizeCapacity(int newCapacity) {
	if ( newCapacity < dataCapacity ) return;

	dataCapacity = newCapacity;

	T *aux = new T [ dataCapacity ];

	for( int i = 0; i < dataSize; i++ ) aux[ i ] = data[ i ];

	delete[] data;
	data = aux;
	//implemente esta funcao
	//Ela deve redimensionar o vetor de modo que ele tenha capacidade newCapacity
	//Se newCapacity for menor do que a capacidade atual voce devera ignorar a chamada a esta funcao (i.e., nunca reduziremos a capacidade do vetor)
	//Nao se esqueca de liberar (deletar) a memoria que nao for mais necessaria (para evitar vazamentos de memoria)
	//Exemplo de execucao:
	//data=[1,2,3,,], dataSize=3, dataCapacity=5 (vetor de capacidade 5, com 3 elementos ocupados)
	//se chamarmos resizeCapacity(10), os membros de dados deverao ter os seguintes valores:
	//data=[1,2,3,,,,,,,], dataSize=3, dataCapacity=10
}

template<class T>
void MyVec<T>::destroy() {
	delete []data;
	dataSize = dataCapacity = 0;
}

template<class T>
void MyVec<T>::create() {
	data = NULL;
	dataSize = dataCapacity = 0;
}

template<class T>
MyVec<T>::MyVec() {
	create();
}

template<class T>
MyVec<T>::MyVec(int n, const T&init) : dataCapacity(n), dataSize(n){
	data = new T [ dataSize ];
	for( int i = 0; i < dataSize; i++) data[ i ] = init;
	//Cria um vetor de tamanho e capacidade n, onde todos os n elementos valem "init"
}

// por referencia pois o argumento pode ser algo grande como uma string
template<class T>
int MyVec<T>::eraseMatchingElements( const T &other ){ 
	int cont = dataSize;

	//se eu usasse alocação de memoria, eu poderia criar um vetor auxiliar e adicionar todos os elementos diferentes d other
	//nele e depois fazer data apontar para esse vetor auxiliar.
	for( int i = 0; i < dataSize; i++ ){
		if( data[i] == other ){
			for( int j = i; j < dataSize - 1; j++){
				data[ j ] = data[ j + 1 ];
			}
		i --;	
		dataSize--;
		}
	}
	return cont - dataSize;

	// o melhor caso vai ser O(n), pois n entra no if
	// o pior caso vai ser O(n^2)
	// T(n) pertence à O(n^2)
}

template<class T>
void MyVec<T>::sortedInsert( const T &x ){
	T aux;
	
	push_back(x);

	int pos = dataSize - 1;
	
	for( int i = pos - 1; i >= 0; i--)
		if(data[pos] > data[i]) break;
		else{
			aux = data[pos];
			data[pos] = data[i];
			data[i] = aux;
			pos = i;
		}

}

//Construtor de copia
template<class T>
MyVec<T>::MyVec(const MyVec &other) {
	// no construtor de cópia, eu ainda n tenho o objeto, pois estou construindo um novo.
	// quando chama a sobrecarga de atribuição, ela chama o destroy, pra destruir o vetor data, mas como estou construindo
	// um novo objeto, data ainda n foi criado, ou seja, quando chama o operador de atribuição, ele tenta destruir
	// o vetor data q eh inválido.
	// para resolver isso, basta aportar data para null
	data = NULL;
	*this = other;
}

template<class T>
MyVec<T> & MyVec<T>::operator=(const MyVec &other) {
	if(this==&other) return *this; 
	destroy(); //Exercicio: por que precisamos disso? pois eh preciso desalocar o vetor para criar outro com tamanho igual ao vetor da atribuução
	dataCapacity = other.dataCapacity;
	dataSize = other.dataSize;
	//data = other.data; //por que nao podemos fazer isso? pq o data vai apontar para o mesmo espaço da memoria q o other.data
	data = new T[dataCapacity];
	for(int i=0;i<dataSize;i++) data[i] = other.data[i];
	return *this;
}

template<class T2>
std::ostream& operator<<(std::ostream &out, const MyVec<T2> &v) {
	out << "Size: " << v.size() << "\n";
	out << "Capacity: " << v.dataCapacity << "\n";
	for(int i=0;i<v.size();i++) out << v.data[i] << " ";
	out << "\n";
	return out;
}

#endif
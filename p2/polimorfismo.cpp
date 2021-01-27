#include <iostream>

using namespace std;

class base {
    private:
        int a;
    public:
        base(int a = 1): a(a){
            //cout << "construtor base" << endl;            
        }
        ~base(){
            cout << "destrutor base" << endl;
            cout << endl;
        }
        void print() const{
            cout << "print " << this->a;
        }
        virtual void complemento() const = 0;
};

class derivada : public base{
    private:
        int b;
    public:
        derivada(int a = 1, int b = 2): base(a), b(b){
            //cout << "construtor derivada" << endl;
        }
        ~derivada(){
            cout << "destrutor derivada" << endl;
            cout << endl;
        }
        virtual void print() const{
            base::print();
            cout << " " << this->b << endl;
        }
        virtual void complemento() const{
            cout << "os metodos são :" << this->b << endl;
        }
};

class derivada2 : public derivada{
    private:
        int c;
    public:
        derivada2(int a = 1, int b = 2, int c = 3) : derivada(a,b), c(c){
            //cout << "construtor derivada 2" << endl;
        }
        ~derivada2(){
            cout << "destrutor derivada 2" << endl;
            cout << endl;
        }
        virtual void print() const{
            derivada::print();
            cout << "continuacao linha de cima " << this->c << endl;
        }

        virtual void complemento() const{
            cout << "os metodos são :" << this->c << endl;
        }
};

int main(){
    //base a;
    derivada b;
    derivada2 c;

    base *bPtr = &c; // a classe base é abstrata, pois ela tem função pura, logo nao pode ter instancias (objetos)
    derivada *dPtr = &c;
    derivada2 *d2Ptr = &c;

    bPtr->print();
    bPtr->complemento();

    cout << endl;

    dPtr->print();
    dPtr->complemento();

    cout << endl;

    d2Ptr->print();
    d2Ptr->complemento();

    return 0;
}
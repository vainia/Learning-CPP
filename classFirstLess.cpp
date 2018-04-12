#include <iostream>
using namespace std;

int i=0;

class Pozdro {
    int k1;
public:
    enum Kraj { PL, DE, FR };
    int k2 = 100500, k3;
    void fun(Kraj kraj) {
        switch (kraj) {
            case PL:
                cout << "D  z  i  e  n           d  o  b  r  y\n"; k1 = 1; break;
            case DE:
                cout << "G   u   t   e   n           T   a   g\n";   k1 = 2; break;
            case FR:
                cout << "B     o     n     j     o     u     r\n";     k1 = 3; break;
        }
    }
    Pozdro(){
      i++;
      cout<<"Został utwozrony nowy obiekt numer: "<<i<<endl;
    }
    ~Pozdro(){
      cout<<"Został usunięty obiekt numer:       "<<i<<endl;
      i--;
    }
};

int main() {
    Pozdro dd, second, third;
    {
      Pozdro fourth, fifth;
    }
    Pozdro siht;

    dd.fun(Pozdro::PL);

    int *pk1 = &dd.k3 - 2;

    cout << "sizeof(dd)                       = " << sizeof(dd) << endl;
    cout << "dd.k1                            =  " << *pk1       << endl;
}

#include <iostream>
#include <cassert>
using namespace std;

struct Bag;
enum Rodzaj {LICZBA, WSKAZNIK, ZNAK};

void wstaw(Bag*,double);
void wstaw(Bag*,int*);
void wstaw(Bag*,char);

void daj(const Bag*,double&);
void daj(const Bag*,int*&);
void daj(const Bag*,char&);

void info(const Bag&);

struct Bag {
    Rodzaj rodzaj;
    union {
        double dbl;
        int   *wsk;
        char   znk;
    };
};

int main() {
    Bag bag;
    double x = 3.14, y;
    int    i = 10, *pi = &i;
    char   c ='a', b;
    cout << "sizeof(bag) = " << sizeof(bag)
         << " bajtow\nAdresy skladowych:\n dbl: "
         << &bag.dbl << "\n wsk: " <<  &bag.wsk
         << "\n znk: " << (void*)&bag.znk << endl;

    wstaw(&bag,x);
    info(bag);
    daj(&bag,y);
    cout << "Z funkcji main - y  = " <<    y << endl;

    wstaw(&bag,&i);
    info(bag);
    daj(&bag,pi);
    cout << "Z funkcji main - *pi = " << *pi << endl;

    wstaw(&bag,c);
    info(bag);
    daj(&bag,b);
    cout << "Z funkcji main - b   = " <<   b << endl;
}

void wstaw(Bag *w, double x) {
    w->rodzaj   = LICZBA;
    w->dbl = x;
}

void wstaw(Bag *w, int *pi) {
    w->rodzaj   = WSKAZNIK;
    w->wsk = pi;
}

void wstaw(Bag *w, char c) {
    w->rodzaj   = ZNAK;
    w->znk = c;
}

void daj(const Bag *w, double& x) {
    assert(w->rodzaj == LICZBA);
    x  = w->dbl;
}

void daj(const Bag *w, int*& pi) {
    assert(w->rodzaj == WSKAZNIK);
    pi = w->wsk;
}

void daj(const Bag *w, char& c) {
    assert(w->rodzaj == ZNAK);
    c  = w->znk;
}

void info(const Bag &w) {
    cout << "\nZ funkcji info - ";
    switch (w.rodzaj) {
    case LICZBA:
        cout << "Liczba:   " << w.dbl    << endl;
        break;
    case WSKAZNIK:
        cout << "Wskaznik: " << *(w.wsk) << endl;
        break;
    case ZNAK:
        cout << "Znak:     " << w.znk    << endl;
        break;
    }
}

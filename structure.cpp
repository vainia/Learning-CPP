#include <iostream>
#include <cstring>   // strcpy
using namespace std;

struct Husband;
struct Wife;

void prinfo(const Husband*);
void prinfo(const Wife*);

struct Wife {
    Husband *hus;
    char name[20];
} honoratka = { 0, "Honoratka" } ;

struct Husband {
    Wife *wif;
    char name[20];
} antoni  = { 0 } ;

int main() {
    strcpy(antoni.name, "Antoni");

    antoni.wif    = &honoratka;
    honoratka.hus = &antoni;

    Husband zenobiusz  = { 0, "Zenobiusz" };
    Wife    celestynka = { 0, "Celestynka"};

    prinfo(&antoni);
    prinfo(&honoratka);
    prinfo(&zenobiusz);
    prinfo(&celestynka);
}

void prinfo(const Husband *h) {
    cout << "Mezczyzna: " << h->name;
    if ( h->wif )
        cout << "; zona "
             << h->wif->name << "\n";
    else
        cout << "; (kawaler)\n";
}

void prinfo(const Wife *w) {
    cout << "Kobieta:   " << w->name;
    if ( w->hus )
        cout << "; maz "
             << (*((*w).hus)).name << "\n";
    else
        cout << "; (panna)\n";
}

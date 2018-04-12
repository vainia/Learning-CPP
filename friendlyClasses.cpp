#include <iostream>
using namespace std;

class Zakres;

class Punkt {

    int liczba;
    friend void isInside(const Punkt*, const Zakres*);

public:
    Punkt(int liczba = 0)
        : liczba(liczba)
    { }
};

class Zakres {

    int lewy, prawy;
    friend void isInside(const Punkt*, const Zakres*);

public:
    Zakres(int lewy = 0, int prawy = 0)
        : lewy(lewy), prawy(prawy)
    { }
};

void isInside(const Punkt *p, const Zakres *z) {
    if ((p->liczba >= z->lewy) && (p->liczba <= z->prawy))
        cout << "Punkt " << p->liczba   << " lezy w "
                "zakresie [" << z->lewy << ","
             << z->prawy  << "]\n";
    else
        cout << "Punkt " << p->liczba   << " lezy poza "
                "zakresem [" << z->lewy << ","
             << z->prawy  << "]\n";
}

int main() {
    Punkt p(7);
    Zakres z1(0,10), z2(8,20);

    isInside(&p,&z1);
    isInside(&p,&z2);
}

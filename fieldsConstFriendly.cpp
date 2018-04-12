#include <iostream>
#include <cstring>
using namespace std;

// UWAGA: klasy niekompletne; brak tu
// przeciazenia operatora przypisania

class Pracownik;

enum stanowisko {zwykly, kierownik, prezes};

class Osoba {
    char* nazwisko;
    int   rok_urodzenia;

      // deklaracja przyjazni
    friend void pracinfo(const Pracownik*);
public:
    Osoba(char* n, int r)
        : nazwisko(strcpy(new char[strlen(n)+1],n)),
          rok_urodzenia(r)
    { }

      // konstruktor kopiujacy
    Osoba(const Osoba& os)
        : nazwisko(strcpy(new
              char[strlen(os.nazwisko)+1],os.nazwisko)),
          rok_urodzenia(os.rok_urodzenia)
    { }

      // destruktor
    ~Osoba() {
        cout << "Usuwamy osobe " << nazwisko << endl;
        delete [] nazwisko;
    }
};

class Pracownik {
    static int      ID;
    Osoba         dane;
    const int &zarobki;
    const int       id;

      // deklaracja przyjazni
    friend void pracinfo(const Pracownik*);
public:
    Pracownik(char* nazw, int rok, int& zar)
        : dane(nazw,rok), zarobki(zar), id(++ID)
    { }

      // konstruktor kopiujacy
    Pracownik(const Pracownik& prac)
        : dane(prac.dane), zarobki(prac.zarobki), id(++ID)
    { }
};
int Pracownik::ID;

void pracinfo(const Pracownik* prac) {
    cout << prac->dane.nazwisko       << " (r.ur. "
         << prac->dane.rok_urodzenia  << ") id="
         << prac->id << "; zarobki: " << prac->zarobki
                                      << endl;
}

int main() {
    int placa[] = { 1600, 2100, 8900 };

    Pracownik  jasio("Jasio  ", 1978, placa[zwykly]);
    Pracownik  henio("Henio  ", 1980, placa[zwykly]);
    Pracownik    jan("Jan    ", 1965, placa[kierownik]);
    Pracownik panJan("Pan Jan", 1955, placa[prezes]);

    pracinfo(&jasio);
    pracinfo(&henio);
    pracinfo(&jan);
    pracinfo(&panJan);

    cout << "\nZmieniamy place\n\n";

    placa[zwykly] -=  300;
    placa[prezes] += 1000;

    pracinfo(&jasio);
    pracinfo(&henio);
    pracinfo(&jan);
    pracinfo(&panJan);

    cout<<placa[2];

    cout << "\nKoniec programu\n\n";
}

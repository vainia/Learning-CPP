#include <iostream>
#include <cstdlib>
using namespace std;

class Klient{
  static int ID;
  char* nazwisko;
  const int id;
  int ma, winien;

public:
  class Saldo{
    int id;
    int saldo;
  public:
    Saldo(int id, int saldo):id(id),saldo(saldo){}
    void printinfo();
  };

  Klient(const char* n):nazwisko(strcpy(new char[strlen(n)+1],n)),id(++ID),ma(0),winien(0){}

  Klient& wplata (int w) {ma += w; return *this; }
  Klient& wyplata(int w) {winien += w; return *this; }

  Saldo* dajSaldo();

  ~Klient() {delete [] nazwisko; }
};

int Klient::ID=0;

Klient::Saldo* Klient::dajSaldo() {
  return new Saldo(id, ma-winien);
}

void Klient::Saldo::printinfo() {
  cout<<"id: "<<id<<" Saldo: "<<saldo<<endl;
}

int main() {
  Klient kow("Kowalski");
  Klient* pmal = new Klient("Malinowski");

  kow.wplata(100).wplata(50).wyplata(75);
  pmal->wplata(200).wyplata(50).wyplata(25);

  Klient::Saldo* pskow = kow.dajSaldo();
  Klient::Saldo* psmal = pmal->dajSaldo();

  pskow->printinfo();
  psmal->printinfo();

  Klient::Saldo anonim(9,500);
  anonim.printinfo();

  delete pskow;
  delete psmal;
  delete pmal;
}

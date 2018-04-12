#include <iostream>
#include <string>
using namespace std;

struct FullInfo {
    string address;

    FullInfo(string name) {
        cout << "Szukam adresu w bazie danych" << endl;
        address = "Adres pana " + name;
    }
};

class Klient {
    string  name;
    mutable FullInfo *fullInfo;
public:
    Klient(string n) {
        name     = n;
        fullInfo = nullptr;
    }

    string getInfo() const {
        return name;
    }

    string getFullInfo() const {
        if (fullInfo == nullptr)
            fullInfo = new FullInfo(name);
        return name + ", " + fullInfo->address;
    }

    ~Klient() {
        delete fullInfo;
        cout << "usuwam " + name << endl;
    }
};

int main() {
    Klient klient("Nowak");
    cout << klient.getInfo()     << endl;
    cout << klient.getFullInfo() << endl;
    cout << "Koniec \'main\'\n";
}

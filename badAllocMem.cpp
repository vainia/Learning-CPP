#include <iostream>
#include <new>
#include <iomanip>
using namespace std;

int main() {
    const size_t mega = 1024*1024, step = 200*mega;

    for (size_t size = step; ;size += step) {
        try {
            char* buf = new char[size];
            delete [] buf;
        }
        catch(bad_alloc) {
            cout << "NIE UDALO SIE: "  << setw(4)
                 << size/mega << " MB" << endl;
            return 1;
        }
        cout << "    udalo sie: "  << setw(4)
             << size/mega << " MB" << endl;
    }
}

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    // sqrt calculato
    // float i;
    // cout<<"Wpisz liczbe z ktorej chcesz uzyskac pierwiastek"<<endl;
    // cout<<"Pierwiastek z "<<i<<" = "<<sqrt(i)<<endl;
    // cin>>i;
    int y=1, *py=0;
    // cout<<"py = "<<py<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"&py = "<<&py<<endl;
    cout<<"&y = "<<&y<<endl<<"\n";

    cout<<"py=&y;"<<endl;
    py=&y;
    cout<<"py = "<<py<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"&py = "<<&py<<endl;
    cout<<"&y = "<<&y<<endl;
    cout<<"*py = "<<*py<<endl<<"\n";

    cout<<"*py=8;"<<endl;
    *py=8;
    cout<<"py = "<<py<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"&py = "<<&py<<endl;
    cout<<"&y = "<<&y<<endl;
    cout<<"*py = "<<*py<<endl<<"\n";


    int x=10, *px=&x;
    int *pv=px;
    cout<<"&x = "<<&x<<endl;
    cout<<"pv = "<<pv<<endl;
    cout<<"px = "<<px<<endl;
    cout<<"&pv = "<<&pv<<endl;
    cout<<"&px = "<<&px<<endl;
    cout<<"*px = "<<*px<<endl;
    cout<<"*pv = "<<*pv<<endl<<"\n";

    return 0;
}

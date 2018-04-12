#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

bool parzysta(int a) {
    return (a%2) == 0;
}

int main() {
    vector<int> vec;
    int d;
    while ( cin >> d ) vec.push_back(d);
    cin.clear();

    cout << "W ciagu liczb ";
    copy(vec.begin(),vec.end(),
         ostream_iterator<int>(cout, " "));
    cout << "\njest "
         << count_if(vec.begin(),vec.end(),parzysta)
         << " liczb parzystych\n";
}

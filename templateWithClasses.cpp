#include <iostream>

using namespace std;

class MyA{
public:
  int x, y;

  MyA(int x, int y): x(x), y(y){}
};

template <typename T>
T myMax(T x, T y){
  if(x>y)return x;
  return y;
}

ostream& operator<<(ostream& s, MyA myTmp){
  s<<"MyA::x="<<myTmp.x<<" "<<"MyA::y="<<myTmp.y<<endl;
  return s;
}

MyA myMax(MyA x, MyA y){
  if((x.x+x.y)>(y.x+y.y))return x;
  return y;
}

int main(){
  MyA x(1,2), y(3,4);
  cout<<myMax(5,6)<<endl;
  cout<<myMax(x,y)<<endl;
  return 0;
}

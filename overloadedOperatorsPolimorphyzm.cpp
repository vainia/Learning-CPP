#include <iostream>

using namespace std;

class A{
  int x, y, z;
public:
  int& operator[](int i){
    if(i==1)return x;
    if(i==2)return y;
    return z;
  }
  A(int x, int y, int z):x(x),y(y),z(z){}
};

class B:virtual public A{
  int x, y;
public:
  B(int px, int py):A(px,py,py-px){
    x=px+py;
    y=px-py;
  }
  int& operator[](int i){
    if(i>0 && i<4) return A::operator[](i);
    if(i==4) return x;
    return y;
  }
};

class C:virtual public A{
  int x, y;
public:
  C(int px, int py):A(px,py,py-px){
    x=px+py;
    y=px-py;
  }
  int& operator[](int i){
    if(i>0 && i<4) return A::operator[](i);
    if(i==4) return x;
    return y;
  }
};

class D:public B, public C{
  int x, y, z;
public:
  D(int x, int y, int z):A(x,y,z),B(x,z),C(y,z),x(x+y+z),y(x-y+z),z(x-y-z){}
  int& operator[](int i){
    if(i>0 && i<6) return B::operator[](i);
    if(i>5 && i<11) return C::operator[](i-5);
    if(i==11) return x;
    if(i==12) return y;
    return z;
  }
};

int main() {
  // B aqq1(1,6);
  // for(int i=1;i<5;++i){
  //   cout<<aqq1[i]<<endl;
  // }
  cout<<endl;
  D aqq(7,1,8);
  aqq.B::operator[](1)=1234567890;
  cout<<aqq.C::operator[](1)<<endl;
   C aqq3(1,6);
   for(int i=1;i<5;++i){
     cout<<aqq3[i]<<endl;
   }
   cout<<endl;
  return 0;
}

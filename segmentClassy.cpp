#include <iostream>
using namespace std;

class A {
protected:
  char A1;
  int A2;
  int A3;
  A(char p_A1='a',int p_A2=5,int p_A3=10):A1(p_A1),A2(p_A2),A3(p_A3){};
  void druk(/* arguments */) {
    cout<<endl<<"klassa A"<<endl;
    cout<<"A1="<<A1<<endl;
    cout<<"A2="<<A2<<endl;
    cout<<"A3="<<A3<<endl;
  }
};

class B {
protected:
  double B1;
  double B2;
  int B3;
  B(double p_B1=0,double p_B2=0,int p_B3=0):B1(p_B1),B2(p_B2),B3(p_B3){};
  void druk(/* arguments */) {
    cout<<endl<<"klassa B"<<endl;
    cout<<"B1="<<B1<<endl;
    cout<<"B2="<<B2<<endl;
    cout<<"B3="<<B3<<endl;
  }
};

class C {
protected:
  char C1;
  int C2;
  C(char p_C1='a',int p_C2=0):C1(p_C1),C2(p_C2){};
  void druk(/* arguments */) {
    cout<<endl<<"klassa C"<<endl;
    cout<<"C1="<<C1<<endl;
    cout<<"C2="<<C2<<endl;
  }
};

class AB:public A, public B{
private:
  int AB1;
public:
  AB(int p_AB1=10):AB1(p_AB1){};
  void druk(){
    A::druk();
    B::druk();
    cout<<endl<<"AB1="<<AB1<<endl;
  }
};

int main(){
  AB ala;
  ala.druk();
  return 0;
}

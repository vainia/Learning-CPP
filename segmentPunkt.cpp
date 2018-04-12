#include <iostream>
using namespace std;

class punkt{
protected:
  double x;
  double y;
  punkt(double px=0, double py=0):x(px),y(py){};
  void druk(/* arguments */){
    cout<<"x="<<x<<endl<<"y="<<y<<endl;
  }
  friend class segment;
};

class pixiel:public punkt{
private:
  int kolor;
public:
  pixiel(double px, double py, int pkolor):kolor(pkolor),punkt(px,py){}
  void druk(/* arguments */) {
    punkt::druk();
    cout<<"kolor="<<kolor<<endl;
  }
};

class segment{
private:
  punkt a;
  punkt b;
public:
  segment(double Ax, double Ay, double Bx, double By){
    a.x=Ax;
    a.y=Ay;
    b.x=Bx;
    b.y=By;
  }
  void druk(/* arguments */) {
    cout<<endl<<"A"<<endl;
    a.druk();
    cout<<endl<<"B"<<endl;
    b.druk();
  }
};

int main(){
  pixiel A(2,3,6);
  segment AB(1,2,2,1);
  A.druk();
  AB.druk();
  return 0;
}

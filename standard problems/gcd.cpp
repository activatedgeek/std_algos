#include <iostream>
using namespace std;

int gcd(int a,int b){
  while(b){
    int r = b;
    b = a%b;
    a = r;
  }
  return a;
}

int main(){
  cout<<gcd(18,24);
  return 0;
}

#include <iostream>

using namespace std;

int main(){
double** p = new double*;
*p= new double;
**p = 4; 
cout << **p;
delete *p;
delete p;
return 0;

}
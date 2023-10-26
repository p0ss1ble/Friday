#include <iostream>
#include <cmath>

using namespace std;

static int get_int_value(int& value) //возвращающий адрес операнда в памяти
{
  double number;
  cin >> number;
  
  while(!cin || number - floor(number)) //while(!cin || number - floor(number)) // or if(cin.fail()) //любая попытка читать дальше безуспешна
  {
    cin.clear(); //только после этого мы можем читать что-то другое
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //просто вводим чиселки
    cout << "Invalid number, repeat:";
    cin >> number;
  }

  value = number;

  return 0;
}

int main()
{
  int n ;
  get_int_value(n);

  if (n > 100000 || n < 0)
  {
    cout << "Incorrect number:";
    return -1;
  }

  int s = 1;
  for ( int i = 1; i < n + 1 ; i++){
      s *= i;
  }

  cout << s << endl;

}
#include <iostream>
#include <cmath>

using namespace std;

int get_int_value(int& value)
{
  double number;
  cin >> number;
  while(!cin || number - floor(number))
  {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Invalid number, repeat: ";
    cin >> number;
  }

  value = number;

  return 0;
}


int fibonachi(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
        
    return fibonachi(n-1) + fibonachi(n-2);
}

int main()
{
  int n;
  get_int_value(n);

  if (n > 100 || n < 1)
  {
    cout << "Incorrect number, repeat: ";
    return -1;
  }
  
  for(int i = 0; i < n; i++){
    cout << fibonachi(i) << endl;
  }
  
  return 0;
}
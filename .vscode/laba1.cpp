#include <cmath>
#include <iostream>
using namespace std;
int main() {
  cout << "Enter x and k" << endl;
  int k, n;
    double x, a, e, y, pi{ 3.1415926535}, b;
  cin >> x >> k;
  if (k>1 && x>-1 && x<1) {
    a = pi / 2 - atan(x);            //значение, вычисленное по стандартной функции
    e = pow(10, -k);                // максимальное епсилон
    n = 1;                         // счётчик для слагаемых
    y = (pow(-1, n) * pow(x, 2 * n - 1)) / (2 * n - 1);    
    double sum = pi / 2;                       // сумма с х=0
    while (abs(y) >= e)
    {
        sum = sum + y;
      n = n + 1;
      y = (pow(-1, n) * pow(x, 2 * n - 1)) / (2 * n - 1);
    }
    b = sum;
      if (a > b) {
        cout << "arcctg1(x)" << "=" << a << endl;
        cout << "arcctg2(x)" << "=" << b << endl;
        cout << "arcctg1(x)" << ">" << "arcctg2(x)";
      }
      else if (a == b) {
        cout << "arcctg1(x)" << "=" << a << endl;
        cout << "arcctg2(x)" << "=" << b << endl;
        cout << "arcctg1(x)" << "=" << "arcctg2(x)";
      }
      else {
        cout << "arcctg1(x)" << "=" << a << endl;
        cout << "arcctg2(x)" << "=" << b << endl;
        cout << "arcctg1(x)" << "<" << "arcctg2(x)";
      }
  }
  else {
    cout << "Check the entered data" << endl;
  }

  return 0;
}
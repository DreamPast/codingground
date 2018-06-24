#include <iostream>
#include "bignum.h"
using namespace std;

int main()
{
   bignum a;
   cin >> a;
   cout << a.pow(32) << endl;
   return 0;
}
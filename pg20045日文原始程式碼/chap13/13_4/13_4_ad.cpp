#include <iostream.h>

int main(void)
{
double d = 1.00000;	// dはdouble型(値は1.0)
int&   p = d;	// pはdouble型を参照？
const int& q = 5;	// qは定数を参照？

p = 3.14;		// 3.14の代入先はintそれともdouble？
cout << "d = " << d << '\n';
cout << "p = " << p << '\n';
cout << "q = " << q << '\n';
return(0);
}

#include <iostream.h>

int main(void)
{
double d = 1.00000;	// d��double�^(�l��1.0)
int&   p = d;	// p��double�^���Q�ƁH
const int& q = 5;	// q�͒萔���Q�ƁH

p = 3.14;		// 3.14�̑�����int����Ƃ�double�H
cout << "d = " << d << '\n';
cout << "p = " << p << '\n';
cout << "q = " << q << '\n';
return(0);
}

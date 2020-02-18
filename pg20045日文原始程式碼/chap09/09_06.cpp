#include	<iostream.h>

double f(double x)		//--- �֐�f ---//
{
	return (x * x);
}

double g(double x)		//--- �֐�g ---//
{
	return (x * x * x + 3 * x * x);
}

//--- ��`������p���Ċ֐�func(x)��x1����x2�܂�n�����Őϕ�����֐� ---//
double daikei(double x1, double x2, int n, double (*func)(double x))
{
	double	s = 0.0;
	double	step = (x2 - x1) / n;
	for (int i = 0; i < n; i++)
		s += ( (*func)(x1 + step*i) + (*func)(x1 + step*(i+1)) ) * step / 2.0;
	return (s);
}

int main(void)
{
	cout << "f(x)��0.0����1.0�܂�10�����Őϕ��F"
		 << daikei(0.0, 1.0, 10, f) << '\n';

	cout << "g(x)��1.0����3.0�܂�15�����Őϕ��F"
		 << daikei(1.0, 3.0, 15, g) << '\n';

	return (0);
}

/*
���s����
f(x)��0.0����1.0�܂�10�����Őϕ��F0.335
g(x)��1.0����3.0�܂�15�����Őϕ��F46.0533
*/

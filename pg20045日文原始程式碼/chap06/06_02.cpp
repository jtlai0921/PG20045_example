#include	<iostream.h>

//--- �����Q�悵���l��ԋp���� ---//
inline double square(double x)
{
	return (x * x);
}

//--- �����R�悵���l��ԋp���� ---//
inline double cube(double x)
{
	return (x * x * x);
}

int main(void)
{
	double  a;

	cout << "�����l����͂��Ă��������F";
	cin >> a;

	cout << a << "�̂Q���" << square(a) << "�ł��B\n";
	cout << a << "�̂R���" << cube(a)   << "�ł��B\n";

	return (0);
}

/*
���s��
�����l����͂��Ă��������F4.2��
4�̂Q���17.64�ł��B
4�̂R���74.088�ł��B
*/

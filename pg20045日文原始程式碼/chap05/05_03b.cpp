#include	<iostream.h>

//--- ���������_�����̂����ԋp���� ---//
double power(double x, int n)
{
	double	a = 1.0;

	if (n > 0)						// n��0���傫���ꍇ
		while (n-- > 0) 	a *= x;
	else							// n��0�ȉ��̏ꍇ
		while (n++ < 0) 	a /= x;

	return (a);
}

int main(void)
{
	double	a;
	int		b;

	cout << "�����l����͂���F";
	cin >> a;

	cout << "�����l����͂���F";
	cin >> b;

	cout << a << "��" << b << "���" << power(a, b) << "�ł��B\n";

	return (0); 
}


#include	<iostream.h>

//--- �Q�悷��i�e���v���[�g�Łj ---//
template <class Type> Type square(Type x)
{
	return (x * x);
}

int main(void)
{
	int	 a;

	cout << "�����l����͂��Ă��������F";
	cin >> a;
	cout << a << "�̂Q���" << square(a) << "�ł��B\n";

	double	b;

	cout << "�����l����͂��Ă��������F";
	cin >> b;
	cout << b << "�̂Q���" << square(b) << "�ł��B\n";

	return (0);
}

/*
���s��
�����l����͂��Ă��������F5��
5�̂Q���25�ł��B
�����l����͂��Ă��������F1.2��
1.2�̂Q���1.44�ł��B
*/
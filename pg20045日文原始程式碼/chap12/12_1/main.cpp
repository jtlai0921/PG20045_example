/*
	���W�N���X Position ��P�� �|���p��P�|					"main.c"
*/

#include	<iostream.h>

#include	"position.h"

int main(void)
{
	Position  a(10.0, -10.0);				// �_a��(10.0, -10.0)�ŏ�����

	Position  b = Position(3.5, 6.0);		// �_b��(-3.5, 6.0)�ŏ�����

	cout << "�_a = (" << a.X() << ", " << a.Y() << ")\n";
	cout << "�_b = (" << b.X() << ", " << b.Y() << ")\n";

	return (0);
}

/*
���s����
�_a = (10, -10)
�_b = (-3.5, 6)
*/


/*
	���W�N���X Position ��P�� �|���p��Q�|					"main.c"
*/

#include	<iostream.h>

#include	"position.h"

int main(void)
{
	Position  a(0.0, 0.0);							// �_a��(0.0, 0.0)�ŏ�����

	cout << "�_a = (" << a.X() << ", " << a.Y() << ")\n";

	cout << "�_a��(10.0, -10.0)����\n";

	a = Position(10.0, -10.0);						// �_a��(10.0, -10.0)����

	cout << "�_a = (" << a.X() << ", " << a.Y() << ")\n";

	return (0);
}

/*
���s����
�_a = (0, 0)
�_a��(10.0, -10.0)����
�_a = (10, -10)
*/

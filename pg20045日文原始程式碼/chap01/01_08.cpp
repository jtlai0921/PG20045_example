#include	<iostream.h>

int main(void)
{
	/* �ϐ����͖��̎w���ʂ�ł͂���܂��� */
	int	    a, b;		// a,b��int�^
	double  x, y;		// x,y��double�^

	cout << "sizeof(int    + int   )�F" << sizeof(a + b) << '\n';
	cout << "sizeof(double + double)�F" << sizeof(x + y) << '\n';
	cout << "sizeof(int    + double)�F" << sizeof(a + x) << '\n';

	return (0);
}

/*
���s���ʈ��
sizeof(int    + int   )�F2
sizeof(double + double)�F8
sizeof(int    + double)�F8
*/

#include	<iostream.h>

int main(void)
{
	int	 x;
	cout << "int�^�̑傫���F" << sizeof(int) << '\n';
	cout << "�ϐ�x�̑傫���F" << sizeof(x)   << '\n';

	double	a;
	cout << "double�^�̑傫���F" << sizeof(double) << '\n';
	cout << "�� �� a �̑傫���F" << sizeof(a)      << '\n';

	return (0);
}

/*
���s���ʈ��
int�^�̑傫���F2
�ϐ�x�̑傫���F2
double�^�̑傫���F8
�� �� a �̑傫���F8
*/


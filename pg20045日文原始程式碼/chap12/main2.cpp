/*
	���W�N���X Position ��Q�� �|���p��Q�|					"main.c"
*/

#include	<iostream.h>

#include	"position.h"

int main(void)
{
	const Position pos_O(0.0, 0.0);			// ���_
	Position  a(5.0, 6.0);					// �_a��(5.0, 6.0)�ŏ�����

	cout << "���_ = " << pos_O << '\n';
	cout << "�_�� = " << a << "\n\n";

//	pos_O.Set(10.0, 5.0);					// �G���[
	a.Set(-3.0, 2.0);						// �_a�̍��W��(-3.0, 2.0)�ɕύX

	cout << "�_����(-3.0, 2.0)�ɕύX���܂����B\n\n";
	cout << "�_�� = " << a << '\n';

	return (0);
}

/*
���s����
���_ = (0, 0)
�_�� = (5.0, 6.0)

�_����(-3.0, 2.0)�ɕύX���܂����B

�_�� = (-3.0, 2.0)
*/

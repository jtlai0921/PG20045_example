/*
	�J�E���^�N���X Counter ��P�Ł@�| ���p�� �|				"main.c"
*/

#include	<iostream.h>

#include	"counter.h"

int main(void)
{
	Counter x;
	int     i;

	for (i = 0; i < 5; i++) {
		x.Increment();					// �J�E���g�A�b�v
		cout << x.Value() << '\n';
	}

	for (i = 0; i < 2; i++) {
		x.Decrement();					// �J�E���g�_�E��
		cout << x.Value() << '\n';
	}

	return (0);
}

/*
���s����
1
2
3
4
5
4
3
*/

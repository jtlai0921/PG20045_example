/*
	�W�����P���Q�[���i���C�����j                          "main.c"
*/

#include	<iostream.h>

#include	"jyanken.h"

int	 draw;							// ������������������
int	 win;							// ��������
int	 lose;							// ��������

int main(void)
{
	cout << "�W�����P�����܂��傤\a\n\n";

	do {
		int  hantei;
		draw = 0;
		do {
			int	 comp = kettei();				// �R���s���[�^�̎�
			int	 user = input();				// ���p�҂̎�

			display(comp);						// ���҂̎��\��
			hantei = judge(user);				// ���s����
			if (hantei > 0)
				cout << "���Ȃ��̏���!!\n";
			else if (hantei < 0)
				cout << "���Ȃ��̕���!!\n";
		} while (!hantei);
		cout << win << "��" << lose << "�s�ł��B\n";
	} while (cont_game());

	return (0);
}

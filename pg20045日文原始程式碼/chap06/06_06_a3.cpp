/*
	�W�����P���Q�[���i���C�����j                          "main.c"
*/

#include	<iostream.h>

int	 kettei(void);					// �R���s���[�^�̎������
int	 judge(int user);				// ���s�𔻒�			

int	 input(void);					// ���p�҂̎�����
void display(int comp);				// �R���s���[�^�̎��\��
int	 cont_game(void);				// ���s�̊m�F

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

/*
���s��
�W�����P�������܂��傤�B

�W�����P���ۂ�
(0)�ް (1)��� (2)�߰:1��
�R���s���[�^���߰�ł��B
���Ȃ��̏���!!
1��0�s�ł��B
������x���܂����H
<Yes��1�^No��0>�F1��
�W�����P���ۂ�
(0)�ް (1)��� (2)�߰:0��
�R���s���[�^�͸ް�ł��B
�������ŃV��
(0)�ް (1)��� (2)�߰:0��
�R���s���[�^���߰�ł��B
���̂��̕���!!
1��1�s�ł��B
������x���܂����H
<Yes��1�^No��0>�F0��
*/

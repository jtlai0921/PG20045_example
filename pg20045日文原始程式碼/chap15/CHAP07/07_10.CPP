#include	<iostream.h>

enum menu  { Termination, Dog, Cat, Mokey, Invalid };

//--- ���ɖ����� ---//
void dog(void)
{
	cout << "����!!����!!\n";
}

//--- �L�ɖ����� ---//
void cat(void)
{
	cout << "�j����!!�j����!!\n";
}

//--- ���ɖ����� ---//
void monkey(void)
{
	cout << "�L�b�L�b!!\n";
}

//--- ���j���[�I�� ---//
menu SelectMenu(void)
{
	int	 ch;

	do {
		cout << "(�O) �I�@��@��\n";
		cout << "(�P) ���̖���\n";
		cout << "(�Q) �L�̖���\n";
		cout << "(�R) ���̖���\n";
		cin >> ch;
	} while (ch < Termination || ch >= Invalid);
	return (menu(ch));				// int�^ch�̒l��menu�^�ɃL���X�g���ĕԋp
}

//--- ���C�� ---//
int main(void)
{
	menu  menu;

	do {
		switch (menu = SelectMenu()) {
		 case Dog:   dog(); break;			// �ǉ�����
		 case Cat:   cat(); break;			// �폜����
		 case Mokey: monkey();  break;		// �\������
		}
	} while (menu != Termination);

	return (0);
}

/*
���s��
(�O) �I�@��@��
(�P) ���̖���
(�Q) �L�̖���
(�R) ���̖���
1��
����!!����!!
(�O) �I�@��@��
(�P) ���̖���
(�Q) �L�̖���
(�R) ���̖���
2��
�j����!!�j����!!
(�O) �I�@��@��
(�P) ���̖���
(�Q) �L�̖���
(�R) ���̖���
3��
�L�b�L�b!!
(�O) �I�@��@��
(�P) ���̖���
(�Q) �L�̖���
(�R) ���̖���
0��
*/

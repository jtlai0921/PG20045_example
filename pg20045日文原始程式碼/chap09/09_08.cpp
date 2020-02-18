#include	<iostream.h>

typedef enum {
	Termination, Dog, Cat, Mokey, Invalid
} menu;

typedef void (*mfunc)(void);

//--- ���̖��� ---//
void dog(void)
{
	cout << "����!!����!!\n";    
}

//--- �L�̖��� ---//
void cat(void)
{
	cout << "�j����!!�j����!!\n";
}

//--- ���̖��� ---//
void monkey(void)
{
	cout << "�L�b�L�b!!\n";
}

//--- ���j���[�I�� ---//
menu SelectMenu(void)
{
	int		ch;

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
	menu   menu;
	mfunc  panimal[] = { dog, cat, monkey };

	do {
		menu = SelectMenu();
		if (menu > Termination || menu < Invalid)
			panimal[menu - 1]();
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
/*
	�W�����P���Q�[���i���o�͊֌W�j"io.c"
*/

#include		<iostream.h>

extern int  draw;

static void inp_message(void)
{
	if (!draw)
		cout << "�W�����P���ۂ�\n";
	else
		cout << "�������ŃV��\n";
	cout << "(0)�ް (1)��� (2)�߰:";
}

int input(void)     //-- ���� --//
{
	int kazu;
	do {
		inp_message();
		cin >> kazu;
	} while (kazu < 0 || kazu > 2);
	return (kazu);
}

void display(int comp)
{
	cout << "�R���s���[�^��";
	switch (comp) {
	 case 0: cout << "�ް"; break;
	 case 1: cout << "���"; break;
	 case 2: cout << "�߰"; break;
	}
	cout << "�ł��B\n"; 
}

int cont_game(void)//-- ���s�̊m�F --//
{
	int cont;
	cout << "������x���܂����H\n"
		 << "<Yes��1�^No��0>�F";
	cin >> cont;
	return (cont);
}


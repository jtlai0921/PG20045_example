/*
	�p���Ńy�b�g���`���X�g�N���XPetList �|���p��|
*/

#include	<iostream.h>

#include	"petlist.h"

enum Menu {
	Terminate, Insert, Append, DspFirst, DspLast, Delete, Remove, Clear,
	Print, Intro, MenuOver
};

//----- �f�[�^���� -----//
Pet* AllocPet(void)
{
	int		kind;
	Pet*	ptr;

	do {
		cout << "��� �y0����, 1���L, 2�����z : ";
		cin >> kind;
	} while (kind < 0 || kind > 2);
	switch (kind) {
	 case 0 : ptr = new Pdog();     break;
	 case 1 : ptr = new Pcat();     break;
	 case 2 : ptr = new Pmonkey();  break;
	}
	return (ptr);
}

Menu SelectMenu(void)		//----- ���j���[�I�� -----//
{
	int		ch;

	do {
		cout << "(1) �擪�ɑ}��  (2) �����ɒǉ�  "
		     << "(3) �擪��\��  (4) ������\��\n";
		cout << "(5) �擪���폜  (6) �������폜  "
		     << "(7) �S�Ă��폜  (8) �S�Ă�\��\n";
		cout << "(9) ���X�g�����ȏЉ�  (0) �I��\n";
		cin >> ch;
	} while (ch < Terminate || ch >= MenuOver);
	return (Menu(ch));
}

int main(void)
{
	Menu	menu;
	PetList	list;

	do {
		menu = SelectMenu();
		switch (menu) {
		 PetNode* p;
		 case Insert  :	{	cout << "�擪�ɑ}������f�[�^����͂���\n";
							Pet* x = AllocPet();
							x->Input();
							PetNode* n = new PetNode(x);
							list.Insert(n);
						} break;

		 case Append  :	{	cout << "�����ɒǉ�����f�[�^����͂���\n";
							Pet* x = AllocPet();
							x->Input();
							PetNode* n = new PetNode(x);
							list.Append(n);
						} break;

		 case DspFirst: if (p = list.Top())
							((Pet*)*p)->Sintro(); break;

		 case DspLast : if (p = list.Top())
							((Pet*)*p)->Sintro(); break;

		 case Delete  : list.Delete(); break;
		 case Remove  : list.Remove(); break;
		 case Clear   : list.Clear();  break;
		 case Print   : cout << list;  break;
		 case Intro   : list.Introduce(); break;
		}
	} while (menu != Terminate);

	return (0);
}

/*
���s��
(1) �擪�ɒǉ�  (2) �����ɒǉ�  (3) �擪��\��  (4) ������\��
(5) �擪���폜  (6) �������폜  (7) �S�Ă��폜  (8) �S�Ă�\��
(9) ���X�g�����ȏЉ�  (0) �I��
1��
�擪�ɑ}������f�[�^����͂���
��� �y0����, 1���L, 2�����z : 1��
���O : Michael��
(1) �擪�ɒǉ�  (2) �����ɒǉ�  (3) �擪��\��  (4) ������\��
(5) �擪���폜  (6) �������폜  (7) �S�Ă��폜  (8) �S�Ă�\��
(9) ���X�g�����ȏЉ�  (0) �I��
1��
�擪�ɑ}������f�[�^����͂���
��� �y0����, 1���L, 2�����z : 0��
���O : Taro��
��� : �G�큥
(1) �擪�ɒǉ�  (2) �����ɒǉ�  (3) �擪��\��  (4) ������\��
(5) �擪���폜  (6) �������폜  (7) �S�Ă��폜  (8) �S�Ă�\��
(9) ���X�g�����ȏЉ�  (0) �I��
2��
�����ɒǉ�����f�[�^����͂���
��� �y0����, 1���L, 2�����z : 2��
���O : Jiro��
�N�� : 10��
(1) �擪�ɒǉ�  (2) �����ɒǉ�  (3) �擪��\��  (4) ������\��
(5) �擪���폜  (6) �������폜  (7) �S�Ă��폜  (8) �S�Ă�\��
(9) ���X�g�����ȏЉ�  (0) �I��
8��
{
	{ Taro }
	{ Michael }
	{ Jiro }
}
(1) �擪�ɒǉ�  (2) �����ɒǉ�  (3) �擪��\��  (4) ������\��
(5) �擪���폜  (6) �������폜  (7) �S�Ă��폜  (8) �S�Ă�\��
(9) ���X�g�����ȏЉ�  (0) �I��
9��
<<---------------- ���ȏЉ� ---------------->>
�l�͎G���Taro������!!
�l�̖��O��Michael���j����!!
�l��10�΂�Jiro���L�b!!
<<------------------------------------------>>
(1) �擪�ɒǉ�  (2) �����ɒǉ�  (3) �擪��\��  (4) ������\��
(5) �擪���폜  (6) �������폜  (7) �S�Ă��폜  (8) �S�Ă�\��
(9) ���X�g�����ȏЉ�  (0) �I��
0��
*/

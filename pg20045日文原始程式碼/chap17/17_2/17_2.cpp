/*
	�p���Ńy�b�g�N���XPet �|���p��|
*/

#include	"pet.h"

int main(void)
{
	const int  max = 10;		// �y�b�g�̍ő吔
	int		i;
	int		no;					// �y�b�g�̐�
	Pet*	MyPet[max];			// �y�b�g�ւ̃|�C���^�̔z��
	int		kind;				// ���

	cout << "�y�b�g�͉��C�ł����H ( 1 �� " << max << " ) : ";
	do {
		cin >> no;
	} while (no < 1 || no > max);

	for (i = 0; i < no; i++) {					// �f�[�^����
		cout << i + 1 << "�C�ڂ̃f�[�^����͂���\n";
		do {
			cout << "��� �y0����, 1���L, 2�����z : ";
			cin >> kind;
		} while (kind < 0 || kind > 2);
		switch (kind) {
		 case 0 : MyPet[i] = new Pdog();     break;
		 case 1 : MyPet[i] = new Pcat();     break;
		 case 2 : MyPet[i] = new Pmonkey();  break;
		}
		MyPet[i]->Input();
	}

	cout << "\n�l�̃y�b�g�̈ꗗ�\\n";				// �ꗗ�\
	for (i = 0; i < no; i++)
		cout << *MyPet[i] << '\n';

	cout << "\n�݂�ȂɎ��ȏЉ�������܂��B\n";		// ���ȏЉ�
	for (i = 0; i < no; i++)
		MyPet[i]->Sintro();

	for (i = 0; i < no; i++)
		delete MyPet[i];

	return (0);
}

/*
���s��
�y�b�g�͉��C�ł����H ( 1 �� 10 ) : 3��
1�C�ڂ̃f�[�^����͂���
��� �y0����, 1���L, 2�����z : 0��
���O : Taro��
��� : �G�큥
2�C�ڂ̃f�[�^����͂���
��� �y0����, 1���L, 2�����z : 1��
���O : Michael��
3�C�ڂ̃f�[�^����͂���
��� �y0����, 1���L, 2�����z : 2��
���O : Jiro��
�N�� : 10��
�l�̃y�b�g�̈ꗗ�\
{ Taro }
{ Michael }
{ Jiro }

�݂�ȂɎ��ȏЉ�������܂�
�l�͎G���Taro������!!
�l�̖��O��Michael���j����!!
�l��10�΂�Jiro���L�b!!
*/

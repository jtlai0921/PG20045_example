/*
	��s�����N���X Kouza�@�| ���p�� �|
*/

#include	<iostream.h>

#include	"kouza.h"

int main(void)
{
	Kouza	Nozawa(1234569,  0, 1991, 1, 1);
	Kouza	Miyata(3468924, 10, 1992, 2, 2);

	Nozawa.Ireru(100);		// ���N��100�~�a����

	Miyata.Orosu(5);			// �{�c�N��5�~�����o��

	cout << "���N�̌���\n";
	cout << "�����ԍ���" << Nozawa.KouzaNo()  << '\n';
	cout << "�a �� �z��" << Nozawa.Yokingaku() << "�~\n";
	cout << "�J �� ����" << Nozawa.Kaisetsubi() << '\n';

	cout << "�{�c�N�̌���\n";
	cout << "�����ԍ���" << Miyata.KouzaNo()  << '\n';
	cout << "�a �� �z��" << Miyata.Yokingaku() << "�~\n";
	cout << "�J �� ����" << Miyata.Kaisetsubi() << '\n';

	return (0);
}

/*
���s����
���N�̌���
�����ԍ���1234569
�a �� �z��100�~
�J �� ����1991�N1��1��
�{�c�N�̌���
�����ԍ���3468924
�a �� �z��5�~
�J �� ����1992�N2��2��
*/

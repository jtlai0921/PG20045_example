#include	<except.h>
#include	<iostream.h>
#include	<new.h>
int main(void)
{
	int	  asize;
	int	  i;
	int*  a;

	cout << "��������z��̗v�f������͂��Ă��������F";
	cin >> asize;

	try {
		a = new int[asize];
	}

	catch (xalloc) {
		cout << "�������̊m�ۂ��ł��܂���̂ŁA�v���O�������I�����܂��B\n";
		return (1);										// �ُ�I��
	}

	for (i = 0; i < asize; i++)
		a[i] = i;

	for (i = 0; i < asize; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';

	delete[] a;

	return (0);											// ����I��
}

/*
���s��i1�j
��������z��̗v�f������͂��Ă��������F3000��
�������̊m�ۂ��ł��܂���̂ŁA�v���O�������I�����܂��B
���s��i2�j
��������z��̗v�f������͂��Ă��������F3��
a[0] = 0
a[1] = 1
a[2] = 2
*/

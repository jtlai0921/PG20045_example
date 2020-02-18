#include	<iostream.h>

typedef int (*func)(int ,int);

//--- b > a�ł����1���A�����łȂ����0��ԋp --//
int int_cmp(int a, int b)
{
	return (a > b);
}

//--- a > b�ł����1���A�����łȂ����0��ԋp --//
int int_rcmp(int a, int b)
{
	return (a < b);
}

//--- ����a��b�̒l������ ---//
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//--- �v�f��n�̔z��a���֐�cmp�ł̔�r����Ƀ\�[�g���� ---//
void sort(int* a, int n, int (*cmp)(int ,int))
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if ((*cmp)(a[i], a[j]))
				swap(a[i], a[j]);
}

int main(void)
{
	char  cont;											// �����𑱍s���邩

	do {
		int  size;
		cout << "�z��̑傫������͂��Ă��������F";
		cin >> size;

		int*  a = new int[size];						// �z��𐶐�

		for (int i = 0; i < size; i++) {				// �e�v�f�̒l��ǂݍ���
			cout << "a[" << i << "] = ";
			cin >> a[i];
		}

		do {
			int	 asc;									// �������邢�͍~��

			cout << "�����Ƀ\�[�g(0) �~���Ƀ\�[�g(1)�F";
			cin >> asc;

			if (!asc)
				sort(a, size, int_cmp);					// �����Ƀ\�[�g
			else
				sort(a, size, int_rcmp);				// �~���Ƀ\�[�g

			cout << "�\�[�g��F\n";
			for (int i = 0; i < size; i++)
				cout << "a[" << i << "] = " << a[i] << '\n';

			cout << "������x�\�[�g���܂����H�i�x�^�m�j";
			cin >> cont;
		} while (cont == 'Y' || cont  == 'y');

		delete[] a;										// �z�������

		cout << "�z���ύX���Ă�蒼���܂����H�i�x�^�m�j";
		cin >> cont;
	} while (cont == 'Y' || cont  == 'y');

	return (0);
}

/*
���s��
�z��̑傫������͂��Ă��������F3��
a[0] = 4��
a[1] = 8��
a[2] = 5��
������x�\�[�g���܂����H�i�x�^�m�jy��
�����Ƀ\�[�g(0)�~���Ƀ\�[�g(1)�F0��
a[0] = 4
a[1] = 5
a[2] = 8
������x�\�[�g���܂����H�i�x�^�m�jy��
�����Ƀ\�[�g(0)�~���Ƀ\�[�g(1)�F1��
a[0] = 8
a[1] = 5
a[2] = 4
������x�\�[�g���܂����H�i�x�^�m�jn��
�z���ύX���Ă�蒼���܂����H�i�x�^�m�jy��
�z��̑傫������͂��Ă��������F5��
a[0] = 5��
a[1] = 4��
a[2] = 8��
a[3] = 6��
a[4] = 7��
�����Ƀ\�[�g(0)�~���Ƀ\�[�g(1)�F0��
a[0] = 4
a[1] = 5
a[2] = 6
a[3] = 7
a[4] = 8
������x�\�[�g���܂����H�i�x�^�m�jn��
�z���ύX���Ă�蒼���܂����H�i�x�^�m�jn��
*/

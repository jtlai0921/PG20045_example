#include	<string.h>
#include	<iostream.h>

int main(void)
{
	int	 i;
	int	 smax;

	cout << "������͂�������܂����F";
	cin >> smax;

	char**  a = new char*[smax];			// char�ւ̃|�C���^�̔z��𐶐�
	for (i = 0; i < smax; i++) {
		char  s[1024];
		cout << "a[" << i << "] = ";
		cin >> s;
		a[i] = new char[strlen(s) + 1];		// ������̒����̕�����������𐶐�
		strcpy(a[i], s);						// ��������R�s�[
	}

	cout << "�z��̊e�v�f�F\n";
	for (i = 0; i < smax; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';

	for (i = 0; i < smax; i++)				// �e�v�f�̎w�������������
		delete[] a[i];
	delete[] a;								// �z�������

	return (0);
}

/*
���s����
������͂�������܂����F3��
a[0] = Turbo��
a[1] = NA��
a[2] = DOHC��
�z��̊e�v�f�F
a[0] = Turbo
a[1] = NA
a[2] = DOHC
*/

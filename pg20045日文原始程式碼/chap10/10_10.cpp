#include	<iostream.h>

const int  smax = 3;
const int  slen = 6;

int main(void)
{
	char   s[smax][slen] = {"March", "iz", "HK13"};

	char*  p[smax] = {"March", "iz", "HK13"};

	cout << "�����z��̔z��\n";
	for (int i = 0; i < smax; i++)
		cout << s[i] << '\n';

	cout << "�|�C���^�̔z��\n";
	for (i = 0; i < smax; i++)
		cout << p[i] << '\n';

	return (0);
}

/*
���s����
�����z��̔z��
March
iz
HK13
�|�C���^�̔z��
March
iz
HK13
*/

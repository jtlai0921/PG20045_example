#include	<iostream.h>

int main(void)
{
	char  c;
	int	 cnt[10] = {0};	// �z��cnt�̑S�v�f��0�ŏ�����

	while (cin.get(c)) {
		if (c >= '0' && c <= '9')
			cnt[c - '0']++;      
	}

	for (int i = 0; i < 10; i++)
		cout << i << "�̏o���񐔁F" << cnt[i] << '\n';

	return (0);
}

/*
���s��
3.1415926535897��
Ctrl+Z��
0�̏o���񐔁F0
1�̏o���񐔁F2
2�̏o���񐔁F1
3�̏o���񐔁F2
4�̏o���񐔁F1
5�̏o���񐔁F3
6�̏o���񐔁F1
7�̏o���񐔁F1
8�̏o���񐔁F1
9�̏o���񐔁F2
*/

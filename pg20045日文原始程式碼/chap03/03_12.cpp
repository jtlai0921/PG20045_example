#include	<iostream.h>

int main(void)
{
	char  c;
	int	 cnt[10] = {0};

	while (cin.get(c)) {
		if (c >= '0' && c <= '9')
			cnt[c - '0']++;
	}

	cout << "�e�����̏o����\n";
	for (int i = 0; i < 10; i++) {
		cout << i << " : ";
		for (int j = 0; j < cnt[i]; j++)
			cout << '*';
		cout << '\n';
	}

	return (0);
}

/*
���s��
3.1415926535897932��
Ctrl+Z��
�e�����̏o����
0 : 
1 : **
2 : **
3 : ****
4 : **
5 : ***
6 : **
7 : *
8 : **
9 : ***
*/

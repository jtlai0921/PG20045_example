#include	<iostream.h>

int main(void)
{
	char c;
	int	 i;
	int	 cnt[10] = {0};

	while (cin.get(c)) {
		if (c >= '0' && c <= '9')
			cnt[c - '0']++;
	}

	int	 max = cnt[0];					// �o���񐔂̍ő�l�����߂�
	for (i = 1; i < 10; i++)
		if (max < cnt[i]) max = cnt[i];

	for (i = max ; i > 0; i--) {
		for (int j = 0; j < 10; j++) { 
			if (cnt[j] >= i)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << '\n';
	}
	for (i = 0; i < 10; i++)		// �Ή����鐔����\��
		cout << i << ' ';
	cout << '\n';

	return (0);
}

/*
���s��
3.1415926535897932��
Ctrl+Z��
      *   *       *
  * * *   *       *
  * * * * * * * * *
0 1 2 3 4 5 6 7 8 9
*/

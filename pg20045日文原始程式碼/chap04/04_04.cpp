#include	<iostream.h>

int main(void)
{
	int	 cnt = 1;			// �J��Ԃ��̉�
	int	 num = 2;			// �Q�ׂ̂���

	while (num < 10000) {
		cout.width(5);
		cout << num;
		num *= 2;
		if (!(cnt % 4))
			cout << '\n';
		cnt++;
	}

	return (0);
}

/*
���s����
    2    4    8   16
   32   64  128  256
  512 1024 2048 4096
 8192
*/

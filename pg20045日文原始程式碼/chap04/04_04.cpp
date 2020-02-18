#include	<iostream.h>

int main(void)
{
	int	 cnt = 1;			// 繰り返しの回数
	int	 num = 2;			// ２のべき乗

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
実行結果
    2    4    8   16
   32   64  128  256
  512 1024 2048 4096
 8192
*/

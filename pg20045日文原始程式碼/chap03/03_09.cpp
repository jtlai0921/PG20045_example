#include	<iostream.h>

int main(void)
{
	int	 i;
	int	 a[10];

	for (i = 0; i < 10; i++)	// 先頭から順に1, 2, …を入れる
		a[i] = i + 1;

	for (i = 0; i < 10; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';

	return (0);
}

/*
実行例
a[0] = 1
a[1] = 2
    ：
 【中略】
    ：
a[9] = 10
*/

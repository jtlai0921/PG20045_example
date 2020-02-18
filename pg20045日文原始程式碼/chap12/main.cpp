/*
	座標クラス Position 第２版 －利用例１－					"main.c"
*/

#include	<iostream.h>

#include	"position.h"

int main(void)
{
	const int max = 5;
	Position  a[max];				// Positionの配列を宣言

	for (int i = 0; i < max; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';

	return (0);
}

/*
実行結果
a[0] = (0, 0)
a[1] = (0, 0)
a[2] = (0, 0)
a[3] = (0, 0)
a[4] = (0, 0)
*/

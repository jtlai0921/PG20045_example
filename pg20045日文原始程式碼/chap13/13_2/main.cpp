/*
	カウンタクラス Counter 　－ 利用例 －
*/

#include	<iostream.h>

#include	"counter.h"

int main(void)
{
	Counter	x, y;

	for (int i = 0; i < 5; i++)				// カウントアップ
		cout << x++ << ' ' << ++y << '\n';

	while (x)								// カウントダウン
		cout << x-- << ' ' << --y << '\n';

	return (0);
}

/*
実行結果
0 1
1 2
2 3
3 4
4 5
5 4
4 3
3 2
2 1
1 0
*/

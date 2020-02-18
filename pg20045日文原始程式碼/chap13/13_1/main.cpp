/*
	カウンタクラス Counter 第１版　－ 利用例 －				"main.c"
*/

#include	<iostream.h>

#include	"counter.h"

int main(void)
{
	Counter x;
	int     i;

	for (i = 0; i < 5; i++) {
		x.Increment();					// カウントアップ
		cout << x.Value() << '\n';
	}

	for (i = 0; i < 2; i++) {
		x.Decrement();					// カウントダウン
		cout << x.Value() << '\n';
	}

	return (0);
}

/*
実行結果
1
2
3
4
5
4
3
*/

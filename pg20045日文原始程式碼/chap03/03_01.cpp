#include	<iostream.h>

int main(void)
{
	char  c;

	while (cin.get(c))	// 次の１文字を読み込む
		cout << c;		// 読み込んだ文字を出力する

	return (0);
}

/*
実行結果一例
This is a pen.▼
This is a pen.
I go to school everyday.▼
I go to school everyday.
Are you ready?▼
Are you ready?
Ctrl+Z
*/

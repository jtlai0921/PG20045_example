#include	<iostream.h>

int main(void)
{
	char  c;

	while (cin.get(c))
		if (c == '\n')			// 改行文字であれば…
			cout << "[RET]\n";
		else						// そうでなければ…
			cout << c;

	return (0);
}

/*
実行結果一例
This is pen.▼
This is pen.
Are you ready?▼
Are you ready?
Ctrl+Z
*/
#include	<iostream.h>

int main(void)
{
	char c;
	int	 ccount = 0;		// 文字数
	int	 ncount = 0;		// 改行数

	while (cin.get(c)) {
		ccount++;
		if (c == '\n')
			ncount++;
	}
	cout << "文字数＝" << ccount << '\n';
	cout << "改行数＝" << ncount << '\n';

	return (0);
}

/*
実行例
Are you ready?▼
Yes, OK!▼
Ctrl+Z
文字数＝24
改行数＝2
*/
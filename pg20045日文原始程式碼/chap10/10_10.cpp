#include	<iostream.h>

const int  smax = 3;
const int  slen = 6;

int main(void)
{
	char   s[smax][slen] = {"March", "iz", "HK13"};

	char*  p[smax] = {"March", "iz", "HK13"};

	cout << "文字配列の配列\n";
	for (int i = 0; i < smax; i++)
		cout << s[i] << '\n';

	cout << "ポインタの配列\n";
	for (i = 0; i < smax; i++)
		cout << p[i] << '\n';

	return (0);
}

/*
実行結果
文字配列の配列
March
iz
HK13
ポインタの配列
March
iz
HK13
*/

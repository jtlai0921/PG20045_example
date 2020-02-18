#include	<string.h>
#include	<iostream.h>

//--- 文字列strの長さを返却する ---//
size_t strlength(const char* str)
{
	size_t  len = 0;

	while (*str++)
		len++;
	return (len);
}

int main(void)
{
	char  x[100];

	cout << "文字列を入力してください：";
	cin >> x;

	cout << "文字列" << x << "の長さ：" << strlength(x) << '\n';

	return (0);
}

/*
実行例
文字列を入力してください：Hello▼
文字列Helloの長さ：5
*/

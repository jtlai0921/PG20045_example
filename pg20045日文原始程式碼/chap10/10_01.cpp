#include	<iostream.h>

//--- 文字列strの長さを返却する ---//
int strlength(char str[])
{
	int  len = 0;

	while (str[len])                                                          
		len++;                                                                 
	return (len);
}

int main(void)
{
	char  x[6] = "ABCDE";
	char  y[]  = "123";

	cout << "文字列x (\"" << x << "\")の長さ：" << strlength(x) << '\n';
	cout << "文字列y (\"" << y << "\")の長さ：" << strlength(y) << '\n';

	return (0);
}

/*
実行結果
文字列x ("ABCDE")の長さ：5
文字列y ("123")の長さ：3
*/

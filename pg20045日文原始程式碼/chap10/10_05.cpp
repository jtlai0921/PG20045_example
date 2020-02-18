#include	<iostream.h>

//--- 文字列srcをdstに複写する ---//
void strcopy(char dst[], const char src[])
{
    for (int len = 0; dst[len] = src[len]; len++)                            
		;                                                                      
}

int main(void)
{
	char  x[100];
	char  y[100];

	cout << "文字列xを入力してください：";
	cin >> x;

	strcopy(y, x);
	cout << "文字列yは" << y << "です。\n";

	return (0);
}

/*
実行例
文字列xを入力してください：shibata▼
文字列yはshibataです。
*/

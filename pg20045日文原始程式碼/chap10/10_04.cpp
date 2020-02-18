#include	<string.h>
#include	<iostream.h>

//--- 文字列strを表示 ---//
void putstring(const char str[])
{
	for (int i = 0; str[i] != '\0'; i++)
		cout << str[i];
}

//--- 文字列strを後ろから逆順に表示 ---//
void putreverse(const char str[])
{
	for (int i = strlen(str) - 1; i >= 0; i--)
		cout << str[i];
}

int main(void)
{
	char	str[100];

	cout << "文字列を入力してください：";
	cin >> str;

	cout << "通常の表示：";		putstring(str);		cout << '\n';
	cout << "逆順の表示：";		putreverse(str);	cout << '\n';

	return (0);
}

/*
実行例
文字列を入力してください：12345▼
12345
54321
*/


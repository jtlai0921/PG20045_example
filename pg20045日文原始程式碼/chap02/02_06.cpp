#include	<iostream.h>

int main(void)
{
	int	 month;

	cout << "月を入力してください：";
	cin >> month;

	if (month >= 3 && month <= 5)
		cout << month << "月は春です。\n";
	else if (month >= 6 && month <= 8)
		cout << month << "月は夏です。\n";
	else if (month >= 9 && month <= 11)
		cout << month << "月は秋です。\n";
	else
		cout << month << "月は冬です。\n";

	return (0);
}

/*
実行例
月を入力してください：3▼
3月は春です。
*/

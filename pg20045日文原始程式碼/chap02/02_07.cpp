#include	<iostream.h>

int main(void)
{
	int	 month;

	cout << "月を入力してください：";
	cin >> month;

	cout << month << "月は";

	if (month == 2)
		cout << "28日か29日です。\n";
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		cout << "30日です。\n";
	else
		cout << "31日です。\n";

	return (0);
}

/*
実行例（1）
月を入力してください：2▼
2月は28日か29日です。
実行例（2）
月を入力してください：5▼
5月は31日です。
*/
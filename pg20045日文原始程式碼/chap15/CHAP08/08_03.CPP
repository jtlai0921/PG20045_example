#include	<iostream.h>

//--- yearが閏年であれば1を、そうでなければ0を返却する ---//
int isleap(int year)
{
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int main(void)
{
	int	 year;

	cout << "年を西暦で入力して下さい：";
	cin >> year;

	if (isleap(year))
		cout << year << "年は閏年です。\n";
	else
		cout << year << "年は閏年ではありません。\n";

	return (0);
}

/*
実行例（1）
年を西暦で入力して下さい：1997▼
1997年は閏年ではありません。
実行例（2）
年を西暦で入力して下さい：1992▼
1992年は閏年です。
*/

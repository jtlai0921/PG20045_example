#include	<iostream.h>

//--- 引数x, yを入れ換える ---//
void swap(int& x, int& y)
{
	int	 temp = x;
	x = y;
	y = temp;
}

//--- a, bを昇順に並べる ---//
void sort(int& a, int& b)
{
	if (a > b)
		swap(a, b);
}

int main(void)
{
	int		a, b;

	cout << "整数ａの値を入力せよ：";
	cin >> a;

	cout << "整数ｂの値を入力せよ：";
	cin >> b;

	sort(a, b);

	cout << "整数ａ，ｂを昇順に並び換えました。\n";
	cout << "ａの値は" << a << "です。\n";
	cout << "ｂの値は" << b << "です。\n";

	return (0);
}

/*
実行例（1）
整数ａの値を入力せよ：10▼
整数ｂの値を入力せよ：20▼
整数ａ，ｂを昇順に並び換えました。
ａの値は10です。
ｂの値は20です。

実行例（2）
整数ａの値を入力せよ：10▼
整数ｂの値を入力せよ：5▼
整数ａ，ｂを昇順に並び換えました。
ａの値は5です。
ｂの値は10です。
*/

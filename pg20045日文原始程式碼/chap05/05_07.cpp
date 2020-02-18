#include	<iostream.h>

//--- 引数x, yを入れ換える ---//
void swap(int& x, int& y)
{
	int	 temp = x;
	x = y;
	y = temp;
}

//--- ３つの引数a, b, cを昇順に並べる ---//
void sort(int& a, int& b, int& c)
{
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
}

int main(void)
{
	int		a, b, c;

	cout << "整数ａの値を入力してください：";
	cin >> a;

	cout << "整数ｂの値を入力してください：";
	cin >> b;

	cout << "整数ｃの値を入力してください：";
	cin >> c;

	sort(a, b, c);

	cout << "整数ａ,ｂ,ｃを昇順に並び換えました。\n";
	cout << "ａの値は" << a << "です。\n";
	cout << "ｂの値は" << b << "です。\n";
	cout << "ｃの値は" << c << "です。\n";

	return (0);
}

/*
実行例
整数ａの値を入力してください：10▼
整数ｂの値を入力してください：30▼
整数ｃの値を入力してください：20▼
整数ａ,ｂ,ｃを昇順に並び換えました。
ａの値は10です。
ｂの値は20です。
ｃの値は30です。
*/

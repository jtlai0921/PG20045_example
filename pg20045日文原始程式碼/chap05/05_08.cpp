#include	<iostream.h>

//--- 引数x, yの値を入れ換える ---//
void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

//--- ４つの引数a, b, c, dを昇順に並び換える ---//
void sort(int& a, int& b, int& c, int& d)
{
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (c > d) swap(c, d);					// d ← 最大値
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);					// c ← ２番目に大きい値
	if (a > b) swap(a, b);					// 並び換え完了
}

int main(void)
{
	int a, b, c, d;
	cout << "整数ａの値を入力してください：";	cin >> a;
	cout << "整数ｂの値を入力してください：";	cin >> b;
	cout << "整数ｃの値を入力してください：";	cin >> c;
	cout << "整数ｄの値を入力してください：";	cin >> d;

	sort(a, b, c, d);
	cout << "整数ａ,ｂ,ｃ,ｄを昇順に並び換えました。\n";
	cout << "ａの値は" << a << "です。\n";
	cout << "ｂの値は" << b << "です。\n";
	cout << "ｃの値は" << c << "です。\n";
	cout << "ｄの値は" << d << "です。\n";

	return (0);
}

/*
実行例
整数ａの値を入力してください：80▼
整数ｂの値を入力してください：95▼
整数ｃの値を入力してください：32▼
整数ｄの値を入力してください：100▼
整数ａ,ｂ,ｃ,ｄを昇順に並び換えました。
ａの値は32です。
ｂの値は80です。
ｃの値は95です。
ｄの値は100です。
*/

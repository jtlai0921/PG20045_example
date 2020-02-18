#include	<iostream.h>

//--- 引数x, yの値を入れ換える ---//
void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

int main(void)
{
	int a; 
	int b;

	cout << "整数ａの値を入力してください：";
	cin >> a;

	cout << "整数ｂの値を入力してください：";
	cin >> b;

	swap(a, b);

	cout << "整数ａとｂの値を入れ換えました。\n";
	cout << "ａの値は" << a << "です。\n";
	cout << "ｂの値は" << b << "です。\n";

	return (0);
}

/*
実行例
整数ａを入力してください：10▼
整数ｂを入力してください：25▼
整数ａとｂの値を入れ換えました。
ａの値は25です。
ｂの値は10です。
*/

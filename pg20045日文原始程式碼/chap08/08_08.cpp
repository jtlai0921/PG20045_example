#include	<iostream.h>

//--- 引数x, yの指す値を入れ換える ---//
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main(void)
{
	int a;
	int b;

	cout << "整数ａを入力してください：";
	cin >> a;

	cout << "整数ｂを入力してください：";
	cin >> b;

	swap(&a, &b);

	cout << "整数ａとｂの値を入れ換えました。\n";
	cout << "ａの値は" << a << "です。\n";
	cout << "ｂの値は" << b << "です。\n";

	return (0);
}

/*
実行例
整数ａを入力してください：100
整数ｂを入力してください：200
整数ａとｂの値を入れ換えました。
ａの値は200です。
ｂの値は100です。
*/

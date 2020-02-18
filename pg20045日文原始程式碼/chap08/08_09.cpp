#include	<iostream.h>

//--- 引数x, yの指す値を入れ換える ---//
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//--- 引数x, yの指す値を昇順に並び換える ---//
void sort(int* x, int* y)
{
	if (*x > *y)
		swap(x, y);
}

int main(void)
{
	int a;
	int b;

	cout << "整数ａを入力してください：";
	cin >> a;

	cout << "整数ｂを入力してください：";
	cin >> b;

	sort(&a, &b);

	cout << "整数ａとｂの値を昇順に並び換えました。\n";
	cout << "ａの値は" << a << "です。\n";
	cout << "ｂの値は" << b << "です。\n";

	return (0);
}

/*
実行例（1）
整数ａを入力してください：200
整数ｂを入力してください：100
整数ａとｂの値を昇順に並び換えました。
ａの値は100です。
ｂの値は200です。

実行例（2）
整数ａを入力してください：5
整数ｂを入力してください：10
整数ａとｂの値を昇順に並び換えました。
ａの値は5です。
ｂの値は10です。
*/

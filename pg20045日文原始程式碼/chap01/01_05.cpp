#include	<iostream.h>

int main(void)
{
	double  x, y;		// 浮動小数点型

	cout << "ｘを入力してください：";			// ｘの入力をうながす
	cin >> x;									// ｘに実数を読み込む

	cout << "ｙを入力してください：";			// ｙの入力をうながす
	cin >> y;									// ｙに実数を読み込む

	cout << "x + y = " << x + y << "\n";		// 和
	cout << "x - y = " << x - y << "\n";		// 差
	cout << "x * y = " << x * y << "\n";		// 積
	cout << "x / y = " << x / y << "\n";		// 商

	return (0);
}


/*
実行例
ｘを入力してください：15▼
ｙを入力してください：5▼
x + y = 20
x - y = 10
x * y = 75
x / y = 3
*/

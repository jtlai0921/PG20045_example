#include	<iostream.h>

int main(void)
{
	int	 a;

	cout << "整数値を入力せよ：";
	cin >> a;

	switch (a) {
	 case  0: cout << "０です。\n";    break;
	 default: cout << "非０です。\n";  break;
	}

	return (0);
}

/*
実行例（1）
整数値を入力せよ：4▼
非０です。
実行例（2）
整数値を入力せよ：0▼
０です。
*/

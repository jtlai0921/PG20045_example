#include	<iostream.h>

int main(void)
{
	int	 a, b;

	cout << "整数値ａを入力せよ：";
	cin >> a;

	cout << "整数値ｂを入力せよ：";
	cin >> b;

	if (a < b)
		cout << "ａはｂより小さいです。\n";
	else if (a > b)
		cout << "ａはｂより大きいです。\n";
	else
		cout << "ａとｂは等しいです。\n";

	return (0);
}

/*
実行例（1）
整数値ａを入力せよ：5▼
整数値ｂを入力せよ：519▼
ａはｂより小さいです。
実行例（2）
整数値ａを入力せよ：51▼
整数値ｂを入力せよ：50▼
ａはｂより大きいです。
実行例（3）
整数値ａを入力せよ：35▼
整数値ｂを入力せよ：35▼
ａとｂは等しいです。
*/
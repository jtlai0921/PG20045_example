#include	<iostream.h>

//--- x時y分のdy分後を求める ---//
void spend(int& x, int& y, int dy)
{
	y += dy;
	x = (x + y / 60) % 24;
	y %= 60;
}

int main(void)
{
	int		h, m, n;

	cout << "何時ですか：";
	cin >> h;

	cout << "何分ですか：";
	cin >> m;

	cout << "何分後の時刻を知りたいですか：";
	cin >> n;

	spend(h, m, n);

	cout << n << "分後は" << h << "時" << m << "分です。\n";

	return (0);
}

/*
実行例（1）
何時ですか：23▼
何分ですか：45▼
何分後の時刻を知りたいですか：25▼
25分後は0時10分です。

実行例（2）
何時ですか：8▼
何分ですか：15▼
何分後の時刻を知りたいですか：90▼
90分後は9時45分です。
*/

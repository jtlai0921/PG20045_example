/*
	整数配列クラス IntAry　―利用例―
*/

#include	<iomanip.h>
#include	<iostream.h>

#include	"intary.h"

int main(void)
{
	int  i, n;

	cout << "現在のIntAryの数：" << IntAry::GetCount() << '\n';

	cout << "要素数を入力せよ：";
	cin >> n;

	IntAry  x(n);
	cout << "クラスIntAryのオブジェクトxを定義しました。\n";
	cout << "現在のIntAryの数：" << IntAry::GetCount() << '\n';

	for (i = 0; i < n; i++)
		x[i] = i;

	IntAry*  y = new IntAry(x);
	cout << "クラスIntAryのオブジェクトを動的に生成しました。\n";
	cout << "現在のIntAryの数：" << IntAry::GetCount() << '\n';

	cout << "    x    y\n";
	cout << "----------\n";
	for (i = 0; i < n; i++)
		cout << setw(5) << x[i] << setw(5) << y[i] << '\n';

	delete y;
	cout << "クラスIntAryのオブジェクトを消滅させした。\n";
	cout << "現在のIntAryの数：" << IntAry::GetCount() << '\n';

	return (0);
}


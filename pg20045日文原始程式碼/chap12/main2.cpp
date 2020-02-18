/*
	座標クラス Position 第２版 －利用例２－					"main.c"
*/

#include	<iostream.h>

#include	"position.h"

int main(void)
{
	const Position pos_O(0.0, 0.0);			// 原点
	Position  a(5.0, 6.0);					// 点aを(5.0, 6.0)で初期化

	cout << "原点 = " << pos_O << '\n';
	cout << "点ａ = " << a << "\n\n";

//	pos_O.Set(10.0, 5.0);					// エラー
	a.Set(-3.0, 2.0);						// 点aの座標を(-3.0, 2.0)に変更

	cout << "点ａを(-3.0, 2.0)に変更しました。\n\n";
	cout << "点ａ = " << a << '\n';

	return (0);
}

/*
実行結果
原点 = (0, 0)
点ａ = (5.0, 6.0)

点ａを(-3.0, 2.0)に変更しました。

点ａ = (-3.0, 2.0)
*/

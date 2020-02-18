/*
	座標クラス Position 第１版 －利用例２－					"main.c"
*/

#include	<iostream.h>

#include	"position.h"

int main(void)
{
	Position  a(0.0, 0.0);							// 点aを(0.0, 0.0)で初期化

	cout << "点a = (" << a.X() << ", " << a.Y() << ")\n";

	cout << "点aに(10.0, -10.0)を代入\n";

	a = Position(10.0, -10.0);						// 点aに(10.0, -10.0)を代入

	cout << "点a = (" << a.X() << ", " << a.Y() << ")\n";

	return (0);
}

/*
実行結果
点a = (0, 0)
点aに(10.0, -10.0)を代入
点a = (10, -10)
*/

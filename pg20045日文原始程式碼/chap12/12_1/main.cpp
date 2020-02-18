/*
	座標クラス Position 第１版 －利用例１－					"main.c"
*/

#include	<iostream.h>

#include	"position.h"

int main(void)
{
	Position  a(10.0, -10.0);				// 点aを(10.0, -10.0)で初期化

	Position  b = Position(3.5, 6.0);		// 点bを(-3.5, 6.0)で初期化

	cout << "点a = (" << a.X() << ", " << a.Y() << ")\n";
	cout << "点b = (" << b.X() << ", " << b.Y() << ")\n";

	return (0);
}

/*
実行結果
点a = (10, -10)
点b = (-3.5, 6)
*/


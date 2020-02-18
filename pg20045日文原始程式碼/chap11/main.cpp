/*
	クラスCar	−利用例−								"main.c"
*/

#include	<iostream.h>

#include	"car.h"

int main(void)
{
	Car   benz(90.0, 0.0, 0.0);
	char  cont;						// 処理を続行するか

	while (1) {
		cout << "現在地 ("      << benz.X() << ", "   << benz.Y()
			 << ") ／ 残り燃料 " << benz.Tank() << "リットル\n";

		cout << "移動しますか？（Ｙ／Ｎ）";
		cin >> cont;

		if (cont == 'N' || cont == 'n') break;

		double  dx, dy;
		cout << "ｘ方向の移動距離：";	cin >> dx;
		cout << "ｙ方向の移動距離：";	cin >> dy;

		if (!benz.Move(dx, dy))
			cout << "移動できません。\n";
	}

	return (0);
}

/*
実行例
現在地(0,0)／残り燃料90リットル
移動しますか？（Ｙ／Ｎ）y▼
ｘ方向の移動距離：20.0▼
ｙ方向の移動距離：15.0▼
現在地(20,15)／残り燃料65リットル
移動しますか？（Ｙ／Ｎ）y▼
ｘ方向の移動距離：-40.0▼
ｙ方向の移動距離：30.0▼
現在地(-20,45)／残り燃料15リットル
移動しますか？（Ｙ／Ｎ）y▼
ｘ方向の移動距離：10.0▼
ｙ方向の移動距離：-12.5▼
移動できません。
現在地(-20,45)／残り燃料15リットル
移動しますか？（Ｙ／Ｎ）n▼
*/


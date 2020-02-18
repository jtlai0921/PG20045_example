//-------------------------------------------------------------
//	車クラス Car （実現部）									"car.c" 
//

#include	<iostream.h>
#include	<math.h>

#include	"car.h"

//--- コンストラクタ ---//
Car::Car(double f, double x, double y) : point(x, y)
{
	fuel = f;
}

//--- ＸおよびＹ方向にそれぞれ(dx,dy)だけ移動 ---//
int Car::Move(double dx, double dy)
{
	double  dist = sqrt(dx * dx + dy * dy);			// 移動距離

	if (dist > fuel)
		return (0);									// 移動失敗
	else {
		point.Set(point.X() + dx, point.Y() + dy);
		fuel -= dist;
		return (1);									// 移動成功
	}
}

//--- 挿入演算子 ---//
ostream& operator<<(ostream& os, const Car& car)
{
	return (os << "現在地 " << car.Pos()
			   << "／ 残り燃料 " << car.Tank() << "リットル\n");
}


//------------------------------------------------------------------------
//	車クラス Car （実現部）									"car.c"  		//
//----------------------------------------------------------------------
#include	<math.h>

#include	"car.h"

//--- コンストラクタ ---//
Car::Car(double f, double x, double y)
{
	fuel = f;	xp = x;		yp = y;
}

//--- ＸおよびＹ方向にそれぞれ(dx,dy)だけ移動 ---//
int Car::Move(double dx, double dy)
{
	double  dist = sqrt(dx * dx + dy * dy);			// 移動距離

	if (dist > fuel)
		return (0);									// 移動失敗
	else {
		fuel -= dist;	xp += dx;	yp += dy;	
		return (1);									// 移動成功
	}
}


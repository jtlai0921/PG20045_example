//---------------------------------------------------------------------------
-//
//	車クラス Car （インタフェース部）						"car.h"			  
//
//---------------------------------------------------------------------------
-//

#include	"position.h"

class Car {

private:
	double    fuel;				// 残り燃料
	Position  point;				// 現在位置

public:
	Car(double f, double x, double y);					// コンストラクタ

	Position Pos(void) const { return (point); }		// 現在位置を返却
	double Tank(void)  const { return (fuel); }			// 残り燃料

	int Move(double dx, double dy);						// 移動
};

ostream& operator<<(ostream& os, const Car& car);		// 挿入演算子


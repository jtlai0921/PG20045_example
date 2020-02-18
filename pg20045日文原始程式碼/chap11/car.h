//-----------------------------------------------------------------------//
//	車クラス Car （インタフェース部）						"car.h"		
//
//----------------------------------------------------------------

class Car {

private:
	double  fuel;				// 残り燃料
	double  xp;					// 現在位置Ｘ座標
	double  yp;					// 現在位置Ｙ座標

public:
	Car(double f, double x, double y);		// コンストラクタ

	double X(void) { return (xp); }			// 現在位置Ｘ座標
	double Y(void) { return (yp); }			// 現在位置Ｙ座標
	double Tank(void) { return (fuel); }	// 残り燃料

	int Move(double dx, double dy);			// 移動
};


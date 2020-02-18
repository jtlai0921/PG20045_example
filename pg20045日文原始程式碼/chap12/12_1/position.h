//------------------------------------------------------------------------
//	座標クラス Position 第１版（インタフェース部）			"position.h"    //
//-----------------------------------------------------------------------

class Position {

private:
	double  xp;					// Ｘ座標
	double  yp;					// Ｙ座標

public:
	Position(double x, double y) { xp = x; yp = y; }	// コンストラクタ

	double X(void) { return (xp); }						// Ｘ座標を返却
	double Y(void) { return (yp); }						// Ｙ座標を返却

	void Set(double x, double y) { xp = x; yp = y; }	// 座標を(x,y)に設定
};


//-----------------------------------------------------------------------//
//	座標クラス Position 第２版（インタフェース部）			"position.h"    //
//-----------------------------------------------------------------------
#include	<iostream.h>

class Position {

private:
	double  xp;					// Ｘ座標
	double  yp;					// Ｙ座標

public:
	Position(void) { xp = 0.0; yp = 0.0; }			// デフォルトコンストラクタ
	Position(double x, double y = 0.0) { xp = x; yp = y; }	  // コンストラクタ

	double X(void) const { return (xp); }				// Ｘ座標を返却
	double Y(void) const { return (yp); }				// Ｙ座標を返却

	void Set(double x, double y)  { xp = x; yp = y; }	// 座標を(x,y)に設定
};

inline ostream& operator<<(ostream& os, const Position& pos)	// 挿入演算子
{
	return (os << '(' << pos.X() << ", " << pos.Y() << ')');
}


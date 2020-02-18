
#include	<iostream.h>

class Position {

private:
	double  xp;					//
	double  yp;					//

public:
	Position(void) { xp = 0.0; yp = 0.0; }			// 
	Position(double x, double y = 0.0) { xp = x; yp = y; }	  //

	double X(void) const { return (xp); }				// 
	double Y(void) const { return (yp); }				//

	void Set(double x, double y)  { xp = x; yp = y; }	//’è
};

inline ostream& operator<<(ostream& os, const Position& pos)	//
{
	return (os << '(' << pos.X() << ", " << pos.Y() << ')');
}



#include	"position.h"

class Car {

private:
	double    fuel;
	Position  point;

public:
	Car(double f, double x, double y);

	Position Pos(void) const { return (point); }
	double Tank(void)  const { return (fuel); }

	int Move(double dx, double dy);	
};

ostream& operator<<(ostream& os, const Car& car);		//


//------------------------------------------------------------------------
//	�ԃN���X Car �i�������j									"car.c"  		//
//----------------------------------------------------------------------
#include	<math.h>

#include	"car.h"

//--- �R���X�g���N�^ ---//
Car::Car(double f, double x, double y)
{
	fuel = f;	xp = x;		yp = y;
}

//--- �w����тx�����ɂ��ꂼ��(dx,dy)�����ړ� ---//
int Car::Move(double dx, double dy)
{
	double  dist = sqrt(dx * dx + dy * dy);			// �ړ�����

	if (dist > fuel)
		return (0);									// �ړ����s
	else {
		fuel -= dist;	xp += dx;	yp += dy;	
		return (1);									// �ړ�����
	}
}


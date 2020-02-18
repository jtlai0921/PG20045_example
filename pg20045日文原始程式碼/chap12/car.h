//---------------------------------------------------------------------------
-//
//	�ԃN���X Car �i�C���^�t�F�[�X���j						"car.h"			  
//
//---------------------------------------------------------------------------
-//

#include	"position.h"

class Car {

private:
	double    fuel;				// �c��R��
	Position  point;				// ���݈ʒu

public:
	Car(double f, double x, double y);					// �R���X�g���N�^

	Position Pos(void) const { return (point); }		// ���݈ʒu��ԋp
	double Tank(void)  const { return (fuel); }			// �c��R��

	int Move(double dx, double dy);						// �ړ�
};

ostream& operator<<(ostream& os, const Car& car);		// �}�����Z�q


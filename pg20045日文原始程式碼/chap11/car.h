//-----------------------------------------------------------------------//
//	�ԃN���X Car �i�C���^�t�F�[�X���j						"car.h"		
//
//----------------------------------------------------------------

class Car {

private:
	double  fuel;				// �c��R��
	double  xp;					// ���݈ʒu�w���W
	double  yp;					// ���݈ʒu�x���W

public:
	Car(double f, double x, double y);		// �R���X�g���N�^

	double X(void) { return (xp); }			// ���݈ʒu�w���W
	double Y(void) { return (yp); }			// ���݈ʒu�x���W
	double Tank(void) { return (fuel); }	// �c��R��

	int Move(double dx, double dy);			// �ړ�
};


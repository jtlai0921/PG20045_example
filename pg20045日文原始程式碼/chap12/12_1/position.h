//------------------------------------------------------------------------
//	���W�N���X Position ��P�Łi�C���^�t�F�[�X���j			"position.h"    //
//-----------------------------------------------------------------------

class Position {

private:
	double  xp;					// �w���W
	double  yp;					// �x���W

public:
	Position(double x, double y) { xp = x; yp = y; }	// �R���X�g���N�^

	double X(void) { return (xp); }						// �w���W��ԋp
	double Y(void) { return (yp); }						// �x���W��ԋp

	void Set(double x, double y) { xp = x; yp = y; }	// ���W��(x,y)�ɐݒ�
};


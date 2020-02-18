//-----------------------------------------------------------------------//
//	���W�N���X Position ��Q�Łi�C���^�t�F�[�X���j			"position.h"    //
//-----------------------------------------------------------------------
#include	<iostream.h>

class Position {

private:
	double  xp;					// �w���W
	double  yp;					// �x���W

public:
	Position(void) { xp = 0.0; yp = 0.0; }			// �f�t�H���g�R���X�g���N�^
	Position(double x, double y = 0.0) { xp = x; yp = y; }	  // �R���X�g���N�^

	double X(void) const { return (xp); }				// �w���W��ԋp
	double Y(void) const { return (yp); }				// �x���W��ԋp

	void Set(double x, double y)  { xp = x; yp = y; }	// ���W��(x,y)�ɐݒ�
};

inline ostream& operator<<(ostream& os, const Position& pos)	// �}�����Z�q
{
	return (os << '(' << pos.X() << ", " << pos.Y() << ')');
}


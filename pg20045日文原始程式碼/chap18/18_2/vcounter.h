//-----------------------------------------------------//
//	�J�E���^�N���X�t�@�~��				"vcounter.h"   //
//-----------------------------------------------------//

#include	<limits.h>

//----- �J�E���^�N���X -----//
class VCounter {
protected:
	unsigned  cnt;						// �J�E���^�l
public:
	VCounter(void) { cnt = 0; }			// �R���X�g���N�^

	virtual void Increment(void) = 0;	// �������z�֐�
	virtual void Decrement(void) = 0;	// �������z�֐�
	unsigned Value(void) { return (cnt); }
};

//----- UINT_MAX������̃J�E���^�N���X -----//
class UnCounter  : public VCounter {
public:
	void Increment(void) { if (cnt < UINT_MAX) cnt++; }
	void Decrement(void) { if (cnt > 0) cnt--; }
	unsigned Value(void) { return (cnt); }
};

//----- ����t�J�E���^ -----//
class BnCounter : public VCounter {
private:
	unsigned  max;						// �ő�l
public:
	BnCounter(unsigned hi = UINT_MAX) { max = hi; }
	void Increment(void) { if (cnt < max) cnt++; }
	void Decrement(void) { if (cnt > 0) cnt--; }
};


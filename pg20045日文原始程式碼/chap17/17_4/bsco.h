//-------------------------------------------------------------//
//	�J�E���^�N���X								"bsco.h"  //
//-------------------------------------------------------------//

#include	<limits.h>

//===== �J�E���^�N���X =====//
class BsCounter {

protected:
	unsigned	cnt;					// �J�E���^�l

public:
	BsCounter(void) { cnt = 0; }		// �R���X�g���N�^

	virtual void Increment(void) { if (cnt < UINT_MAX) cnt++; }
	virtual void Decrement(void) { if (cnt > 0) cnt--; }
	unsigned Value(void) { return (cnt); }
};

//===== ����t���J�E���^�N���X =====//
class BndCounter : public BsCounter {

private:
	unsigned  max;

public:
	BndCounter(unsigned hi = UINT_MAX) { max = hi; cnt = 0; }
	void Increment(void) { if (cnt < max) cnt++; }
	void Decrement(void) { if (cnt > 0) cnt--; }
};


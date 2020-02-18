//----------------------------------------------------------------------------//
//  �J�E���^�N���X Counter									"counter.h"       //
//----------------------------------------------------------------------------//


#include	<limits.h>

//===== �J�E���^�N���X =====//
class Counter {

private:
	unsigned  Cnt;					// �J�E���g�l

public:
	Counter(void) { Cnt = 0; }		// �R���X�g���N�^

	void Increment(void) { if (Cnt < UINT_MAX) Cnt++; }		// �J�E���g�A�b�v
	void Decrement(void) { if (Cnt > 0) Cnt--; }			// �J�E���g�_�E��
	unsigned Value(void) { return (Cnt); }					// �J�E���g�l��ԋp
};


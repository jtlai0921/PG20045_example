//----------------------------------------------------------------------------//
//	�����J�E���g�A�b�v�N���X Bcounter						"bcounter.h"      //
//----------------------------------------------------------------------------//


#include	"counter.h"

//===== �����J�E���g�A�b�v�N���X =====//
class Bcounter : private Counter {

public:
	Bounter(void) { }					// �R���X�g���N�^

	Counter::Value;						// �֐�Value ����A�N�Z�X�錾

	void Increment(void) {				// �Q�i�߂饥��Ē�`
		if (Value() < UINT_MAX - 1) {
			Counter::Increment();
			Counter::Increment();
		}
	}
};


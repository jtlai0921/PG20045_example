//----------------------------------------------------------------------------//
//	�J�E���^�N���X Counter									"counter.h"       //
//----------------------------------------------------------------------------//


#include	<limits.h>

//===== �J�E���^�N���X =====//
class Counter {

private:
	unsigned	Cnt;								// �J�E���g�l

public:
	Counter(void) { Cnt = 0; }						// �R���X�g���N�^

	operator unsigned(void) { return (Cnt); }		// �ϊ��֐�   unsigned(op)

	int operator!(void) { return (Cnt == 0); }		// �ے艉�Z�q !op

	Counter operator++(void) {					// �O�u�C���N�������g���Z�q ++op
		if (Cnt < UINT_MAX) Cnt++;
			return (*this);
	}

	Counter operator++(int dummy) {				// ��u�C���N�������g���Z�q op++
		Counter x = *this;
		if (Cnt < UINT_MAX) Cnt++;
			return (x);
	}

	Counter operator--(void) {					// �O�u�f�N�������g���Z�q --op
		if (Cnt > 0) Cnt--;
			return (*this);
	}

	Counter operator--(int dummy) {				// ��u�f�N�������g���Z�q op--
		Counter x = *this;
		if (Cnt > 0) Cnt--;
			return (x);
	}
};


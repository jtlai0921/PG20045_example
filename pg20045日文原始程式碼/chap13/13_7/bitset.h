//----------------------------------------------------------------------------//
//	unsigned�ŏW���N���X BitSet�i�C���^�t�F�[�X���j			"bitset.h"        //
//----------------------------------------------------------------------------//


#include	<iostream.h>

//===== unsigned�ŏW���N���X BitSet =====//
class BitSet {

private:
	unsigned  vec;						// �W��

	static int	len;						// unsigned�^�̃r�b�g��
	static int	unsigned_len(void);	

	static unsigned Lshift(unsigned x, int a)		// x������a�r�b�g�V�t�g
	{												// 			�����l��ԋp
		return ((a >= len) ? 0 : (x << a));
	}

public:
	BitSet(void) { vec = 0; }				// �R���X�g���N�^

	int	 Count(void);						// �v�f����ԋp
	int	 Min(void);							// �ŏ��v�f��ԋp
	int	 Max(void);							// �ő�v�f��ԋp
	int	 Null(void);							// ��W�����H
	int	 Member(int no);						// no�͊܂܂�Ă��邩�H

	void Empty(void);						// ��W���ɂ���
	void Insert(int no);						// �v�fno��ǉ�
	void Delete(int no);						// �v�fno���폜
	void Fill(int bottom, int top);			// {bottom, �c, top}��ǉ�
	void Clear(int bottom, int top);		// {bottom, �c, top}���폜

	BitSet& operator+=(const BitSet& op1);
	BitSet& operator*=(const BitSet& op1);
	BitSet& operator-=(const BitSet& op1);

	friend BitSet operator+(const BitSet& op1, const BitSet& op2);
	friend BitSet operator*(const BitSet& op1, const BitSet& op2);
	friend BitSet operator-(const BitSet& op1, const BitSet& op2);

	friend int operator==(const BitSet& op1, const BitSet& op2);
	friend int operator!=(const BitSet& op1, const BitSet& op2);
	friend int operator<(const BitSet& op1, const BitSet& op2);
	friend int operator<=(const BitSet& op1, const BitSet& op2);
	friend int operator>(const BitSet& op1, const BitSet& op2);
	friend int operator>=(const BitSet& op1, const BitSet& op2);

	friend ostream& operator<<(ostream& os, const BitSet& op1);
};


//----------------------------------------------------------------------------//
//	�{�������N���X LongLong�i�C���^�t�F�[�X���j				"LongLong.h"      //
//----------------------------------------------------------------------------//

#include		<iostream.h>

//===== �{�������N���X =====//
class LongLong {

typedef unsigned long  WORD;

private:
	char  sign;			// ����
	WORD  hi;			// ���
	WORD  lo;			// ����

	static unsigned unsigned_long_len(void);

	LongLong&  AdjustSign(void);				// �l��0�ł���Ε�����0�Ƃ���

public:
	const static unsigned  ulong_len;			// unsigned long�^�̃r�b�g��

	static void Lshift(WORD& HI, WORD& LO, unsigned num);
	static void Rshift(WORD& HI, WORD& LO, unsigned num);
	static void Add(WORD& H1, WORD& L1, WORD H2, WORD L2);
	static void Sub(WORD& H1, WORD& L1, WORD H2, WORD L2);
	static void Mul(WORD& H1, WORD& L1, WORD H2, WORD L2);
	static void Div(WORD& H1, WORD& L1, WORD H2, WORD L2);
	static void Mod(WORD& H1, WORD& L1, WORD H2, WORD L2);
	static void Inc(WORD& HI, WORD& LO);
	static void Dec(WORD& HI, WORD& LO);

	static void And(WORD& H1, WORD& L1, WORD H2, WORD L2);
	static void Or( WORD& H1, WORD& L1, WORD H2, WORD L2);
	static void XOr(WORD& H1, WORD& L1, WORD H2, WORD L2);
	static int  Msd(WORD  HI, WORD  LO);
	static int  Cmp(WORD  H1, WORD  L1, WORD H2, WORD L2);

	LongLong(void);							// �f�t�H���g�R���X�g���N�^
	LongLong(char sign, WORD hi, WORD lo);	// �R���X�g���N�^
	LongLong(long op);				// �ϊ��R���X�g���N�^�ilong   �� LongLong�j
	LongLong(const char str[]);		// �ϊ��R���X�g���N�^�i������ �� LongLong�j

	operator long(void);						// �ϊ��֐� long(op)

	LongLong operator+(void) const;			// �P�� + ���Z�q
	LongLong operator-(void) const;			// �P�� - ���Z�q
	LongLong operator~(void) const;			// �␔���Z�q
	LongLong& operator++(void);				// �O�u�C���N�������g���Z�q
	LongLong& operator--(void);				// �O�u�f�N�������g���Z�q
	LongLong operator++(int dmy);			// ��u�C���N�������g���Z�q
	LongLong operator--(int dmy);			// ��u�f�N�������g���Z�q

	LongLong& operator+=(const LongLong& op);			// +=���Z�q
	LongLong& operator-=(const LongLong& op);			// -=���Z�q
	LongLong& operator*=(const LongLong& op);			// *=���Z�q
	LongLong& operator/=(const LongLong& op);			// /=���Z�q
	LongLong& operator%=(const LongLong& op);			// %=���Z�q
	LongLong& operator&=(const LongLong& op);			// &=���Z�q
	LongLong& operator|=(const LongLong& op);			// |=���Z�q
	LongLong& operator^=(const LongLong& op);			// ^=���Z�q
	LongLong& operator<<=(int num);						// <<=���Z�q
	LongLong& operator>>=(int num);						// >>=���Z�q

	friend LongLong operator+(const LongLong& op1, const LongLong& op2);
	friend LongLong operator-(const LongLong& op1, const LongLong& op2);
	friend LongLong operator*(const LongLong& op1, const LongLong& op2);
	friend LongLong operator/(const LongLong& op1, const LongLong& op2);
	friend LongLong operator%(const LongLong& op1, const LongLong& op2);
	friend LongLong operator&(const LongLong& op1, const LongLong& op2);
	friend LongLong operator|(const LongLong& op1, const LongLong& op2);
	friend LongLong operator^(const LongLong& op1, const LongLong& op2);
	friend LongLong operator<<(const LongLong& op, int num);
	friend LongLong operator>>(const LongLong& op, int num);

	friend int operator<( const LongLong& op1, const LongLong& op2);
	friend int operator>( const LongLong& op1, const LongLong& op2);
	friend int operator<=(const LongLong& op1, const LongLong& op2);
	friend int operator>=(const LongLong& op1, const LongLong& op2);
	friend int operator==(const LongLong& op1, const LongLong& op2);
	friend int operator!=(const LongLong& op1, const LongLong& op2);

	friend ostream& operator<<(ostream& os, const LongLong& op);   // �}�����Z�q
};


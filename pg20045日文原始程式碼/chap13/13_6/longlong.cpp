//-----------------------------------------------------------//
//	�{�������N���X LongLong�i�������j		"LongLong.c"     //
//-----------------------------------------------------------//

#include		<iostream.h>
#include		<limits.h>

#include		"LongLong.h"

const unsigned LongLong::ulong_len =
								 LongLong::unsigned_long_len();

//--- WORD�^�̃r�b�g����ԋp ---//
unsigned LongLong::unsigned_long_len(void)
{
	int   count = 0;
	WORD  x = ~0UL;

	while (x) {
		if (x & 1UL) count++;
		x >>= 1;
	}
	return (count);
}

//--- <HI�LO>��num�r�b�g���V�t�g ---//
void LongLong::Lshift(WORD& HI, WORD& LO, unsigned num)
{
	if (num >= ulong_len * 2)
		HI = LO = 0UL;
	else if (num >= ulong_len) {
		HI = LO << (num - ulong_len);
		LO = 0UL;
	} else {
		WORD  tmp = LO;
		HI <<= num;
		LO <<= num;
		if (num)
			HI |= (tmp >> (ulong_len - num));
	}
}

//--- <HI�LO>��num�r�b�g�E�V�t�g ---//
void LongLong::Rshift(WORD& HI, WORD& LO, unsigned num)
{
	if (num >= ulong_len * 2)
		HI = LO = 0UL;
	else if (num >= ulong_len){
		HI = 0UL;
		LO = HI >> (num - ulong_len);
	} else {
		WORD  tmp = HI;
		HI >>= num;
		LO >>= num;
		if (num)
			LO |= (tmp << (ulong_len - num));
	}
}

//--- <H1, L1>��<H2, L2>�������� ---//
void LongLong::Add(WORD& H1, WORD& L1, WORD H2, WORD L2)
{
	WORD  diff = ULONG_MAX - L2;

	if (diff > L1) {
		L1 += L2;
		H1 += H2;
	} else {								// �J��オ��
		L1 -= diff + 1;
		H1 += H2 + 1;
	}
}

//--- <H1�L1>����<H2�L2>������ ---//
void LongLong::Sub(WORD& H1, WORD& L1, WORD H2, WORD L2)
{
	if (!H1 && !H2)
		L1 -= L2;
	else {
		if (L1 >= L2) {
			L1 -= L2;
			H1 -= H2;
		} else {							// �J�艺����
			L1 += ULONG_MAX - L2 + 1;
			H1 -= H2 + 1;
		}
	}
}

//--- <H1�L1>��<H2�L2>���|���� ---//
void LongLong::Mul(WORD& H1, WORD& L1, WORD H2, WORD L2)
{
	WORD  TH = H1;
	WORD  TL = L1;

	H1 = L1 = 0UL;
	while ((TH || TL) && (H2 || L2)) {
		if (L2 & 1UL)
			Add(H1, L1, TH, TL);
		Lshift(TH, TL, 1);
		Rshift(H2, L2, 1);
	}
}

//--- <H1�L1>��<H2�L2>�Ŋ���i���j ---//
void LongLong::Div(WORD& H1, WORD& L1, WORD H2, WORD L2)
{
	if (!H1 && !H2)
		L1 /= L2;
	else {
		WORD  TH = H1;
		WORD  TL = L1;

		H1 = L1 = 0UL;
		if (H2 || L2) {
			int  sub = Msd(TH, TL) - Msd(H2, L2);
			Lshift(H2, L2, sub);
			while (sub >= 0) {
				Lshift(H1, L1, 1);
				if (Cmp(TH, TL, H2, L2) >= 0) {
					Sub(TH, TL, H2, L2);
					L1++;
				}
				Rshift(H2, L2, 1);
				sub--;
			}
		}
	}
}

//--- <H1�L1>��<H2�L2>�Ŋ������]��i��]�j ---//
void LongLong::Mod(WORD& H1, WORD& L1, WORD H2, WORD L2)
{
	if (Cmp(H2, L2, 0UL, 0UL)) {
		int  sub = Msd(H1, L1) - Msd(H2, L2);
		Lshift(H2, L2, sub);
		while (sub >= 0) {
			if (Cmp(H1, L1, H2, L2) >= 0)
				Sub(H1, L1, H2, L2);
			Rshift(H2, L2, 1);
			sub--;
		}
	}
}

//--- <HI�LO>���C���N�������g ---//
void LongLong::Inc(WORD& HI, WORD& LO)
{
	if (ULONG_MAX != LO)
		LO++;
	else {							// �J��オ��
		LO = 0UL;
		HI++;
	}
}

//--- <HI�LO>���f�N�������g ---//
void LongLong::Dec(WORD& HI, WORD& LO)
{
	if (LO)
		LO--;
	else {							// �J�艺����
		LO = ULONG_MAX;
		HI--;
	}
}

//--- <H1�L1>��<H2�L2>�̘_���ς����߂� ---//
void LongLong::And(WORD& H1, WORD& L1, WORD H2, WORD L2)
{
	H1 &= H2;
	L1 &= L2;
}

//--- <H1�L1>��<H2�L2>�̘_���a�����߂� ---//
void LongLong::Or(WORD& H1, WORD& L1, WORD H2, WORD L2)
{
	H1 |= H2;
	L1 |= L2;
}

//--- <H1�L1>��<H2�L2>�̔r���I�_���a�����߂� ---//
void LongLong::XOr(WORD& H1, WORD& L1, WORD H2, WORD L2)
{
	H1 ^= H2;
	L1 ^= L2;
}

//--- <HI�LO>��1�̃r�b�g�ōł���ʂ̃r�b�g�̈ʒu�����߂� ---//
int LongLong::Msd(WORD HI, WORD LO)
{
	int  i;

	if (HI)
		for (i = ulong_len - 1; i >= 0; i--)
			if ((HI >> i) & 1UL)
				return (ulong_len + i);

	for (i = ulong_len - 1; i >= 0; i--)
		if ((LO >> i) & 1UL)
			return (i);

	return (-1);
}

//--- <H1�L1>��<H2�L2>���r�i��F1, �������F0, ���F -1�j ---//
int LongLong::Cmp(WORD H1, WORD L1, WORD H2, WORD L2)
{
	if (H1 != H2)
		return ((H1 > H2) ? 1 : -1);
	else if (L1 != L2)
		return ((L1 > L2) ? 1 : -1);
	return (0);
}

//--- �f�t�H���g�R���X�g���N�^ ---//
LongLong::LongLong(void)
{
	sign = 0;	hi = lo = 0;
}

//--- �R���X�g���N�^ ---//
LongLong::LongLong(char s, WORD h, WORD l)
{
	hi = h;
	lo = l;
	sign = (s != 0);
	AdjustSign();
}

//--- �ϊ��R���X�g���N�^�ilong   �� LongLong�j ---//
LongLong::LongLong(long op)
{
	sign  = (op < 0);
	hi = 0;
	if (op < 0) {
		op ^= ~0UL;
		op++;
	}
	lo = op;
}

//--- �ϊ��R���X�g���N�^�i������ �� LongLong�j ---//
LongLong::LongLong(const char str[])
{
	sign = 0;
	hi = lo = 0UL;

	int  i = 0;
	if (str[i] == '+' || str[i] == '-')
		sign = (str[i++] == '-');
	while (str[i] >= '0' && str[i] <= '9') {
		LongLong::Mul(hi, lo, 0UL, 10UL);
		LongLong::Add(hi, lo, 0UL, str[i++] - '0');	
	}
	AdjustSign();
}

//--- �ϊ��֐� long(op) ---//
LongLong::operator long(void)
{
	long  tmp = (long)lo;
	if (sign)
		tmp *= -1;
	return (tmp);
}

//--- �l��0�ł���Ε�����0�Ƃ��� ---//
LongLong& LongLong::AdjustSign(void)
{
	if (hi == 0UL && lo == 0UL)
		sign = 0;
	return (*this);
}

//--- �P�� + ���Z�q ---//
LongLong LongLong::operator+(void) const
{
	return (*this);
}

//--- �P�� - ���Z�q ---//
LongLong LongLong::operator-(void) const
{
	return (LongLong(!sign , hi, lo));
}

//--- �␔���Z�q ---//
LongLong LongLong::operator~(void) const
{
	return (LongLong(sign , ~hi, ~lo));
}

//--- �O�u�C���N�������g���Z�q (++LongLong) ---//
LongLong& LongLong::operator++(void)
{
	if (!sign)					// ���̏ꍇ
		Inc(hi, lo);
	else						// ���̏ꍇ
		Dec(hi, lo);
	return (AdjustSign());
}

//--- ��u�C���N�������g���Z�q (LongLong++) ---//
LongLong LongLong::operator++(int dmy)
{
	LongLong  tmp = *this;
	++*this;
	return (tmp);
}

//--- �O�u�f�N�������g���Z�q (--LongLong) ---//
LongLong& LongLong::operator--(void)
{
	if (sign)					// ���̏ꍇ
		Inc(hi, lo);
	else						// ���̏ꍇ
		Dec(hi, lo);
	return (AdjustSign());
}

//--- ��u�f�N�������g���Z�q (LongLong--) ---//
LongLong LongLong::operator--(int dmy)
{
	LongLong  tmp = *this;
	--*this;
	return (tmp);
}

//--- +=���Z�q (LongLong += LongLong) ---//
LongLong& LongLong::operator+=(const LongLong& op)
{
	if (sign == op.sign)
		Add(hi, lo, op.hi, op.lo);
	else
		*this -= -op;
	return (AdjustSign());
}

//--- -=���Z�q (LongLong -= LongLong) ---//
LongLong& LongLong::operator-=(const LongLong& op)
{
	if (sign != op.sign)
		*this +=  -op;
	else {
		if (Cmp(hi, lo, op.hi, op.lo) >= 0)
			Sub(hi, lo, op.hi, op.lo);
		else {
			WORD  tmpH = op.hi;
			WORD  tmpL = op.lo;
			Sub(tmpH, tmpL, hi, lo);
			hi = tmpH;	lo = tmpL;
			sign = !sign;
		}
	}
	return (AdjustSign());
}

//--- *=���Z�q (LongLong *= LongLong) ---//
LongLong& LongLong::operator*=(const LongLong& op)
{
	Mul(hi, lo, op.hi, op.lo);
	sign = (sign != op.sign);
	return (AdjustSign());
}

//--- /=���Z�q (LongLong /= LongLong) ---//
LongLong& LongLong::operator/=(const LongLong& op)
{
	Div(hi, lo, op.hi, op.lo);
	sign = (sign != op.sign);
	return (AdjustSign());
}
	
//--- %=���Z�q (LongLong %= LongLong) ---//
LongLong& LongLong::operator%=(const LongLong& op)
{
	Mod(hi, lo, op.hi, op.lo);
	return (AdjustSign());
}

//--- <<=���Z�q (LongLong <<= int) ---//
LongLong& LongLong::operator<<=(int num)
{
	Lshift(hi, lo, num);
	return (AdjustSign());
}

//--- >>=���Z�q (LongLong >>= int) ---//
LongLong& LongLong::operator>>=(int num)
{
	Rshift(hi, lo, num);
	return (AdjustSign());
}

//--- &=���Z�q (LongLong &= LongLong) ---//
LongLong& LongLong::operator&=(const LongLong& op)
{
	And(hi, lo, op.hi, op.lo);
	return (AdjustSign());
}

//--- |=���Z�q (LongLong |= LongLong) ---//
LongLong& LongLong::operator|=(const LongLong& op)
{
	Or(hi, lo, op.hi, op.lo);
	return (AdjustSign());
}

//--- ^=���Z�q (LongLong ^= LongLong) ---//
LongLong& LongLong::operator^=(const LongLong& op)
{
	XOr(hi, lo, op.hi, op.lo);
	return (AdjustSign());
}

//--- �Q�� + ���Z�q (LongLong + LongLong) ---//
LongLong operator+(const LongLong& op1, const LongLong& op2)
{
	LongLong  tmp = op1;
	tmp += op2;
	return (tmp);
}

//--- �Q�� - ���Z�q (LongLong - LongLong) ---//
LongLong operator-(const LongLong& op1, const LongLong& op2)
{
	LongLong  tmp = op1;
	tmp -= op2;
	return (tmp);
}

//--- �Q�� * ���Z�q (LongLong * LongLong) ---//
LongLong operator*(const LongLong& op1, const LongLong& op2)
{
	LongLong  tmp = op1;
	tmp *= op2;

	return (tmp);
}

//--- �Q�� / ���Z�q (LongLong / LongLong) ---//
LongLong operator/(const LongLong& op1, const LongLong& op2)
{
	LongLong  tmp = op1;
	tmp /= op2;

	return (tmp);
}

//--- �Q�� % ���Z�q (LongLong % LongLong) ---//
LongLong operator%(const LongLong& op1, const LongLong& op2)
{
	LongLong  tmp = op1;
	tmp %= op2;

	return (tmp);
}

//--- ���V�t�g���Z�q (LongLong << int) ---//
LongLong operator<<(const LongLong& op, int num)
{
	LongLong  ret = op;
	ret <<= num;

	return (ret);
}

//--- �E�V�t�g���Z�q (LongLong >> int) ---//
LongLong operator>>(const LongLong& op, int num)
{
	LongLong  ret = op;
	ret >>= num;

	return (ret);
}

//--- �Q�� & ���Z�q (LongLong & LongLong) ---//
LongLong operator&(const LongLong& op1, const LongLong& op2)
{
	LongLong  tmp = op1;
	tmp &= op2;

	return (tmp);
}

//--- �Q�� | ���Z�q (LongLong | LongLong) ---//
LongLong operator|(const LongLong& op1, const LongLong& op2)
{
	LongLong  tmp = op1;
	tmp |= op2;

	return (tmp);
}

//--- �Q�� ^ ���Z�q (LongLong ^ LongLong) ---//
LongLong operator^(const LongLong& op1, const LongLong& op2)
{
	LongLong  tmp = op1;
	tmp ^= op2;

	return (tmp);
}

//--- LongLong��r�F op1 �� op2 ��? (op1 < op2) ---//
int operator<(const LongLong& op1, const LongLong& op2)
{
	return ((op1.sign != op2.sign) ? op1.sign : LongLong::Cmp(op1.hi, op1.lo, op2.hi, op2.lo)== (op1.sign * 2 - 1));
}

//--- LongLong��r�F op1 �� op2 ��? (op1 > op2) ---//
int operator>(const LongLong& op1, const LongLong& op2)
{
	return ((op1.sign != op2.sign) ? op2.sign :
				LongLong::Cmp(op1.hi, op1.lo, op2.hi, op2.lo)
                                          == - (op1.sign * 2 - 1));
}

//--- LongLong��r�F op1 �� op2 ��? (op1 <= op2) ---//
int operator<=(const LongLong& op1, const LongLong& op2)
{
	return (op1 < op2 || op1 == op2);
}

//--- LongLong��r�F op1 �� op2 ��? (op1 >= op2) ---//
int operator>=(const LongLong& op1, const LongLong& op2)
{
	return (op1 > op2 || op1 == op2);
}

//--- op1��op2�͓��������H (op1 == op2) ---//
int operator==(const LongLong& op1, const LongLong& op2)
{
	return (op1.sign == op2.sign && op1.hi == op2.hi &&
			op1.lo   == op2.lo);
}

//--- op1��op2�͓������Ȃ����H (op1 != op2) ---//
int operator!=(const LongLong& op1, const LongLong& op2)
{
	return (!(op1 == op2));
}

//--- �}�����Z�q ---//
ostream& operator<<(ostream& os, const LongLong& op)
{
	if (op.sign) os << '-';				// ����������o��

	if (!op.hi) 
		os << op.lo;
	else{
		LongLong::WORD  TH = op.hi;
		LongLong::WORD  TL = op.lo;
		LongLong::WORD  KH = 0UL;
		LongLong::WORD  KL = 1UL;

		while (LongLong::Cmp(TH, TL, 0UL, 10UL) >= 0) {
			LongLong::Div(TH, TL, 0UL, 10UL);
			LongLong::Mul(KH, KL, 0UL, 10UL);
		}
		TH = op.hi;
		TL = op.lo;
		while (LongLong::Cmp(KH, KL, 0UL, 0UL)) {
			LongLong::WORD  PH = TH;
			LongLong::WORD  PL = TL;
			LongLong::Div(PH, PL, KH, KL);
			os << char(PL + '0');
			LongLong::Mod(TH, TL, KH, KL);
			LongLong::Div(KH, KL, 0UL, 10UL);
		}
	}
	return (os);
}

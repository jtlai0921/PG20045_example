//-----------------------------------------------------------//
//	倍長整数クラス LongLong（実現部）		"LongLong.c"     //
//-----------------------------------------------------------//

#include		<iostream.h>
#include		<limits.h>

#include		"LongLong.h"

const unsigned LongLong::ulong_len =
								 LongLong::unsigned_long_len();

//--- WORD型のビット数を返却 ---//
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

//--- <HI･LO>をnumビット左シフト ---//
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

//--- <HI･LO>をnumビット右シフト ---//
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

//--- <H1, L1>に<H2, L2>を加える ---//
void LongLong::Add(WORD& H1, WORD& L1, WORD H2, WORD L2)
{
	WORD  diff = ULONG_MAX - L2;

	if (diff > L1) {
		L1 += L2;
		H1 += H2;
	} else {								// 繰り上がり
		L1 -= diff + 1;
		H1 += H2 + 1;
	}
}

//--- <H1･L1>から<H2･L2>を引く ---//
void LongLong::Sub(WORD& H1, WORD& L1, WORD H2, WORD L2)
{
	if (!H1 && !H2)
		L1 -= L2;
	else {
		if (L1 >= L2) {
			L1 -= L2;
			H1 -= H2;
		} else {							// 繰り下がり
			L1 += ULONG_MAX - L2 + 1;
			H1 -= H2 + 1;
		}
	}
}

//--- <H1･L1>に<H2･L2>を掛ける ---//
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

//--- <H1･L1>を<H2･L2>で割る（商） ---//
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

//--- <H1･L1>を<H2･L2>で割った余り（剰余） ---//
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

//--- <HI･LO>をインクリメント ---//
void LongLong::Inc(WORD& HI, WORD& LO)
{
	if (ULONG_MAX != LO)
		LO++;
	else {							// 繰り上がり
		LO = 0UL;
		HI++;
	}
}

//--- <HI･LO>をデクリメント ---//
void LongLong::Dec(WORD& HI, WORD& LO)
{
	if (LO)
		LO--;
	else {							// 繰り下がり
		LO = ULONG_MAX;
		HI--;
	}
}

//--- <H1･L1>と<H2･L2>の論理積を求める ---//
void LongLong::And(WORD& H1, WORD& L1, WORD H2, WORD L2)
{
	H1 &= H2;
	L1 &= L2;
}

//--- <H1･L1>と<H2･L2>の論理和を求める ---//
void LongLong::Or(WORD& H1, WORD& L1, WORD H2, WORD L2)
{
	H1 |= H2;
	L1 |= L2;
}

//--- <H1･L1>と<H2･L2>の排他的論理和を求める ---//
void LongLong::XOr(WORD& H1, WORD& L1, WORD H2, WORD L2)
{
	H1 ^= H2;
	L1 ^= L2;
}

//--- <HI･LO>の1のビットで最も上位のビットの位置を求める ---//
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

//--- <H1･L1>と<H2･L2>を比較（大：1, 等しい：0, 小： -1） ---//
int LongLong::Cmp(WORD H1, WORD L1, WORD H2, WORD L2)
{
	if (H1 != H2)
		return ((H1 > H2) ? 1 : -1);
	else if (L1 != L2)
		return ((L1 > L2) ? 1 : -1);
	return (0);
}

//--- デフォルトコンストラクタ ---//
LongLong::LongLong(void)
{
	sign = 0;	hi = lo = 0;
}

//--- コンストラクタ ---//
LongLong::LongLong(char s, WORD h, WORD l)
{
	hi = h;
	lo = l;
	sign = (s != 0);
	AdjustSign();
}

//--- 変換コンストラクタ（long   → LongLong） ---//
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

//--- 変換コンストラクタ（文字列 → LongLong） ---//
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

//--- 変換関数 long(op) ---//
LongLong::operator long(void)
{
	long  tmp = (long)lo;
	if (sign)
		tmp *= -1;
	return (tmp);
}

//--- 値が0であれば符号を0とする ---//
LongLong& LongLong::AdjustSign(void)
{
	if (hi == 0UL && lo == 0UL)
		sign = 0;
	return (*this);
}

//--- 単項 + 演算子 ---//
LongLong LongLong::operator+(void) const
{
	return (*this);
}

//--- 単項 - 演算子 ---//
LongLong LongLong::operator-(void) const
{
	return (LongLong(!sign , hi, lo));
}

//--- 補数演算子 ---//
LongLong LongLong::operator~(void) const
{
	return (LongLong(sign , ~hi, ~lo));
}

//--- 前置インクリメント演算子 (++LongLong) ---//
LongLong& LongLong::operator++(void)
{
	if (!sign)					// 正の場合
		Inc(hi, lo);
	else						// 負の場合
		Dec(hi, lo);
	return (AdjustSign());
}

//--- 後置インクリメント演算子 (LongLong++) ---//
LongLong LongLong::operator++(int dmy)
{
	LongLong  tmp = *this;
	++*this;
	return (tmp);
}

//--- 前置デクリメント演算子 (--LongLong) ---//
LongLong& LongLong::operator--(void)
{
	if (sign)					// 負の場合
		Inc(hi, lo);
	else						// 正の場合
		Dec(hi, lo);
	return (AdjustSign());
}

//--- 後置デクリメント演算子 (LongLong--) ---//
LongLong LongLong::operator--(int dmy)
{
	LongLong  tmp = *this;
	--*this;
	return (tmp);
}

//--- +=演算子 (LongLong += LongLong) ---//
LongLong& LongLong::operator+=(const LongLong& op)
{
	if (sign == op.sign)
		Add(hi, lo, op.hi, op.lo);
	else
		*this -= -op;
	return (AdjustSign());
}

//--- -=演算子 (LongLong -= LongLong) ---//
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

//--- *=演算子 (LongLong *= LongLong) ---//
LongLong& LongLong::operator*=(const LongLong& op)
{
	Mul(hi, lo, op.hi, op.lo);
	sign = (sign != op.sign);
	return (AdjustSign());
}

//--- /=演算子 (LongLong /= LongLong) ---//
LongLong& LongLong::operator/=(const LongLong& op)
{
	Div(hi, lo, op.hi, op.lo);
	sign = (sign != op.sign);
	return (AdjustSign());
}
	
//--- %=演算子 (LongLong %= LongLong) ---//
LongLong& LongLong::operator%=(const LongLong& op)
{
	Mod(hi, lo, op.hi, op.lo);
	return (AdjustSign());
}

//--- <<=演算子 (LongLong <<= int) ---//
LongLong& LongLong::operator<<=(int num)
{
	Lshift(hi, lo, num);
	return (AdjustSign());
}

//--- >>=演算子 (LongLong >>= int) ---//
LongLong& LongLong::operator>>=(int num)
{
	Rshift(hi, lo, num);
	return (AdjustSign());
}

//--- &=演算子 (LongLong &= LongLong) ---//
LongLong& LongLong::operator&=(const LongLong& op)
{
	And(hi, lo, op.hi, op.lo);
	return (AdjustSign());
}

//--- |=演算子 (LongLong |= LongLong) ---//
LongLong& LongLong::operator|=(const LongLong& op)
{
	Or(hi, lo, op.hi, op.lo);
	return (AdjustSign());
}

//--- ^=演算子 (LongLong ^= LongLong) ---//
LongLong& LongLong::operator^=(const LongLong& op)
{
	XOr(hi, lo, op.hi, op.lo);
	return (AdjustSign());
}

//--- ２項 + 演算子 (LongLong + LongLong) ---//
LongLong operator+(const LongLong& op1, const LongLong& op2)
{
	LongLong  tmp = op1;
	tmp += op2;
	return (tmp);
}

//--- ２項 - 演算子 (LongLong - LongLong) ---//
LongLong operator-(const LongLong& op1, const LongLong& op2)
{
	LongLong  tmp = op1;
	tmp -= op2;
	return (tmp);
}

//--- ２項 * 演算子 (LongLong * LongLong) ---//
LongLong operator*(const LongLong& op1, const LongLong& op2)
{
	LongLong  tmp = op1;
	tmp *= op2;

	return (tmp);
}

//--- ２項 / 演算子 (LongLong / LongLong) ---//
LongLong operator/(const LongLong& op1, const LongLong& op2)
{
	LongLong  tmp = op1;
	tmp /= op2;

	return (tmp);
}

//--- ２項 % 演算子 (LongLong % LongLong) ---//
LongLong operator%(const LongLong& op1, const LongLong& op2)
{
	LongLong  tmp = op1;
	tmp %= op2;

	return (tmp);
}

//--- 左シフト演算子 (LongLong << int) ---//
LongLong operator<<(const LongLong& op, int num)
{
	LongLong  ret = op;
	ret <<= num;

	return (ret);
}

//--- 右シフト演算子 (LongLong >> int) ---//
LongLong operator>>(const LongLong& op, int num)
{
	LongLong  ret = op;
	ret >>= num;

	return (ret);
}

//--- ２項 & 演算子 (LongLong & LongLong) ---//
LongLong operator&(const LongLong& op1, const LongLong& op2)
{
	LongLong  tmp = op1;
	tmp &= op2;

	return (tmp);
}

//--- ２項 | 演算子 (LongLong | LongLong) ---//
LongLong operator|(const LongLong& op1, const LongLong& op2)
{
	LongLong  tmp = op1;
	tmp |= op2;

	return (tmp);
}

//--- ２項 ^ 演算子 (LongLong ^ LongLong) ---//
LongLong operator^(const LongLong& op1, const LongLong& op2)
{
	LongLong  tmp = op1;
	tmp ^= op2;

	return (tmp);
}

//--- LongLong比較： op1 ＜ op2 か? (op1 < op2) ---//
int operator<(const LongLong& op1, const LongLong& op2)
{
	return ((op1.sign != op2.sign) ? op1.sign : LongLong::Cmp(op1.hi, op1.lo, op2.hi, op2.lo)== (op1.sign * 2 - 1));
}

//--- LongLong比較： op1 ＞ op2 か? (op1 > op2) ---//
int operator>(const LongLong& op1, const LongLong& op2)
{
	return ((op1.sign != op2.sign) ? op2.sign :
				LongLong::Cmp(op1.hi, op1.lo, op2.hi, op2.lo)
                                          == - (op1.sign * 2 - 1));
}

//--- LongLong比較： op1 ≦ op2 か? (op1 <= op2) ---//
int operator<=(const LongLong& op1, const LongLong& op2)
{
	return (op1 < op2 || op1 == op2);
}

//--- LongLong比較： op1 ≧ op2 か? (op1 >= op2) ---//
int operator>=(const LongLong& op1, const LongLong& op2)
{
	return (op1 > op2 || op1 == op2);
}

//--- op1とop2は等しいか？ (op1 == op2) ---//
int operator==(const LongLong& op1, const LongLong& op2)
{
	return (op1.sign == op2.sign && op1.hi == op2.hi &&
			op1.lo   == op2.lo);
}

//--- op1とop2は等しくないか？ (op1 != op2) ---//
int operator!=(const LongLong& op1, const LongLong& op2)
{
	return (!(op1 == op2));
}

//--- 挿入演算子 ---//
ostream& operator<<(ostream& os, const LongLong& op)
{
	if (op.sign) os << '-';				// 負符号上を出力

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

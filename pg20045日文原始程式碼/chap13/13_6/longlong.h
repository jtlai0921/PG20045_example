//----------------------------------------------------------------------------//
//	倍長整数クラス LongLong（インタフェース部）				"LongLong.h"      //
//----------------------------------------------------------------------------//

#include		<iostream.h>

//===== 倍長整数クラス =====//
class LongLong {

typedef unsigned long  WORD;

private:
	char  sign;			// 符号
	WORD  hi;			// 上位
	WORD  lo;			// 下位

	static unsigned unsigned_long_len(void);

	LongLong&  AdjustSign(void);				// 値が0であれば符号を0とする

public:
	const static unsigned  ulong_len;			// unsigned long型のビット数

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

	LongLong(void);							// デフォルトコンストラクタ
	LongLong(char sign, WORD hi, WORD lo);	// コンストラクタ
	LongLong(long op);				// 変換コンストラクタ（long   → LongLong）
	LongLong(const char str[]);		// 変換コンストラクタ（文字列 → LongLong）

	operator long(void);						// 変換関数 long(op)

	LongLong operator+(void) const;			// 単項 + 演算子
	LongLong operator-(void) const;			// 単項 - 演算子
	LongLong operator~(void) const;			// 補数演算子
	LongLong& operator++(void);				// 前置インクリメント演算子
	LongLong& operator--(void);				// 前置デクリメント演算子
	LongLong operator++(int dmy);			// 後置インクリメント演算子
	LongLong operator--(int dmy);			// 後置デクリメント演算子

	LongLong& operator+=(const LongLong& op);			// +=演算子
	LongLong& operator-=(const LongLong& op);			// -=演算子
	LongLong& operator*=(const LongLong& op);			// *=演算子
	LongLong& operator/=(const LongLong& op);			// /=演算子
	LongLong& operator%=(const LongLong& op);			// %=演算子
	LongLong& operator&=(const LongLong& op);			// &=演算子
	LongLong& operator|=(const LongLong& op);			// |=演算子
	LongLong& operator^=(const LongLong& op);			// ^=演算子
	LongLong& operator<<=(int num);						// <<=演算子
	LongLong& operator>>=(int num);						// >>=演算子

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

	friend ostream& operator<<(ostream& os, const LongLong& op);   // 挿入演算子
};


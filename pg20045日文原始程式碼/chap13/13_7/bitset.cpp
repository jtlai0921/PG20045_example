//-------------------------------------------------------------//
//	unsigned版集合クラス BitSet（実現）			"bitset.c"     //
//-------------------------------------------------------------//

#include	<iostream.h>

#include	"bitset.h"

//  unsigned型のビット数
int BitSet::len = BitSet::unsigned_len();

//--- unsigned型のビット数を返却 ---//
int BitSet::unsigned_len(void)
{
	int	 count = 0;
	unsigned  x = ~0U;			// xの全ビットは1

	while (x) {
		if (x & 1) count++;
		x >>= 1;
	}
	return (count);
}

//--- 要素数を返却 ---//
int BitSet::Count(void)
{
	int  count = 0;
	unsigned  x = vec;

	while (x) {
		if (x & 1) count++;
		x >>= 1;
	}
	return (count);
}

//--- 最小要素を返却 ---//
int BitSet::Min(void)
{
	if (vec == 0)
		return (-1);					// 空集合
	else {
		int	 min = 0;
		int	 x = vec;

		while (1) {
			if (x & 1) break;
			x >>= 1;
			min++;
		}
		return (min);
	}
}

//--- 最大要素を返却 ---//
int	BitSet::Max(void)
{
	if (vec == 0)
		return (-1);					// 空集合
	else {
		int	 max = len - 1;
		int	 msb = 1 << (len - 1);
		int	 x = vec;

		while (1) {
			if (x & msb) break;
			x <<= 1;
			max--;
		}
		return (max);
	}
}

//--- 空集合か？ ---//
int BitSet::Null(void)
{
	return (vec == 0);
}

//--- noは含まれているか？ ---//
int BitSet::Member(int no)
{
	return ((vec & (1 << no)) != 0);
}

//--- 空集合にする ---//
void BitSet::Empty(void)
{
	vec = 0;
}

//--- noを追加 ---//
void BitSet::Insert(int no)
{
	vec |= 1 << no;
}

//--- noを削除 ---//
void BitSet::Delete(int no)
{
	vec &= ~(1 << no);
}

//--- {bottom, …, top}を追加 ---//
void BitSet::Fill(int bottom, int top)
{
	vec |= Lshift(~Lshift(~0U, top - bottom + 1), bottom);
}

//--- {bottom, …, top}を削除 ---//
void BitSet::Clear(int bottom, int top)
{
	vec &= ~Lshift(~Lshift(~0U, top - bottom + 1), bottom);
}

//--- 集合を加える （BitSet += BitSet） ---//
BitSet& BitSet::operator+=(const BitSet& set)
{
	vec |= set.vec;
	return (*this);
}

//--- 集合を掛ける （BitSet *= BitSet） ---//
BitSet& BitSet::operator*=(const BitSet& set)
{
	vec &= set.vec;
	return (*this);
}

//--- 集合を引く （BitSet -= BitSet） ---//
BitSet& BitSet::operator-=(const BitSet& set)
{
	vec &= ~(vec & set.vec);
	return (*this);
}

//--- 和集合を求める （BitSet + BitSet） ---//
BitSet operator+(const BitSet& st1, const BitSet& st2)
{
	BitSet temp;
	temp.vec = st1.vec | st2.vec;
	return (temp);
}

//--- 積集合を求める （BitSet * BitSet） ---//
BitSet operator*(const BitSet& st1, const BitSet& st2)
{
	BitSet temp;
	temp.vec = st1.vec & st2.vec;
	return (temp);
}

//--- 差集合を求める （BitSet - BitSet） ---//
BitSet operator-(const BitSet& st1, const BitSet& st2)
{
	BitSet temp;
	temp.vec = (st1.vec | st2.vec) & ~(st1.vec & st2.vec);
	return (temp);
}

//--- 等値演算子 （BitSet == BitSet） ---//
int operator==(const BitSet& st1, const BitSet& st2)
{
	return (st1.vec == st2.vec);
}

//--- 等値演算子 （BitSet != BitSet） ---//
int operator!=(const BitSet& st1, const BitSet& st2)
{
	return (st1.vec != st2.vec);
}

//--- 真部分集合か？ （BitSet < BitSet） ---//
int operator<(const BitSet& st1, const BitSet& st2)
{
	return ((st1.vec & ~(st1.vec & st2.vec)) == 0 &&
			 st1.vec != st2.vec);
}

//--- 部分集合か？ （BitSet <= BitSet） ---//
int operator<=(const BitSet& st1, const BitSet& st2)
{
	return ((st1.vec & ~(st1.vec & st2.vec)) == 0);
}

//--- 真部分集合か？ （BitSet > BitSet） ---//
int operator>(const BitSet& st1, const BitSet& st2)
{
	return ((st2.vec & ~(st2.vec & st1.vec)) == 0 &&
			 st1.vec != st2.vec);
}

//--- 部分集合か？ （BitSet >= BitSet） ---//
int operator>=(const BitSet& st1, const BitSet& st2)
{
	return ((st2.vec & ~(st2.vec & st1.vec)) == 0);
}

//--- 挿入演算子 ---//
ostream& operator<<(ostream& os, const BitSet& set)
{
	unsigned  x = set.vec;

	os << "{ ";
	for (int i = 0; x ; i++) {	
		if (x & 1)
			cout << i << ' ';
		x >>= 1; 
	}

	return (os << "}");
}


//----------------------------------------------------------------------------//
//	unsigned版集合クラス BitSet（インタフェース部）			"bitset.h"        //
//----------------------------------------------------------------------------//


#include	<iostream.h>

//===== unsigned版集合クラス BitSet =====//
class BitSet {

private:
	unsigned  vec;						// 集合

	static int	len;						// unsigned型のビット数
	static int	unsigned_len(void);	

	static unsigned Lshift(unsigned x, int a)		// xを左にaビットシフト
	{												// 			した値を返却
		return ((a >= len) ? 0 : (x << a));
	}

public:
	BitSet(void) { vec = 0; }				// コンストラクタ

	int	 Count(void);						// 要素数を返却
	int	 Min(void);							// 最小要素を返却
	int	 Max(void);							// 最大要素を返却
	int	 Null(void);							// 空集合か？
	int	 Member(int no);						// noは含まれているか？

	void Empty(void);						// 空集合にする
	void Insert(int no);						// 要素noを追加
	void Delete(int no);						// 要素noを削除
	void Fill(int bottom, int top);			// {bottom, …, top}を追加
	void Clear(int bottom, int top);		// {bottom, …, top}を削除

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


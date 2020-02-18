//-------------------------------------------------------------//
//	unsigned�ŏW���N���X BitSet�i�����j			"bitset.c"     //
//-------------------------------------------------------------//

#include	<iostream.h>

#include	"bitset.h"

//  unsigned�^�̃r�b�g��
int BitSet::len = BitSet::unsigned_len();

//--- unsigned�^�̃r�b�g����ԋp ---//
int BitSet::unsigned_len(void)
{
	int	 count = 0;
	unsigned  x = ~0U;			// x�̑S�r�b�g��1

	while (x) {
		if (x & 1) count++;
		x >>= 1;
	}
	return (count);
}

//--- �v�f����ԋp ---//
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

//--- �ŏ��v�f��ԋp ---//
int BitSet::Min(void)
{
	if (vec == 0)
		return (-1);					// ��W��
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

//--- �ő�v�f��ԋp ---//
int	BitSet::Max(void)
{
	if (vec == 0)
		return (-1);					// ��W��
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

//--- ��W�����H ---//
int BitSet::Null(void)
{
	return (vec == 0);
}

//--- no�͊܂܂�Ă��邩�H ---//
int BitSet::Member(int no)
{
	return ((vec & (1 << no)) != 0);
}

//--- ��W���ɂ��� ---//
void BitSet::Empty(void)
{
	vec = 0;
}

//--- no��ǉ� ---//
void BitSet::Insert(int no)
{
	vec |= 1 << no;
}

//--- no���폜 ---//
void BitSet::Delete(int no)
{
	vec &= ~(1 << no);
}

//--- {bottom, �c, top}��ǉ� ---//
void BitSet::Fill(int bottom, int top)
{
	vec |= Lshift(~Lshift(~0U, top - bottom + 1), bottom);
}

//--- {bottom, �c, top}���폜 ---//
void BitSet::Clear(int bottom, int top)
{
	vec &= ~Lshift(~Lshift(~0U, top - bottom + 1), bottom);
}

//--- �W���������� �iBitSet += BitSet�j ---//
BitSet& BitSet::operator+=(const BitSet& set)
{
	vec |= set.vec;
	return (*this);
}

//--- �W�����|���� �iBitSet *= BitSet�j ---//
BitSet& BitSet::operator*=(const BitSet& set)
{
	vec &= set.vec;
	return (*this);
}

//--- �W�������� �iBitSet -= BitSet�j ---//
BitSet& BitSet::operator-=(const BitSet& set)
{
	vec &= ~(vec & set.vec);
	return (*this);
}

//--- �a�W�������߂� �iBitSet + BitSet�j ---//
BitSet operator+(const BitSet& st1, const BitSet& st2)
{
	BitSet temp;
	temp.vec = st1.vec | st2.vec;
	return (temp);
}

//--- �ϏW�������߂� �iBitSet * BitSet�j ---//
BitSet operator*(const BitSet& st1, const BitSet& st2)
{
	BitSet temp;
	temp.vec = st1.vec & st2.vec;
	return (temp);
}

//--- ���W�������߂� �iBitSet - BitSet�j ---//
BitSet operator-(const BitSet& st1, const BitSet& st2)
{
	BitSet temp;
	temp.vec = (st1.vec | st2.vec) & ~(st1.vec & st2.vec);
	return (temp);
}

//--- ���l���Z�q �iBitSet == BitSet�j ---//
int operator==(const BitSet& st1, const BitSet& st2)
{
	return (st1.vec == st2.vec);
}

//--- ���l���Z�q �iBitSet != BitSet�j ---//
int operator!=(const BitSet& st1, const BitSet& st2)
{
	return (st1.vec != st2.vec);
}

//--- �^�����W�����H �iBitSet < BitSet�j ---//
int operator<(const BitSet& st1, const BitSet& st2)
{
	return ((st1.vec & ~(st1.vec & st2.vec)) == 0 &&
			 st1.vec != st2.vec);
}

//--- �����W�����H �iBitSet <= BitSet�j ---//
int operator<=(const BitSet& st1, const BitSet& st2)
{
	return ((st1.vec & ~(st1.vec & st2.vec)) == 0);
}

//--- �^�����W�����H �iBitSet > BitSet�j ---//
int operator>(const BitSet& st1, const BitSet& st2)
{
	return ((st2.vec & ~(st2.vec & st1.vec)) == 0 &&
			 st1.vec != st2.vec);
}

//--- �����W�����H �iBitSet >= BitSet�j ---//
int operator>=(const BitSet& st1, const BitSet& st2)
{
	return ((st2.vec & ~(st2.vec & st1.vec)) == 0);
}

//--- �}�����Z�q ---//
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


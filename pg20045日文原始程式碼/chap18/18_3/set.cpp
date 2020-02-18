//-------------------------------------------------------------//
//  �W���N���X�t�@�~���i�������j                    "set.c"    //
//-------------------------------------------------------------//

#include    <iostream.h>

#include    "set.h"

//======================== class BitSet ========================//

int BitSet::len = BitSet::unsigned_len();

//--- unsigned�^�̃r�b�g���𐔂��� ---//
int BitSet::unsigned_len(void)
{
    int   count = 0;
    unsigned  x = ~0U;
    while (x) {
        if (x & 1) 
     count++;
        x >>= 1;
    }

    return (count);
}

//--- �R���X�g���N�^ ---//
BitSet::BitSet(unsigned set)
{
    vec = set;
}

//--- ��W���ɂ��� ---//
void BitSet::Empty(void)
{
    vec = 0;
}

//--- ��W�����H ---//
int BitSet::Null(void) const 
{
    return (vec == 0);
}

//--- �v�f���𓾂� ---//
int BitSet::Count(void) const 
{
    int  count = 0;
    unsigned  x = vec;
    while (x) {
        if (x & 1) count++;
        x >>= 1;
    }

    return (count);
}

//--- �ŏ��v�f�𓾂� ---//
int    BitSet::Min(void) const 
{
    int  min = 0, x = vec;

    if (x == 0)                    // ��W���Ȃ�-1��ԋp
        return (-1);
    while (1) {
        if (x & 1) break;
        x >>= 1;
        min++;
    }

    return (min);
}

//--- �ő�v�f�𓾂� ---//
int BitSet::Max(void) const 
{
    int  max = len - 1,msb = 1 << (len - 1);
    int  x = vec;

    if (x == 0)                    // ��W���Ȃ�-1��ԋp
        return (-1);
    while (1) {
        if (x & msb) break;
        x <<= 1;
        max--;
    }

    return (max);
}

//--- no���܂܂�Ă��邩 ---//
int BitSet::Member(int no) const
{
    return ((vec & (1 << no)) != 0);
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

//--- bottom����top��ǉ� ---//
void BitSet::Fill(int bottom, int top)
{
    vec |= Lshift(~Lshift(~0U, top - bottom + 1), bottom);
}

//--- bottom����top���폜 ---//
void BitSet::Clear(int bottom, int top)
{
    vec &= ~Lshift(~Lshift(~0U, top - bottom + 1), bottom);
}

//--- �f�[�^�̕\�� ---//
ostream& BitSet::Print(ostream& os) const
{
    unsigned  x = vec;
    os << "{ ";
    for (int i = 0; x ; i++) {    
        if (x & 1)
            cout << i << ' ';
        x >>= 1; 
    }
    return (os << "}");
}

//--- �a�W�������߂� ---//
BitSet& BitSet::operator+=(const BitSet& op1)
{
    vec |= op1.vec;
    return (*this);
}

//--- ���W�������߂� ---//
BitSet& BitSet::operator*=(const BitSet& op1)
{
    vec &= op1.vec;
    return (*this);
}

//--- �ϏW�������߂� ---//
BitSet& BitSet::operator-=(const BitSet& op1)
{
    vec &= ~(vec & op1.vec);
    return (*this);
}

//--- �a�W�������߂� ---//
BitSet operator+(const BitSet& op1, const BitSet& op2)
{
    BitSet  temp;
    temp.vec = op1.vec | op2.vec;
    return (temp);
}

//--- �ϏW�������߂� ---//
BitSet operator*(const BitSet& op1, const BitSet& op2)
{
    BitSet  temp;
    temp.vec = op1.vec & op2.vec;
    return (temp);
}

//--- ���W�������߂� ---//
BitSet operator-(const BitSet& op1, const BitSet& op2)
{
    BitSet  temp;
    temp.vec = op1.vec  & ~(op1.vec & op2.vec);
    return (temp);
}

//--- ���l���Z�q ---//
int operator==(const BitSet& op1, const BitSet& op2)
{
    return (op1.vec == op2.vec);
}

//--- ���l���Z�q ---//
int operator!=(const BitSet& op1, const BitSet& op2)
{
    return (op1.vec != op2.vec);
}

//--- �^�����W�����H ---//
int operator<(const BitSet& op1, const BitSet& op2)
{
    return ((op1 - op2).Null() && op1 != op2);
}

//--- �����W�����H ---//
int operator<=(const BitSet& op1, const BitSet& op2)
{
    return ((op1 - op2).Null());
}

//--- �^�����W�����H ---//
int operator>(const BitSet& op1, const BitSet& op2)
{
    return ((op2 - op1).Null());
}

//--- �����W�����H ---//
int operator>=(const BitSet& op1, const BitSet& op2)
{
    return ((op2 - op1).Null() && op1 != op2);
}

//======================== class BndSet ========================//

//--- �R���X�g���N�^ ---//
BndSet::BndSet(unsigned m) : max(m)
{
    bnum = max / BitSet::len + 1;
    ptr = new BitSet[bnum];
}

//--- �R�s�[�R���X�g���N�^ ---//
BndSet::BndSet(const BndSet& op1) : max(op1.max), bnum(op1.bnum)
{
    ptr = new BitSet[bnum];
    for (int i = 0; i < bnum; i++)
        ptr[i] = op1.ptr[i];
}

//--- ��W���ɂ��� ---//
void BndSet::Empty(void)
{
    for (int i = 0; i < bnum ; i++)
        ptr[i].Empty();
}

//--- ��W�����H ---//
int BndSet::Null(void) const
{
    for (int i = 0; i < bnum ; i++)
        if (!ptr[i].Null()) return (0);
    return (1);
}

//--- �v�f���𓾂� ---//
int BndSet::Count(void) const
{
    int  count = 0;
    for (int i = 0; i < bnum ; i++)
        count += ptr[i].Count();
    return (count);
}

//--- �ŏ��v�f�𓾂� ---//
int    BndSet::Min(void) const
{
    int  min;

    if (Null())                    // ��W���Ȃ�-1��ԋp
        return (-1);
    for (int i = 0; i < bnum ; i++)
        if ((min = ptr[i].Count()) != -1)
            break;
    return (min);
}

//--- �ő�v�f�𓾂� ---//
int    BndSet::Max(void) const
{
    int  max;

    if (Null())                    // ��W���Ȃ�-1��ԋp
        return (-1);//bnum 
    for (int i = bnum  - 1; i >= 0; i--)
        if ((max = ptr[i].Max()) != -1)
            break;
    return (max + i * BitSet::len);
}

//--- no���܂܂�Ă��邩 ---//
int BndSet::Member(int no) const
{
    if (no < 0 && no >= max)
        return (0);
    return (ptr[no / BitSet::len].Member(no % BitSet::len));
}

//--- no��ǉ� ---//
void BndSet::Insert(int no)
{
    if (no >= 0 && no < max)
        ptr[no / BitSet::len].Insert(no % BitSet::len);
}

//--- no���폜 ---//
void BndSet::Delete(int no)
{
    if (no >= 0 && no < max)
        ptr[no / BitSet::len].Delete(no % BitSet::len);
}

//--- bottom����top��ǉ� ---//
void BndSet::Fill(int bottom, int top)
{
    if (bottom <= max && 0 <= bottom && top < max) {
        int  t = top / BitSet::len;
        int  tb = top % BitSet::len;
        int  b = bottom / BitSet::len;
        int  bb = bottom % BitSet::len;

        if (t == b)
            ptr[b].Fill(bb, tb);
        else {
            ptr[b].Fill(bb, BitSet::len - 1);
            for (int i = b + 1; i < t; i++)
                ptr[i].Fill(0, BitSet::len - 1);
            ptr[t].Fill(0, tb);
        }
    }
}

//--- bottom����top���폜 ---//
void BndSet::Clear(int bottom, int top)
{
    if (bottom <= max && 0 <= bottom && top < max) {
        int  t = top / BitSet::len;
        int  tb = top % BitSet::len;
        int  b = bottom / BitSet::len;
        int  bb = bottom % BitSet::len;

        if (t == b)
            ptr[b].Clear(bb, tb);
        else {
            ptr[b].Fill(bb, BitSet::len - 1);
            for (int i = b + 1; i < t; i++)
                ptr[i].Clear(0, BitSet::len - 1);
            ptr[t].Clear(0, tb);
        }
    }
}
           
//--- �f�[�^�̕\�� ---//
void BndSet::Print(ostream& os) const
{
    os << "{ ";
    for (int i = 0; i < bnum ; i++) {    
        for (int j = 0; j < len; j++)
            if (ptr[i].Member(j))
                cout << i * len + j << ' ';
    }
    return (os << "}");
}

//--- ������Z�q ---//
BndSet& BndSet::operator=(const BndSet& op1)
{
    bnum = op1.bnum;
    max = op1.max;
    delete[] ptr;
    ptr = new BitSet[bnum];
    for (int i = 0; i < bnum; i++)
        ptr[i] = op1.ptr[i];
    return (*this);
}

//--- �a�W�������߂� ---//
BndSet& BndSet::operator+=(const BndSet& op1)
{
    int  x = (op1.bnum < bnum) ? op1.bnum : bnum;
    for (int i = 0; i < x; i++)
        ptr[i] += op1.ptr[i];
    return (*this);
}

//--- �ϏW�������߂� ---//
BndSet& BndSet::operator*=(const BndSet& op1)
{
    int  x = (op1.bnum < bnum) ? op1.bnum : bnum;
    for (int i = 0; i < x; i++)
        ptr[i] *= op1.ptr[i];
    return (*this);
}

//--- ���W�������߂� ---//
BndSet& BndSet::operator-=(const BndSet& op1)
{
    int  x = (op1.bnum < bnum) ? op1.bnum : bnum;
    for (int i = 0; i < x; i++)
        ptr[i] -= op1.ptr[i];
    return (*this);
}

//--- �a�W�������߂� ---//
BndSet operator+(const BndSet& op1, const BndSet& op2)
{
    BndSet  temp(op1);
    temp += op2;
    return (temp);
}

//--- �ϏW�������߂� ---//
BndSet operator*(const BndSet& op1, const BndSet& op2)
{
    BndSet  temp(op1);
    temp *= op2;
    return (temp);
}

//--- ���W�������߂� ---//
BndSet operator-(const BndSet& op1, const BndSet& op2)
{
    BndSet  temp(op1);
    temp -= op2;
    return (temp);
}

//--- ���l���Z�q ---//
int operator==(const BndSet& op1, const BndSet& op2)
{
    if (op1.Max() != op2.Max())
        return (0);
    int  x = (op1.bnum < op2.bnum) ? op1.bnum : op2.bnum;
    for (int i = 0; i < x; i++)
        if (op1.ptr[i] != op2.ptr[i])
            return (0);
    return (1);
}

//--- ���l���Z�q ---//
int operator!=(const BndSet& op1, const BndSet& op2)
{
    if (op1.Max() != op2.Max())
        return (1);
    int  x = (op1.bnum < op2.bnum) ? op1.bnum : op2.bnum;
    for (int i = 0; i < x; i++)
        if (op1.ptr[i] == op2.ptr[i])
            return (0);
    return (1);
}

//--- �^�����W�����H ---//
int operator<(const BndSet& op1, const BndSet& op2)
{
    return ((op1 - op2).Null() && op1 != op2);
}

//--- �����W�����H ---//
int operator<=(const BndSet& op1, const BndSet& op2)
{
    return ((op1 - op2).Null());
}

//--- �^�����W�����H ---//
int operator>(const BndSet& op1, const BndSet& op2)
{
    return ((op2 - op1).Null() && op1 != op2);
}

//--- �����W�����H ---//
int operator>=(const BndSet& op1, const BndSet& op2)
{
    return ((op2 - op1).Null());
}

//======================= class ListSet =======================//

//--- �R�s�[�R���X�g���N�^ ---//
ListSet::ListSet(const ListSet& op1) : max(0)
{
    if (op1.max) {
        TypeNode<int>*  temp = (TypeNode<int>*)op1.list.Top();
        TypeNode<int>*  bottom = 
                    (TypeNode<int>*)op1.list.Bottom()->Next();

        while (temp != bottom) {
            Insert(*temp);
            temp = (TypeNode<int>*)temp->Next();
        }
    }
}

//--- ��W���ɂ��� ---//
void ListSet::Empty(void)
{
    list.Clear();
    max = 0;
}

//--- ��W���� ---//
int ListSet::Null(void) const
{
    return (list.Top() == NULL);
}

//--- �v�f���𓾂� ---//
int ListSet::Count(void) const
{
    return (max);
}

//--- �ŏ��v�f�𓾂� ---//
int ListSet::Min(void) const
{
    if (!max)                            // �����Ƃ��ɂ�-1��ԋp
        return (-1);

    TypeNode<int>* temp = (TypeNode<int>*)list.Top();
    TypeNode<int>* bottom =
                         (TypeNode<int>*)list.Bottom()->Next();
    int  min = (int)*temp;
    temp = (TypeNode<int>*)temp->Next();
    while (temp != bottom) {
        if (*temp < min)
                min = (int)*temp;
        temp = (TypeNode<int>*)temp->Next();
    }

    return (min);
}

//--- �ő�v�f�𓾂� ---//
int ListSet::Max(void) const
{
    if (!max)                            // �����Ƃ��ɂ�-1��ԋp
        return (-1);
    TypeNode<int>*  temp = (TypeNode<int>*)list.Top();
    TypeNode<int>*  bottom =
                         (TypeNode<int>*)list.Bottom()->Next();

    int  max = (int)*temp;
    temp = (TypeNode<int>*)temp->Next();
    while (temp != bottom) {
        if (*temp > max)
            max = (int)*temp;
        temp = (TypeNode<int>*)temp->Next();
    }
    return (max);
}

//--- no���܂܂�Ă��邩 ---//
int ListSet::Member(int no) const
{
    if (max) {
        TypeNode<int>*  temp = (TypeNode<int>*)list.Top();
        TypeNode<int>*  bottom =
                         (TypeNode<int>*)list.Bottom()->Next();

        while (temp != bottom) {
            if (*temp == no)    // �܂܂�Ă���Ƃ��ɂ�1��ԋp
                return (1);
            temp = (TypeNode<int>*)temp->Next();
        }
    }

    return (0);                            // �����Ƃ��ɂ�0��ԋp
}

//--- no��ǉ� ---//
void ListSet::Insert(int no)
{
    if (!Member(no)) {
        list.Insert(new TypeNode<int>(no));
        max++;
    }
}

//--- no���폜 ---//
void ListSet::Delete(int no)
{
    if (max && kill(list, no))
            max--;
}

//--- bottom����top��ǉ� ---//
void ListSet::Fill(int bottom, int top)
{
    for (int i = bottom; i <= top; i++)
        Insert(i);
}

//--- bottom����top���폜 ---//
void ListSet::Clear(int bottom, int top)
{
    for (int i = bottom; i <= top; i++)
        Delete(i);
}

//--- �f�[�^�̕\�� ---//
ostream& ListSet::Print(ostream& os) const
{
    os << "{ ";
    if (list.Top() != NULL) {
        TypeNode<int>*  temp = (TypeNode<int>*)list.Top();
        TypeNode<int>*  bottom =
                         (TypeNode<int>*)list.Bottom()->Next();

        while (temp != bottom) {
            os << *temp << ' ';
            temp = (TypeNode<int>*)temp->Next();
        }
    }
    return (os << "}");
}

//--- ������Z�q ---//
ListSet& ListSet::operator=(const ListSet& op1)
{
    list.Clear();
    if (op1.max) {

        TypeNode<int>*  temp = (TypeNode<int>*)op1.list.Top();
        TypeNode<int>*  bottom = 
                    (TypeNode<int>*)op1.list.Bottom()->Next();
        while (temp != bottom) {
            Insert(*temp);
            temp = (TypeNode<int>*)temp->Next();
        }
    }

    return (*this);
}

//--- �a�W�������߂� ---//
ListSet& ListSet::operator+=(const ListSet& op1)
{
    if (op1.max) {
        TypeNode<int>*  temp = (TypeNode<int>*)op1.list.Top();
        TypeNode<int>*  bottom = 
                    (TypeNode<int>*)op1.list.Bottom()->Next();

        while (temp != bottom) {
            Insert(int(*temp));
            temp = (TypeNode<int>*)temp->Next();
        }
    }

    return (*this);
}

//--- �ϏW�������߂� ---//
ListSet& ListSet::operator*=(const ListSet& op1)
{
    if (max) {
        TypeNode<int>* temp = (TypeNode<int>*)list.Top();
        TypeNode<int>* bottom =
                         (TypeNode<int>*)list.Bottom()->Next();
        while (temp != bottom) {
            if (!op1.Member(*temp)) {
                TypeNode<int>*  a = (TypeNode<int>*)temp->Next();
                Delete(*temp);
                temp = a;
            } else {
                temp = (TypeNode<int>*)temp->Next();
            }
        }
    }

    return (*this);
}

//--- ���W�������߂� ---//
ListSet& ListSet::operator-=(const ListSet& op1)
{
    if (op1.max) {
        TypeNode<int>* temp = (TypeNode<int>*)op1.list.Top();
        TypeNode<int>* bottom = 
                    (TypeNode<int>*)op1.list.Bottom()->Next();

        while (temp != bottom) {
            if (Member(*temp)) {
                TypeNode<int>*  a = (TypeNode<int>*)temp->Next();
                Delete(*temp);
                temp = a;
            } else {
                temp = (TypeNode<int>*)temp->Next();
            }
        }
    }

    return (*this);
}

//--- �a�W�������߂� ---//
ListSet operator+(const ListSet& op1, const ListSet& op2)
{
    ListSet  temp(op1);
    temp += op2;
    return (temp);
}

//--- �ϏW�������߂� ---//
ListSet operator*(const ListSet& op1, const ListSet& op2)
{
    ListSet  temp(op1);
    temp *= op2;
    return (temp);
}

//--- ���W�������߂� ---//
ListSet operator-(const ListSet& op1, const ListSet& op2)
{
    ListSet  temp(op1);
    temp -= op2;
    return (temp);
}

//--- ���l���Z�q ---//
int operator==(const ListSet& op1, const ListSet& op2)
{
    if (op1.max) {
        TypeNode<int>* temp = (TypeNode<int>*)op1.list.Top();
        TypeNode<int>* bottom = 
                    (TypeNode<int>*)op1.list.Bottom()->Next();
        while (temp != bottom) {
            if (!op2.Member(*temp))
                return (0);
            temp = (TypeNode<int>*)temp->Next();
        }
        return (1);
    }
    if (!op2.max)
        return (1);
    return (0);
}

//--- ���l���Z�q ---//
int operator!=(const ListSet& op1, const ListSet& op2)
{
    return (!(op1 == op2));
}

//--- �^�����W�����H ---//
int operator<(const ListSet& op1, const ListSet& op2)
{
    return ((op1 - op2).Null() && op1 != op2);
}

//--- �����W�����H ---//
int operator<=(const ListSet& op1, const ListSet& op2)
{
    return ((op1 - op2).Null());
}

//--- �^�����W�����H ---//
int operator>(const ListSet& op1, const ListSet& op2)
{
    return ((op2 - op1).Null() && op1 != op2);
}

//--- �����W�����H ---//
int operator>=(const ListSet& op1, const ListSet& op2)
{
    return ((op2 - op1).Null());
}

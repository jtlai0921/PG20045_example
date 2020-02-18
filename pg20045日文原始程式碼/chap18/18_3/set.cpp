//-------------------------------------------------------------//
//  集合クラスファミリ（実現部）                    "set.c"    //
//-------------------------------------------------------------//

#include    <iostream.h>

#include    "set.h"

//======================== class BitSet ========================//

int BitSet::len = BitSet::unsigned_len();

//--- unsigned型のビット数を数える ---//
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

//--- コンストラクタ ---//
BitSet::BitSet(unsigned set)
{
    vec = set;
}

//--- 空集合にする ---//
void BitSet::Empty(void)
{
    vec = 0;
}

//--- 空集合か？ ---//
int BitSet::Null(void) const 
{
    return (vec == 0);
}

//--- 要素数を得る ---//
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

//--- 最小要素を得る ---//
int    BitSet::Min(void) const 
{
    int  min = 0, x = vec;

    if (x == 0)                    // 空集合なら-1を返却
        return (-1);
    while (1) {
        if (x & 1) break;
        x >>= 1;
        min++;
    }

    return (min);
}

//--- 最大要素を得る ---//
int BitSet::Max(void) const 
{
    int  max = len - 1,msb = 1 << (len - 1);
    int  x = vec;

    if (x == 0)                    // 空集合なら-1を返却
        return (-1);
    while (1) {
        if (x & msb) break;
        x <<= 1;
        max--;
    }

    return (max);
}

//--- noが含まれているか ---//
int BitSet::Member(int no) const
{
    return ((vec & (1 << no)) != 0);
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

//--- bottomからtopを追加 ---//
void BitSet::Fill(int bottom, int top)
{
    vec |= Lshift(~Lshift(~0U, top - bottom + 1), bottom);
}

//--- bottomからtopを削除 ---//
void BitSet::Clear(int bottom, int top)
{
    vec &= ~Lshift(~Lshift(~0U, top - bottom + 1), bottom);
}

//--- データの表示 ---//
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

//--- 和集合を求める ---//
BitSet& BitSet::operator+=(const BitSet& op1)
{
    vec |= op1.vec;
    return (*this);
}

//--- 差集合を求める ---//
BitSet& BitSet::operator*=(const BitSet& op1)
{
    vec &= op1.vec;
    return (*this);
}

//--- 積集合を求める ---//
BitSet& BitSet::operator-=(const BitSet& op1)
{
    vec &= ~(vec & op1.vec);
    return (*this);
}

//--- 和集合を求める ---//
BitSet operator+(const BitSet& op1, const BitSet& op2)
{
    BitSet  temp;
    temp.vec = op1.vec | op2.vec;
    return (temp);
}

//--- 積集合を求める ---//
BitSet operator*(const BitSet& op1, const BitSet& op2)
{
    BitSet  temp;
    temp.vec = op1.vec & op2.vec;
    return (temp);
}

//--- 差集合を求める ---//
BitSet operator-(const BitSet& op1, const BitSet& op2)
{
    BitSet  temp;
    temp.vec = op1.vec  & ~(op1.vec & op2.vec);
    return (temp);
}

//--- 等値演算子 ---//
int operator==(const BitSet& op1, const BitSet& op2)
{
    return (op1.vec == op2.vec);
}

//--- 等値演算子 ---//
int operator!=(const BitSet& op1, const BitSet& op2)
{
    return (op1.vec != op2.vec);
}

//--- 真部分集合か？ ---//
int operator<(const BitSet& op1, const BitSet& op2)
{
    return ((op1 - op2).Null() && op1 != op2);
}

//--- 部分集合か？ ---//
int operator<=(const BitSet& op1, const BitSet& op2)
{
    return ((op1 - op2).Null());
}

//--- 真部分集合か？ ---//
int operator>(const BitSet& op1, const BitSet& op2)
{
    return ((op2 - op1).Null());
}

//--- 部分集合か？ ---//
int operator>=(const BitSet& op1, const BitSet& op2)
{
    return ((op2 - op1).Null() && op1 != op2);
}

//======================== class BndSet ========================//

//--- コンストラクタ ---//
BndSet::BndSet(unsigned m) : max(m)
{
    bnum = max / BitSet::len + 1;
    ptr = new BitSet[bnum];
}

//--- コピーコンストラクタ ---//
BndSet::BndSet(const BndSet& op1) : max(op1.max), bnum(op1.bnum)
{
    ptr = new BitSet[bnum];
    for (int i = 0; i < bnum; i++)
        ptr[i] = op1.ptr[i];
}

//--- 空集合にする ---//
void BndSet::Empty(void)
{
    for (int i = 0; i < bnum ; i++)
        ptr[i].Empty();
}

//--- 空集合か？ ---//
int BndSet::Null(void) const
{
    for (int i = 0; i < bnum ; i++)
        if (!ptr[i].Null()) return (0);
    return (1);
}

//--- 要素数を得る ---//
int BndSet::Count(void) const
{
    int  count = 0;
    for (int i = 0; i < bnum ; i++)
        count += ptr[i].Count();
    return (count);
}

//--- 最小要素を得る ---//
int    BndSet::Min(void) const
{
    int  min;

    if (Null())                    // 空集合なら-1を返却
        return (-1);
    for (int i = 0; i < bnum ; i++)
        if ((min = ptr[i].Count()) != -1)
            break;
    return (min);
}

//--- 最大要素を得る ---//
int    BndSet::Max(void) const
{
    int  max;

    if (Null())                    // 空集合なら-1を返却
        return (-1);//bnum 
    for (int i = bnum  - 1; i >= 0; i--)
        if ((max = ptr[i].Max()) != -1)
            break;
    return (max + i * BitSet::len);
}

//--- noが含まれているか ---//
int BndSet::Member(int no) const
{
    if (no < 0 && no >= max)
        return (0);
    return (ptr[no / BitSet::len].Member(no % BitSet::len));
}

//--- noを追加 ---//
void BndSet::Insert(int no)
{
    if (no >= 0 && no < max)
        ptr[no / BitSet::len].Insert(no % BitSet::len);
}

//--- noを削除 ---//
void BndSet::Delete(int no)
{
    if (no >= 0 && no < max)
        ptr[no / BitSet::len].Delete(no % BitSet::len);
}

//--- bottomからtopを追加 ---//
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

//--- bottomからtopを削除 ---//
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
           
//--- データの表示 ---//
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

//--- 代入演算子 ---//
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

//--- 和集合を求める ---//
BndSet& BndSet::operator+=(const BndSet& op1)
{
    int  x = (op1.bnum < bnum) ? op1.bnum : bnum;
    for (int i = 0; i < x; i++)
        ptr[i] += op1.ptr[i];
    return (*this);
}

//--- 積集合を求める ---//
BndSet& BndSet::operator*=(const BndSet& op1)
{
    int  x = (op1.bnum < bnum) ? op1.bnum : bnum;
    for (int i = 0; i < x; i++)
        ptr[i] *= op1.ptr[i];
    return (*this);
}

//--- 差集合を求める ---//
BndSet& BndSet::operator-=(const BndSet& op1)
{
    int  x = (op1.bnum < bnum) ? op1.bnum : bnum;
    for (int i = 0; i < x; i++)
        ptr[i] -= op1.ptr[i];
    return (*this);
}

//--- 和集合を求める ---//
BndSet operator+(const BndSet& op1, const BndSet& op2)
{
    BndSet  temp(op1);
    temp += op2;
    return (temp);
}

//--- 積集合を求める ---//
BndSet operator*(const BndSet& op1, const BndSet& op2)
{
    BndSet  temp(op1);
    temp *= op2;
    return (temp);
}

//--- 差集合を求める ---//
BndSet operator-(const BndSet& op1, const BndSet& op2)
{
    BndSet  temp(op1);
    temp -= op2;
    return (temp);
}

//--- 等値演算子 ---//
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

//--- 等値演算子 ---//
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

//--- 真部分集合か？ ---//
int operator<(const BndSet& op1, const BndSet& op2)
{
    return ((op1 - op2).Null() && op1 != op2);
}

//--- 部分集合か？ ---//
int operator<=(const BndSet& op1, const BndSet& op2)
{
    return ((op1 - op2).Null());
}

//--- 真部分集合か？ ---//
int operator>(const BndSet& op1, const BndSet& op2)
{
    return ((op2 - op1).Null() && op1 != op2);
}

//--- 部分集合か？ ---//
int operator>=(const BndSet& op1, const BndSet& op2)
{
    return ((op2 - op1).Null());
}

//======================= class ListSet =======================//

//--- コピーコンストラクタ ---//
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

//--- 空集合にする ---//
void ListSet::Empty(void)
{
    list.Clear();
    max = 0;
}

//--- 空集合か ---//
int ListSet::Null(void) const
{
    return (list.Top() == NULL);
}

//--- 要素数を得る ---//
int ListSet::Count(void) const
{
    return (max);
}

//--- 最小要素を得る ---//
int ListSet::Min(void) const
{
    if (!max)                            // 無いときには-1を返却
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

//--- 最大要素を得る ---//
int ListSet::Max(void) const
{
    if (!max)                            // 無いときには-1を返却
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

//--- noが含まれているか ---//
int ListSet::Member(int no) const
{
    if (max) {
        TypeNode<int>*  temp = (TypeNode<int>*)list.Top();
        TypeNode<int>*  bottom =
                         (TypeNode<int>*)list.Bottom()->Next();

        while (temp != bottom) {
            if (*temp == no)    // 含まれているときには1を返却
                return (1);
            temp = (TypeNode<int>*)temp->Next();
        }
    }

    return (0);                            // 無いときには0を返却
}

//--- noを追加 ---//
void ListSet::Insert(int no)
{
    if (!Member(no)) {
        list.Insert(new TypeNode<int>(no));
        max++;
    }
}

//--- noを削除 ---//
void ListSet::Delete(int no)
{
    if (max && kill(list, no))
            max--;
}

//--- bottomからtopを追加 ---//
void ListSet::Fill(int bottom, int top)
{
    for (int i = bottom; i <= top; i++)
        Insert(i);
}

//--- bottomからtopを削除 ---//
void ListSet::Clear(int bottom, int top)
{
    for (int i = bottom; i <= top; i++)
        Delete(i);
}

//--- データの表示 ---//
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

//--- 代入演算子 ---//
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

//--- 和集合を求める ---//
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

//--- 積集合を求める ---//
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

//--- 差集合を求める ---//
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

//--- 和集合を求める ---//
ListSet operator+(const ListSet& op1, const ListSet& op2)
{
    ListSet  temp(op1);
    temp += op2;
    return (temp);
}

//--- 積集合を求める ---//
ListSet operator*(const ListSet& op1, const ListSet& op2)
{
    ListSet  temp(op1);
    temp *= op2;
    return (temp);
}

//--- 差集合を求める ---//
ListSet operator-(const ListSet& op1, const ListSet& op2)
{
    ListSet  temp(op1);
    temp -= op2;
    return (temp);
}

//--- 等値演算子 ---//
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

//--- 等値演算子 ---//
int operator!=(const ListSet& op1, const ListSet& op2)
{
    return (!(op1 == op2));
}

//--- 真部分集合か？ ---//
int operator<(const ListSet& op1, const ListSet& op2)
{
    return ((op1 - op2).Null() && op1 != op2);
}

//--- 部分集合か？ ---//
int operator<=(const ListSet& op1, const ListSet& op2)
{
    return ((op1 - op2).Null());
}

//--- 真部分集合か？ ---//
int operator>(const ListSet& op1, const ListSet& op2)
{
    return ((op2 - op1).Null() && op1 != op2);
}

//--- 部分集合か？ ---//
int operator>=(const ListSet& op1, const ListSet& op2)
{
    return ((op2 - op1).Null());
}

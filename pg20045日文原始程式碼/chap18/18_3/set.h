//-------------------------------------------------------------//
//  集合クラスファミリ（インタフェイス部）          "set.h"    //
//-------------------------------------------------------------//

#include    <iostream.h>

#include    "list.h"

//--- 集合クラス（抽象クラス）---//
class Set {

public:
    virtual void Empty(void) = 0;              // 空集合にする
    virtual int  Null(void) const = 0;         // 空集合か？
    virtual int  Count(void) const = 0;        // 要素数を得る
    virtual int  Min(void) const = 0;          // 最小要素を得る
    virtual int  Max(void) const = 0;          // 最大要素を得る
    virtual int  Member(int no) const = 0;     // noが含まれているか
    virtual void Insert(int no) = 0;           // noを追加
    virtual void Delete(int no) = 0;           // noを削除
    virtual void Fill(int bottom, int top) = 0;
    virtual void Clear(int bottom, int top) = 0;
    virtual ostream& Print(ostream& os) const = 0;    // データ表示
};

//--- 挿入演算子 ---//
inline ostream& operator<<(ostream& os, const Set& st)
{
    return (st.Print(os));
}

//--- unsinged版集合クラス ---//
class BitSet : public Set {

private:
    unsigned   vec;                        // 集合
    static int unsigned_len(void);

    static unsigned Lshift(unsigned x, int a)
    {
        return ((a >= len) ? 0 : (x << a));
    }

public:
    static const int len;              // unsigned型のビット数

    BitSet(unsigned set = 0);           // コンストラクタ
    void Empty(void);                   // 空集合にする
    int Null(void) const;               // 空集合か？
    int  Count(void) const;             // 要素数を得る
    int  Min(void) const;               // 最小要素を得る
    int  Max(void) const;               // 最大要素を得る
    int  Member(int no) const;          // noが含まれているか
    void Insert(int no);                // noを追加
    void Delete(int no);                // noを削除
    void Fill(int bottom, int top);     // bottomからtopを追加
    void Clear(int bottom, int top);    // bottomからtopを削除
    ostream& Print(ostream& os) const;  // データの表示

    BitSet& operator+=(const BitSet& op1);
    BitSet& operator*=(const BitSet& op1);
    BitSet& operator-=(const BitSet& op1);
    friend BitSet operator+(const BitSet& op1, const BitSet& op2);
    friend BitSet operator*(const BitSet& op1, const BitSet& op2);
    friend int operator==(const BitSet& op1, const BitSet& op2);
    friend BitSet operator-(const BitSet& op1, const BitSet& op2);

    friend int operator!=(const BitSet& op1, const BitSet& op2);
    friend int operator<(const BitSet& op1, const BitSet& op2);
    friend int operator<=(const BitSet& op1, const BitSet& op2);
    friend int operator>(const BitSet& op1, const BitSet& op2);
    friend int operator>=(const BitSet& op1, const BitSet& op2);
};

//--- 上限付き集合 ---//
class BndSet : public Set {

private:
    int  bnum;                          // BitSetオブジェクトの数
    int  max;                           // 要素数
    BitSet*  ptr;                       // BitSetの配列へのポインタ

public:
    BndSet(unsigned m);                 // コンストラクタ
    ~BndSet(void) { delete ptr; }       // デストラクタ
    BndSet(const BndSet& op1);          // コピーコンストラクタ

    void Empty(void);                   // 空集合にする
    int Null(void) const;               // 空集合か？
    int Count(void) const;              // 要素数を得る
    int    Min(void) const;             // 最小要素を得る
    int    Max(void) const;             // 最大要素を得る
    int Member(int no) const;           // noが含まれているか
    void Insert(int no);                // noを追加
    void Delete(int no);                // noを削除
    void Fill(int bottom, int top);     // bottomからtopを追加
    void Clear(int bottom, int top);    // bottomからtopを削除
    ostream& Print(ostream& os) const;  // データの表示

    BndSet& operator=(const BndSet& op1);
    BndSet& operator+=(const BndSet& op1);
    BndSet& operator*=(const BndSet& op1);
    BndSet& operator-=(const BndSet& op1);

    friend BndSet operator+(const BndSet& op1, const BndSet& op2);
    friend BndSet operator*(const BndSet& op1, const BndSet& op2);
    friend BndSet operator-(const BndSet& op1, const BndSet& op2);

    friend int operator==(const BndSet& op1, const BndSet& op2);
    friend int operator!=(const BndSet& op1, const BndSet& op2);
    friend int operator<(const BndSet& op1, const BndSet& op2);
    friend int operator<=(const BndSet& op1, const BndSet& op2);
    friend int operator>(const BndSet& op1, const BndSet& op2);
    friend int operator>=(const BndSet& op1, const BndSet& op2);
};

//--- リスト集合クラス ---//
class ListSet : public Set {

private:
    int   max;                           // 要素数
    List  list;

public:
    ListSet(void) : max(0) { }           // コンストラクタ
    ListSet(const ListSet& op1);         // コピーコンストラクタ
    void Empty(void);                    // 空集合にする
    int Null(void) const;                // 空集合か？
    int Count(void) const;               // 要素数を得る
    int Min(void) const;                 // 最小要素を得る
    int Max(void) const;                 // 最大要素を得る
    int Member(int no) const;            // noが含まれているか
    void Insert(int no);                 // noを追加
    void Delete(int no);                 // noを削除
    void Fill(int bottom, int top);      // bottomからtopを追加
    void Clear(int bottom, int top);     // bottomからtopを削除
    ostream& Print(ostream& os) const;   // データの表示

    ListSet& operator=(const ListSet& op1);
    ListSet& operator+=(const ListSet& op1);
    ListSet& operator*=(const ListSet& op1);
    ListSet& operator-=(const ListSet& op1);
    friend ListSet operator+(const ListSet& , const ListSet& );
    friend ListSet operator*(const ListSet& , const ListSet& );
    friend ListSet operator-(const ListSet& , const ListSet& );

    friend int operator==(const ListSet& op1, const ListSet& op2);
    friend int operator!=(const ListSet& op1, const ListSet& op2);
    friend int operator<(const ListSet& op1, const ListSet& op2);
    friend int operator<=(const ListSet& op1, const ListSet& op2);
    friend int operator>(const ListSet& op1, const ListSet& op2);
    friend int operator>=(const ListSet& op1, const ListSet& op2);
};

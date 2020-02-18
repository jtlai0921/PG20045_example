//-------------------------------------------------------------//
//  �W���N���X�t�@�~���i�C���^�t�F�C�X���j          "set.h"    //
//-------------------------------------------------------------//

#include    <iostream.h>

#include    "list.h"

//--- �W���N���X�i���ۃN���X�j---//
class Set {

public:
    virtual void Empty(void) = 0;              // ��W���ɂ���
    virtual int  Null(void) const = 0;         // ��W�����H
    virtual int  Count(void) const = 0;        // �v�f���𓾂�
    virtual int  Min(void) const = 0;          // �ŏ��v�f�𓾂�
    virtual int  Max(void) const = 0;          // �ő�v�f�𓾂�
    virtual int  Member(int no) const = 0;     // no���܂܂�Ă��邩
    virtual void Insert(int no) = 0;           // no��ǉ�
    virtual void Delete(int no) = 0;           // no���폜
    virtual void Fill(int bottom, int top) = 0;
    virtual void Clear(int bottom, int top) = 0;
    virtual ostream& Print(ostream& os) const = 0;    // �f�[�^�\��
};

//--- �}�����Z�q ---//
inline ostream& operator<<(ostream& os, const Set& st)
{
    return (st.Print(os));
}

//--- unsinged�ŏW���N���X ---//
class BitSet : public Set {

private:
    unsigned   vec;                        // �W��
    static int unsigned_len(void);

    static unsigned Lshift(unsigned x, int a)
    {
        return ((a >= len) ? 0 : (x << a));
    }

public:
    static const int len;              // unsigned�^�̃r�b�g��

    BitSet(unsigned set = 0);           // �R���X�g���N�^
    void Empty(void);                   // ��W���ɂ���
    int Null(void) const;               // ��W�����H
    int  Count(void) const;             // �v�f���𓾂�
    int  Min(void) const;               // �ŏ��v�f�𓾂�
    int  Max(void) const;               // �ő�v�f�𓾂�
    int  Member(int no) const;          // no���܂܂�Ă��邩
    void Insert(int no);                // no��ǉ�
    void Delete(int no);                // no���폜
    void Fill(int bottom, int top);     // bottom����top��ǉ�
    void Clear(int bottom, int top);    // bottom����top���폜
    ostream& Print(ostream& os) const;  // �f�[�^�̕\��

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

//--- ����t���W�� ---//
class BndSet : public Set {

private:
    int  bnum;                          // BitSet�I�u�W�F�N�g�̐�
    int  max;                           // �v�f��
    BitSet*  ptr;                       // BitSet�̔z��ւ̃|�C���^

public:
    BndSet(unsigned m);                 // �R���X�g���N�^
    ~BndSet(void) { delete ptr; }       // �f�X�g���N�^
    BndSet(const BndSet& op1);          // �R�s�[�R���X�g���N�^

    void Empty(void);                   // ��W���ɂ���
    int Null(void) const;               // ��W�����H
    int Count(void) const;              // �v�f���𓾂�
    int    Min(void) const;             // �ŏ��v�f�𓾂�
    int    Max(void) const;             // �ő�v�f�𓾂�
    int Member(int no) const;           // no���܂܂�Ă��邩
    void Insert(int no);                // no��ǉ�
    void Delete(int no);                // no���폜
    void Fill(int bottom, int top);     // bottom����top��ǉ�
    void Clear(int bottom, int top);    // bottom����top���폜
    ostream& Print(ostream& os) const;  // �f�[�^�̕\��

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

//--- ���X�g�W���N���X ---//
class ListSet : public Set {

private:
    int   max;                           // �v�f��
    List  list;

public:
    ListSet(void) : max(0) { }           // �R���X�g���N�^
    ListSet(const ListSet& op1);         // �R�s�[�R���X�g���N�^
    void Empty(void);                    // ��W���ɂ���
    int Null(void) const;                // ��W�����H
    int Count(void) const;               // �v�f���𓾂�
    int Min(void) const;                 // �ŏ��v�f�𓾂�
    int Max(void) const;                 // �ő�v�f�𓾂�
    int Member(int no) const;            // no���܂܂�Ă��邩
    void Insert(int no);                 // no��ǉ�
    void Delete(int no);                 // no���폜
    void Fill(int bottom, int top);      // bottom����top��ǉ�
    void Clear(int bottom, int top);     // bottom����top���폜
    ostream& Print(ostream& os) const;   // �f�[�^�̕\��

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

//-------------------------------------------------------------//
//	�z�񃊃X�g�N���X FixedList					"fixedlist.h"  //
//-------------------------------------------------------------//

//===== �z�񃊃X�g�N���X�̃m�[�h =====//
template<class Type>
class FixedNode {
	friend class FixedList<Type>;

private:
	Type  data;		// �f�[�^
	int	  next;
	int	  dnext;

public:
	Type Data(void) const { return (data); }	// �f�[�^��ԋp
	int Next(void)  const { return (next); }
};

//===== �z�񃊃X�g�N���X =====//
template<class Type>
class FixedList {

private:
	FixedNode<Type>	*ptr;
	int	 size;				// ���X�g���i�[����z��̗v�f��
	int	 top;				// ���`���X�g�̐擪�v�f�ւ̃|�C���^
	int	 deleted;			// �폜���X�g�̐擪�v�f�ւ̃|�C���^
	int	 max;				// ���ݓo�^����Ă���m�[�h�̌�

	int GetIndex(void)		// �}�����ׂ��ʒu�̓Y������ԋp
	{
		if (deleted == Null)
			return (++max);
		else {
			int  rec = deleted;
			deleted = ptr[rec].dnext;
			return (rec);
		}
	}

	void DeleteIndex(int idx)	// ���R�[�hidx���폜���X�g�ɓo�^
	{
		if (deleted == Null) {
			deleted = idx;
			ptr[idx].dnext = Null;
		} else {
			int  p = deleted;
			deleted = idx;
			ptr[idx].dnext = p;
		}
	}
	
public:

	enum { Null = -1 };					// �k���|�C���^
	FixedList(int sz)					// �R���X�g���N�^
	{
		ptr = new FixedNode<Type>[size = sz];
		top = deleted = max = Null;
	}

	~FixedList(void) { Clear(); delete[] ptr; }	// �f�X�g���N�^
	int Top(void)    { return (top); }

	void InsertNode(Type data)			// �擪�Ƀm�[�h��}��
	{
		int  p = top;
		top = GetIndex();
		ptr[top].next = p;
        ptr[top].data = data;
	}

	void AppendNode(Type data)			// �����Ƀm�[�h��ǉ�
	{
		if (top == Null)
			InsertNode(data);
		else {
			int  p = top;
			while (ptr[p].next != Null)
				p = ptr[p].next;
			p = ptr[p].next = GetIndex();
			ptr[p].next = Null;
			ptr[p].data = data;
		}
	}

	void DeleteNode(void)				// �擪�m�[�h�̍폜
	{
		if (top != Null) {
			int  p = ptr[top].next;
			DeleteIndex(top);
			top = p;
		}
	}

	void Clear(void)					// �S�Ẵm�[�h���폜
	{
		while (top != Null)
			DeleteNode();
	}

	FixedNode<Type>& operator[](int i)	// �Y�������Z�q
	{
		return (ptr[i]);
	}
};


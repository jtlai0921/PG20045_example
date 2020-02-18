//----------------------------------------------------------------------------//
//	�L���[�N���X�e���v���[�g								"queue.h"         //
//----------------------------------------------------------------------------//


//===== �L���[�N���X�e���v���[�g =====//
template <class Type> class Queue {

private:
	int		size;				// �z��̑傫��
	int		no;					// ���݂̗v�f��
	Type*	ptr;				// �L���[�{�̂ւ̃|�C���^
	Type*	front;				// �擪�v�f
	Type*	rear;				// �����v�f

	Queue(const Queue&);			// �R�s�[�R���X�g���N�^�𖳌���
	Queue& operator=(const Queue&);	// ������Z�q�𖳌���

public:
	//----- ��L���[����̎��o���ɑ΂����O -----//
	class EmptyErr {
	private:
		Queue*	ident;
	public:
		EmptyErr(Queue* p) : ident(p) { }
		Queue* Ptr(void)  { return (ident); }
	};

	Queue(int sz) {
		front = rear = ptr = new Type[size = sz];
		no = 0;
	}

	~Queue(void)		{ delete[] ptr; }

	int Add(const Type &x) {	// �f�[�^�̒ǉ�
		if (no >= size)
			return (0);
		no++;
		*rear++ = x;
		if (rear >= ptr + size) rear = ptr;
		return (1);
	}

	Type Remove(void) {			// �f�[�^�̎�肾��
		if (no <= 0)
			throw EmptyErr(this);		// �G���[���o
		no--;
		Type temp = *front++;
		if (front >= ptr + size) front = ptr;
		return (temp);
	}

	friend ostream& operator<<(ostream&, Queue<Type>&);
};

//----- �o�� -----//
template <class Type>
ostream& operator<<(ostream& os, Queue<Type>& x)
{
	os << "{ ";
	if (x.no > 0) {
		Type* ptr;
		int   j = 0;

		for (ptr = x.front; ptr < x.ptr+x.size; ptr++) {
			if (++j > x.no) break;
			cout << *ptr << ' ';
		}
		for (ptr = x.ptr; ptr < x.ptr+x.size; ptr++) {
			if (++j > x.no) break;
			cout << *ptr << ' ';
		}
	}
	os << "}\n";
	return (os);
}


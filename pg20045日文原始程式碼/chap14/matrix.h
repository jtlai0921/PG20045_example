//----------------------------------------------------------------------------//
//	�s��N���X Matrix �i�C���^�t�F�[�X���j						"matrix.h"    //
//----------------------------------------------------------------------------//


//===== �s��N���X =====//
class Matrix {

private:
	int		width;			// �s��
	int		height;			// ��
	int		*ptr;			// �s��{�̂��i�[����z��ւ̃|�C���^

public:
	Matrix(int, int);			// �R���X�g���N�^�i��s��ƂȂ�j
	Matrix(const Matrix&);		// �R�s�[�R���X�g���N�^
	~Matrix(void);				// �f�X�g���N�^

	void	Print(int w = 0) const;				// ��ʕ\��

	// a�s�̐擪�v�f�ւ̃|�C���^��ԋp���� ( Matrix[int] ) �Y�������Z�q
	// �@�@���ӁF (a < height)�ł���Ƃ��̂ݓ��삪�ۏ؂����
		  int* operator[](int a)	   { return (ptr + a * width); }
	const int* operator[](int a) const { return (ptr + a * width); }

	Matrix operator+(void) { return (*this); }	// �P�� + ���Z�q
	Matrix operator-(void);						// �P�� - ���Z�q

	Matrix& operator=( const Matrix&);			// = ���Z�q
	Matrix& operator+=(const Matrix&);			// += ���Z�q
	Matrix& operator-=(const Matrix&);			// -= ���Z�q
	Matrix& operator*=(const Matrix&);			// *= ���Z�q

	friend Matrix operator+(const Matrix&, const Matrix&);	// �Q�� + ���Z�q
	friend Matrix operator-(const Matrix&, const Matrix&);	// �Q�� - ���Z�q 
	friend Matrix operator*(const Matrix&, const Matrix&);	// �Q�� * ���Z�q

	friend int operator==(const Matrix&, const Matrix&);	// == ���Z�q
	friend int operator!=(const Matrix&, const Matrix&);	// != ���Z�q

	// �s��mat�Ƒ傫���i�s���E�񐔁j�͓��������H
	int EqSize(const Matrix& mat) const {
		return (width == mat.width  &&  height == mat.height);
	}
};


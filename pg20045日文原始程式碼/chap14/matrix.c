//-------------------------------------------------------------	//
//	�s��N���X Matrix �i�������j					"matrix.c"  //
//-------------------------------------------------------------	//

#include	<iomanip.h>
#include	<iostream.h>

#include	"matrix.h"

//--- �R���X�g���N�^�i��s��ƂȂ�j ---//
Matrix::Matrix(int w, int h) : width(w), height(h)
{
	ptr = new int[height * width];
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			(*this)[i][j] = 0;
	}
}

//--- �R�s�[�R���X�g���N�^ ---//
Matrix::Matrix(const Matrix& mat)
						 : width(mat.width), height(mat.height)
{
	ptr = new int[height * width];
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			(*this)[i][j] = mat[i][j];
	}
}

//--- �f�X�g���N�^ ---//
Matrix::~Matrix(void)
{
	delete[] ptr;
}

//--- �s��~(-1)�����߂� ( - Matrix ) ---//
Matrix Matrix::operator-(void)
{
	Matrix temp(width, height);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			temp[i][j] = (*this)[i][j];

	return (temp);
}

//--- �s���mat�������� ( Matrix = Matrix ) ---//
Matrix& Matrix::operator=(const Matrix& mat)
{
	if (&mat != this && EqSize(mat)) {
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				(*this)[i][j] = mat[i][j];
	}

	return (*this);
}

//--- �s���mat�������� ( Matrix += Matrix ) ---//
Matrix& Matrix::operator+=(const Matrix& mat)
{
	if (EqSize(mat)) {
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				(*this)[i][j] += mat[i][j];
	}
	return (*this);
}

//--- �s�񂩂�mat������ ( Matrix -= Matrix ) ---//
Matrix& Matrix::operator-=(const Matrix& mat)
{
	if (EqSize(mat)) {
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				(*this)[i][j] -= mat[i][j];
	}
	return (*this);
}

//--- �s���mat�������� ( Matrix *= Matrix ) ---//
Matrix& Matrix::operator*=(const Matrix& mat)
{
	if (width == mat.height  &&  height == mat.width) {
		Matrix temp(height, mat.width);
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				for (int k = 0 ; k < height; k++)
					temp[i][j] += (*this)[i][k] * mat[k][j];
		*this = temp;
	}
	return (*this);
}

//--- �s��mt1��mt2�̘a�����߂� ( Matrix + Matrix ) ---//
Matrix operator+(const Matrix& mt1, const Matrix& mt2)
{
	Matrix temp(mt1);
	return (temp + mt2);
}

//--- �s��mt1����mt2���������l�����߂� ( Matrix - Matrix ) ---//
Matrix operator-(const Matrix& mt1, const Matrix& mt2)
{
	Matrix temp(mt1);
	return (temp -= mt2);
}

//--- �s��mt1��mt2�̐ς����߂� ( Matrix * Matrix ) ---//
Matrix operator*(const Matrix& mt1, const Matrix& mt2)
{
	Matrix temp(mt1);
	return (temp *= mt2);
}

//--- �s��mt1��mt2�͓������� ( Matrix == Matrix ) ---//
int operator==(const Matrix& mt1, const Matrix& mt2)
{
	if (!mt1.EqSize(mt2)) return (0);	// ���������傫�����Ⴄ
	for (int i = 0; i < mt1.height; i++)
		for (int j = 0; j < mt1.width; j++)
			if (mt1[i][j] != mt2[i][j])	// �P�v�f�ł��Ⴆ�΁c
				return (0);
	return (1);
}

//--- �s��mt1��mt2�͓������Ȃ��� ( Matrix != Matrix ) ---//
int operator!=(const Matrix& mt1, const Matrix& mt2)
{
	return ( !(mt1 == mt2) );
}

//--- ��ʕ\���i���͊e�����̕��j ---//
void Matrix::Print(int w) const
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			cout << setw(w) << (*this)[i][j];
		cout << '\n';
	}
}


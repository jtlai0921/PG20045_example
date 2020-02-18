//-------------------------------------------------------------	//
//	行列クラス Matrix （実現部）					"matrix.c"  //
//-------------------------------------------------------------	//

#include	<iomanip.h>
#include	<iostream.h>

#include	"matrix.h"

//--- コンストラクタ（零行列となる） ---//
Matrix::Matrix(int w, int h) : width(w), height(h)
{
	ptr = new int[height * width];
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			(*this)[i][j] = 0;
	}
}

//--- コピーコンストラクタ ---//
Matrix::Matrix(const Matrix& mat)
						 : width(mat.width), height(mat.height)
{
	ptr = new int[height * width];
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			(*this)[i][j] = mat[i][j];
	}
}

//--- デストラクタ ---//
Matrix::~Matrix(void)
{
	delete[] ptr;
}

//--- 行列×(-1)を求める ( - Matrix ) ---//
Matrix Matrix::operator-(void)
{
	Matrix temp(width, height);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			temp[i][j] = (*this)[i][j];

	return (temp);
}

//--- 行列にmatを代入する ( Matrix = Matrix ) ---//
Matrix& Matrix::operator=(const Matrix& mat)
{
	if (&mat != this && EqSize(mat)) {
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				(*this)[i][j] = mat[i][j];
	}

	return (*this);
}

//--- 行列にmatを加える ( Matrix += Matrix ) ---//
Matrix& Matrix::operator+=(const Matrix& mat)
{
	if (EqSize(mat)) {
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				(*this)[i][j] += mat[i][j];
	}
	return (*this);
}

//--- 行列からmatを引く ( Matrix -= Matrix ) ---//
Matrix& Matrix::operator-=(const Matrix& mat)
{
	if (EqSize(mat)) {
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				(*this)[i][j] -= mat[i][j];
	}
	return (*this);
}

//--- 行列にmatをかける ( Matrix *= Matrix ) ---//
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

//--- 行列mt1とmt2の和を求める ( Matrix + Matrix ) ---//
Matrix operator+(const Matrix& mt1, const Matrix& mt2)
{
	Matrix temp(mt1);
	return (temp + mt2);
}

//--- 行列mt1からmt2を引いた値を求める ( Matrix - Matrix ) ---//
Matrix operator-(const Matrix& mt1, const Matrix& mt2)
{
	Matrix temp(mt1);
	return (temp -= mt2);
}

//--- 行列mt1とmt2の積を求める ( Matrix * Matrix ) ---//
Matrix operator*(const Matrix& mt1, const Matrix& mt2)
{
	Matrix temp(mt1);
	return (temp *= mt2);
}

//--- 行列mt1とmt2は等しいか ( Matrix == Matrix ) ---//
int operator==(const Matrix& mt1, const Matrix& mt2)
{
	if (!mt1.EqSize(mt2)) return (0);	// そもそも大きさが違う
	for (int i = 0; i < mt1.height; i++)
		for (int j = 0; j < mt1.width; j++)
			if (mt1[i][j] != mt2[i][j])	// １要素でも違えば…
				return (0);
	return (1);
}

//--- 行列mt1とmt2は等しくないか ( Matrix != Matrix ) ---//
int operator!=(const Matrix& mt1, const Matrix& mt2)
{
	return ( !(mt1 == mt2) );
}

//--- 画面表示（ｗは各数字の幅） ---//
void Matrix::Print(int w) const
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			cout << setw(w) << (*this)[i][j];
		cout << '\n';
	}
}


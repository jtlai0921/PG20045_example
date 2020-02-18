//----------------------------------------------------------------------------//
//	行列クラス Matrix （インタフェース部）						"matrix.h"    //
//----------------------------------------------------------------------------//


//===== 行列クラス =====//
class Matrix {

private:
	int		width;			// 行数
	int		height;			// 列数
	int		*ptr;			// 行列本体を格納する配列へのポインタ

public:
	Matrix(int, int);			// コンストラクタ（零行列となる）
	Matrix(const Matrix&);		// コピーコンストラクタ
	~Matrix(void);				// デストラクタ

	void	Print(int w = 0) const;				// 画面表示

	// a行の先頭要素へのポインタを返却する ( Matrix[int] ) 添え字演算子
	// 　　注意： (a < height)であるときのみ動作が保証される
		  int* operator[](int a)	   { return (ptr + a * width); }
	const int* operator[](int a) const { return (ptr + a * width); }

	Matrix operator+(void) { return (*this); }	// 単項 + 演算子
	Matrix operator-(void);						// 単項 - 演算子

	Matrix& operator=( const Matrix&);			// = 演算子
	Matrix& operator+=(const Matrix&);			// += 演算子
	Matrix& operator-=(const Matrix&);			// -= 演算子
	Matrix& operator*=(const Matrix&);			// *= 演算子

	friend Matrix operator+(const Matrix&, const Matrix&);	// ２項 + 演算子
	friend Matrix operator-(const Matrix&, const Matrix&);	// ２項 - 演算子 
	friend Matrix operator*(const Matrix&, const Matrix&);	// ２項 * 演算子

	friend int operator==(const Matrix&, const Matrix&);	// == 演算子
	friend int operator!=(const Matrix&, const Matrix&);	// != 演算子

	// 行列matと大きさ（行数・列数）は等しいか？
	int EqSize(const Matrix& mat) const {
		return (width == mat.width  &&  height == mat.height);
	}
};


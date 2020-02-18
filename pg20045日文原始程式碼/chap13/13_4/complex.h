//------------------------------------------------------------------------//
//	複素数クラス Complex （インタフェース部）		"complex.h"   //
//-----------------------------------------------------------------------//


#include	<iostream.h>

class Complex {

private:
	double  re;			// 実部
	double  im;			// 虚部

public:
	Complex(double r = 0, double i = 0) { re = r; im = i; }		//コンストラクタ
	friend double Real(const Complex& x) { return (x.re); }		// 実部を返却
	friend double Imag(const Complex& x) { return (x.im); }		// 虚部を返却

	Complex operator+(void) { return (*this); }					// 単項＋演算子
	Complex operator-(void) { return (Complex(-re, -im)); }		// 単項－演算子

	Complex& operator+=(const Complex& x) {							// ＋＝演算子
		re += x.re;
		im += x.im;
		return (*this);
	}

	Complex& operator-=(const Complex& x) {							// －＝演算子
		re -= x.re;
		im -= x.im;
		return (*this);
	}

	friend Complex operator+(const Complex& x, const Complex& y) {
		return (Complex(x.re + y.re,  x.im + y.im));
	}

	friend Complex operator+(const double x, const Complex& y) {
		return (Complex(x + y.re, y.im));
	}

	friend Complex operator+(const Complex& x, const double y) {
		return (Complex(x.re + y, x.im));
	}

	friend Complex operator-(const Complex& x, const Complex& y) {
		return (Complex(x.re - y.re,  x.im - y.im));
	}

	friend Complex operator-(const double x, const Complex& y) {
		return (Complex(x - y.re, - y.im));
	}

	friend Complex operator-(const Complex& x, const double y) {
		return (Complex(x.re - y, x.im));
	}

	friend int operator==(const Complex& x, const Complex& y) {
		return (x.re == y.re && x.im == y.im);
	}

	friend int operator!=(const Complex& x, const Complex& y) {
		return (!(x == y));
	}
};

inline ostream& operator<<(ostream& s, const Complex& x)
{
	return (s << '(' << Real(x) << ',' << Imag(x) << ')');
}

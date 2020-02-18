//------------------------------------------------------------------------//
//	���f���N���X Complex �i�C���^�t�F�[�X���j		"complex.h"   //
//-----------------------------------------------------------------------//


#include	<iostream.h>

class Complex {

private:
	double  re;			// ����
	double  im;			// ����

public:
	Complex(double r = 0, double i = 0) { re = r; im = i; }		//�R���X�g���N�^
	friend double Real(const Complex& x) { return (x.re); }		// ������ԋp
	friend double Imag(const Complex& x) { return (x.im); }		// ������ԋp

	Complex operator+(void) { return (*this); }					// �P���{���Z�q
	Complex operator-(void) { return (Complex(-re, -im)); }		// �P���|���Z�q

	Complex& operator+=(const Complex& x) {							// �{�����Z�q
		re += x.re;
		im += x.im;
		return (*this);
	}

	Complex& operator-=(const Complex& x) {							// �|�����Z�q
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

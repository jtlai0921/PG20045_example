#include	<iostream.h>

class A {
public:
	char	ch;
	A(char a) { cout << "A::chを" << (ch = a) << "で初期化\n"; }
};

class B {
public:
	char	ch;
	B(char b) { cout << "B::chを" << (ch = b) << "で初期化\n"; }
};

class X : A, B {
public:
	char	ch;
	void Say(void) { cout << "X::chを" << ch << "で初期化\n"; }
	X(char x) : A('X'), B('X') { ch = x; Say(); }
};

class Y : B, A {
public:
	char	ch;
	void Say(void) { cout << "Y::chを" << ch << "で初期化\n"; }
	Y(char y) : B('Y'), A('Y') { ch = y; Say(); }
};

class Z : X, Y {
public:
	char	ch;
	void Say(void) { cout << "Z::chを" << ch << "で初期化\n"; }
	Z(char z) : X('Z'), Y('Z') { ch = z; Say(); }
};

int main(void)
{
	Z a('S');

	return (0);
}

/*
実行結果
A::chをXで初期化
B::chをXで初期化
X::chをZで初期化
B::chをYで初期化
A::chをYで初期化
Y::chをZで初期化
Z::chをSで初期化
*/
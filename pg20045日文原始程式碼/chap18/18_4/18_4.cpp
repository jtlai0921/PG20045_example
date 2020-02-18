#include	<iostream.h>

class A {
public:
	char	ch;
	A(char a) { cout << "A::ch��" << (ch = a) << "�ŏ�����\n"; }
};

class B {
public:
	char	ch;
	B(char b) { cout << "B::ch��" << (ch = b) << "�ŏ�����\n"; }
};

class X : A, B {
public:
	char	ch;
	void Say(void) { cout << "X::ch��" << ch << "�ŏ�����\n"; }
	X(char x) : A('X'), B('X') { ch = x; Say(); }
};

class Y : B, A {
public:
	char	ch;
	void Say(void) { cout << "Y::ch��" << ch << "�ŏ�����\n"; }
	Y(char y) : B('Y'), A('Y') { ch = y; Say(); }
};

class Z : X, Y {
public:
	char	ch;
	void Say(void) { cout << "Z::ch��" << ch << "�ŏ�����\n"; }
	Z(char z) : X('Z'), Y('Z') { ch = z; Say(); }
};

int main(void)
{
	Z a('S');

	return (0);
}

/*
���s����
A::ch��X�ŏ�����
B::ch��X�ŏ�����
X::ch��Z�ŏ�����
B::ch��Y�ŏ�����
A::ch��Y�ŏ�����
Y::ch��Z�ŏ�����
Z::ch��S�ŏ�����
*/
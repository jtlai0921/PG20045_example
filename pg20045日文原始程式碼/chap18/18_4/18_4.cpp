#include	<iostream.h>

class A {
public:
	char	ch;
	A(char a) { cout << "A::ch‚ð" << (ch = a) << "‚Å‰Šú‰»\n"; }
};

class B {
public:
	char	ch;
	B(char b) { cout << "B::ch‚ð" << (ch = b) << "‚Å‰Šú‰»\n"; }
};

class X : A, B {
public:
	char	ch;
	void Say(void) { cout << "X::ch‚ð" << ch << "‚Å‰Šú‰»\n"; }
	X(char x) : A('X'), B('X') { ch = x; Say(); }
};

class Y : B, A {
public:
	char	ch;
	void Say(void) { cout << "Y::ch‚ð" << ch << "‚Å‰Šú‰»\n"; }
	Y(char y) : B('Y'), A('Y') { ch = y; Say(); }
};

class Z : X, Y {
public:
	char	ch;
	void Say(void) { cout << "Z::ch‚ð" << ch << "‚Å‰Šú‰»\n"; }
	Z(char z) : X('Z'), Y('Z') { ch = z; Say(); }
};

int main(void)
{
	Z a('S');

	return (0);
}

/*
ŽÀsŒ‹‰Ê
A::ch‚ðX‚Å‰Šú‰»
B::ch‚ðX‚Å‰Šú‰»
X::ch‚ðZ‚Å‰Šú‰»
B::ch‚ðY‚Å‰Šú‰»
A::ch‚ðY‚Å‰Šú‰»
Y::ch‚ðZ‚Å‰Šú‰»
Z::ch‚ðS‚Å‰Šú‰»
*/
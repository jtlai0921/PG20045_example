//----------------------------------------------------------------------------//
//	�_���N���X Boolean										"boolean.h"       //
//----------------------------------------------------------------------------//


class Boolean {

public:
	enum bool {False, True};

private:
	bool	x;

public:
	Boolean(void)		{ x = False; }
	Boolean(int val)	{ x = bool(val != 0); }

	operator int(void)	{ return (x); }				// �ϊ��֐� int(op)

	int operator!(void)	{ return (x == False); }	// �ے艉�Z�q !op

	char* String(void)	{ return (x == False ? "False" : "True"); }
};

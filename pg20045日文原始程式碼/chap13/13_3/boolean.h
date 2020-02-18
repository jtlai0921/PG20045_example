//----------------------------------------------------------------------------//
//	論理クラス Boolean										"boolean.h"       //
//----------------------------------------------------------------------------//


class Boolean {

public:
	enum bool {False, True};

private:
	bool	x;

public:
	Boolean(void)		{ x = False; }
	Boolean(int val)	{ x = bool(val != 0); }

	operator int(void)	{ return (x); }				// 変換関数 int(op)

	int operator!(void)	{ return (x == False); }	// 否定演算子 !op

	char* String(void)	{ return (x == False ? "False" : "True"); }
};

#include  <iostream.h>

//--- ‚˜‚Ö‚ÌQÆ‚ğ•Ô‹p‚·‚éŠÖ” ---//
int& ref(void)
{
	static int  x = 3;

	return (x);
}

int main(void)
{
	ref() = 5;		// ref()‚Ö’l‚ğ‘ã“ü

	cout << "ref() = " << ref() << '\n';

	return (0);
}

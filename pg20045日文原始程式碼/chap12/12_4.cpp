/*
	âsûÀNX Kouza@| pá |
*/

#include	<iostream.h>

#include	"kouza.h"

int main(void)
{
	Kouza	Nozawa(1234569,  0, 1991, 1, 1);
	Kouza	Miyata(3468924, 10, 1992, 2, 2);

	Nozawa.Ireru(100);		// ìòNª100~a¯é

	Miyata.Orosu(5);			// {cNª5~ø«o·

	cout << "ìòNÌûÀ\n";
	cout << "ûÀÔ" << Nozawa.KouzaNo()  << '\n';
	cout << "a à z" << Nozawa.Yokingaku() << "~\n";
	cout << "J Ý ú" << Nozawa.Kaisetsubi() << '\n';

	cout << "{cNÌûÀ\n";
	cout << "ûÀÔ" << Miyata.KouzaNo()  << '\n';
	cout << "a à z" << Miyata.Yokingaku() << "~\n";
	cout << "J Ý ú" << Miyata.Kaisetsubi() << '\n';

	return (0);
}

/*
ÀsÊ
ìòNÌûÀ
ûÀÔ1234569
a à z100~
J Ý ú1991N11ú
{cNÌûÀ
ûÀÔ3468924
a à z5~
J Ý ú1992N22ú
*/

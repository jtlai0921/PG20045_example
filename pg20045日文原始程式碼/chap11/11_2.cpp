/*
	âsûÀNX kouza@| pá |
*/

#include	<iostream.h>

#include	"kouza.h"

int main(void)
{
	kouza	nozawa(1234569,  0);		// ìòNÌâsûÀ
	kouza	miyata(3468924, 10);		// {cNÌâsûÀ

	nozawa.ireru(100);				// ìòNª100~a¯é

	miyata.orosu(5);					// {cNª5~ø«o·

	cout << "ìòNÌûÀ\n";
	cout << "ûÀÔ" << nozawa.kouza_no()  << '\n';
	cout << "a à z" << nozawa.yokingaku() << "~\n\n";

	cout << "{cNÌûÀ\n";
	cout << "ûÀÔ" << miyata.kouza_no()  << '\n';
	cout << "a à z" << miyata.yokingaku() << "~\n";

	return (0);
}

/*
ÀsÊ
ìòNÌûÀ
ûÀÔ1234569
a à z100~
{cNÌûÀ
ûÀÔ3468924
a à z5~
*/

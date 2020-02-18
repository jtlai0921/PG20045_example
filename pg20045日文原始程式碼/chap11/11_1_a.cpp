#include	<iostream.h>

//===== ‹âsŒûÀƒNƒ‰ƒX =====//
class kouza {

public:					//===== ŒöŠJ•” =====//
	long  number;			// ŒûÀ”Ô†
	long  yokin;			// —a‹àŠz
};

int main(void)
{
	kouza  nozawa = {1234569, 0};		// –ì‘òŒN‚Ì‹âsŒûÀ

	kouza  miyata;						// ‹{“cŒN‚Ì‹âsŒûÀ
	miyata.number = 3468924;
	miyata.yokin  = 10;

	nozawa.yokin += 100;					// –ì‘òŒN‚ª100‰~—a‚¯‚é

	miyata.yokin -= 5;					// ‹{“cŒN‚ª5‰~ˆø‚«o‚·

	cout << "–ì‘òŒN‚ÌŒûÀ\n";
	cout << "ŒûÀ”Ô†" << nozawa.number << '\n';
	cout << "—a ‹à Šz" << nozawa.yokin  << "‰~\n\n";

	cout << "‹{“cŒN‚ÌŒûÀ\n";
	cout << "ŒûÀ”Ô†" << miyata.number << '\n';
	cout << "—a ‹à Šz" << miyata.yokin  << "‰~\n";

	return (0);
}

/*
ÀsŒ‹‰Ê
–ì‘òŒN‚ÌŒûÀ
ŒûÀ”Ô†1234569
—a ‹à Šz100‰~
‹{“cŒN‚ÌŒûÀ
ŒûÀ”Ô†3468924
—a ‹à Šz5‰~
*/

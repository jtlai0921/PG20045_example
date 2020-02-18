#include	<iostream.h>

//===== ‹âsŒûÀƒNƒ‰ƒX =====//
class kouza {
private:							//===== „“I•” =====// 
	long    number;						// ŒûÀ”Ô†
	long    yokin;						// —a‹àŠz

public:								//===== ŒöŠJ•” =====//
	kouza(long no, long yok) {			// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
		number = no;
		yokin = yok;
	}
	void ireru(long okane) { yokin += okane; }		// ‚¨‹à‚ğ—a‚¯‚é
	void orosu(long okane) { yokin -= okane; }		// ‚¨‹à‚ğˆø‚«o‚·
	long kouza_no(void)    { return (number); }		// ŒûÀ”Ô†
	long yokingaku(void)   { return (yokin); }		// —a‹àŠz
};

int main(void)
{
	kouza  nozawa(1234569,  0);	// –ì‘òŒN‚Ì‹âsŒûÀ
	kouza  miyata(3468924, 10);	// ‹{“cŒN‚Ì‹âsŒûÀ

	nozawa.ireru(100);				// –ì‘òŒN‚ª100‰~—a‚¯‚é
	miyata.orosu(5);					// ‹{“cŒN‚ª5‰~ˆø‚«o‚·

	cout << "–ì‘òŒN‚ÌŒûÀ\n";
	cout << "ŒûÀ”Ô†" << nozawa.kouza_no()  << '\n';
	cout << "—a ‹à Šz" << nozawa.yokingaku() << "‰~\n\n";

	cout << "‹{“cŒN‚ÌŒûÀ\n";
	cout << "ŒûÀ”Ô†" << miyata.kouza_no()  << '\n';
	cout << "—a ‹à Šz" << miyata.yokingaku() << "‰~\n";

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

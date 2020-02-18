#include	<iostream.h>

typedef enum {
	Termination, Dog, Cat, Mokey, Invalid
} menu;

typedef void (*mfunc)(void);

//--- Œ¢‚Ì–Â‚«º ---//
void dog(void)
{
	cout << "ƒƒ“!!ƒƒ“!!\n";    
}

//--- ”L‚Ì–Â‚«º ---//
void cat(void)
{
	cout << "ƒjƒƒƒ“!!ƒjƒƒƒ“!!\n";
}

//--- ‰‚Ì–Â‚«º ---//
void monkey(void)
{
	cout << "ƒLƒbƒLƒb!!\n";
}

//--- ƒƒjƒ…[‘I‘ğ ---//
menu SelectMenu(void)
{
	int		ch;

	do {
		cout << "(‚O) I@‚í@‚è\n";
		cout << "(‚P) Œ¢‚Ì–Â‚«º\n";
		cout << "(‚Q) ”L‚Ì–Â‚«º\n";
		cout << "(‚R) ‰‚Ì–Â‚«º\n";
		cin >> ch;
	} while (ch < Termination || ch >= Invalid);
	return (menu(ch));				// intŒ^ch‚Ì’l‚ğmenuŒ^‚ÉƒLƒƒƒXƒg‚µ‚Ä•Ô‹p
}

//--- ƒƒCƒ“ ---//
int main(void)
{
	menu   menu;
	mfunc  panimal[] = { dog, cat, monkey };

	do {
		menu = SelectMenu();
		if (menu > Termination || menu < Invalid)
			panimal[menu - 1]();
	} while (menu != Termination);

	return (0);
}

/*
Às—á
(‚O) I@‚í@‚è
(‚P) Œ¢‚Ì–Â‚«º
(‚Q) ”L‚Ì–Â‚«º
(‚R) ‰‚Ì–Â‚«º
1¥
ƒƒ“!!ƒƒ“!!
(‚O) I@‚í@‚è
(‚P) Œ¢‚Ì–Â‚«º
(‚Q) ”L‚Ì–Â‚«º
(‚R) ‰‚Ì–Â‚«º
2¥
ƒjƒƒƒ“!!ƒjƒƒƒ“!!
(‚O) I@‚í@‚è
(‚P) Œ¢‚Ì–Â‚«º
(‚Q) ”L‚Ì–Â‚«º
(‚R) ‰‚Ì–Â‚«º
3¥
ƒLƒbƒLƒb!!
(‚O) I@‚í@‚è
(‚P) Œ¢‚Ì–Â‚«º
(‚Q) ”L‚Ì–Â‚«º
(‚R) ‰‚Ì–Â‚«º
0¥
*/
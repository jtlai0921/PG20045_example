#include	<iostream.h>

typedef enum {
	Termination, Dog, Cat, Mokey, Invalid
} menu;

typedef void (*mfunc)(void);

//--- ’ΜΒ«Ί ---//
void dog(void)
{
	cout << "!!!!\n";    
}

//--- LΜΒ«Ί ---//
void cat(void)
{
	cout << "j!!j!!\n";
}

//--- ΜΒ«Ί ---//
void monkey(void)
{
	cout << "LbLb!!\n";
}

//--- j[Iπ ---//
menu SelectMenu(void)
{
	int		ch;

	do {
		cout << "(O) I@ν@θ\n";
		cout << "(P) ’ΜΒ«Ί\n";
		cout << "(Q) LΜΒ«Ί\n";
		cout << "(R) ΜΒ«Ί\n";
		cin >> ch;
	} while (ch < Termination || ch >= Invalid);
	return (menu(ch));				// int^chΜlπmenu^ΙLXg΅ΔΤp
}

//--- C ---//
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
ΐsα
(O) I@ν@θ
(P) ’ΜΒ«Ί
(Q) LΜΒ«Ί
(R) ΜΒ«Ί
1₯
!!!!
(O) I@ν@θ
(P) ’ΜΒ«Ί
(Q) LΜΒ«Ί
(R) ΜΒ«Ί
2₯
j!!j!!
(O) I@ν@θ
(P) ’ΜΒ«Ί
(Q) LΜΒ«Ί
(R) ΜΒ«Ί
3₯
LbLb!!
(O) I@ν@θ
(P) ’ΜΒ«Ί
(Q) LΜΒ«Ί
(R) ΜΒ«Ί
0₯
*/
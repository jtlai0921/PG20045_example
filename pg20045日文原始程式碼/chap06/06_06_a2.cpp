/*
	ジャンケンゲーム（入出力関係）"io.c"
*/

#include		<iostream.h>

extern int  draw;

static void inp_message(void)
{
	if (!draw)
		cout << "ジャンケンぽん\n";
	else
		cout << "あいこでショ\n";
	cout << "(0)ｸﾞｰ (1)ﾁｮｷ (2)ﾊﾟｰ:";
}

int input(void)     //-- 入力 --//
{
	int kazu;
	do {
		inp_message();
		cin >> kazu;
	} while (kazu < 0 || kazu > 2);
	return (kazu);
}

void display(int comp)
{
	cout << "コンピュータは";
	switch (comp) {
	 case 0: cout << "ｸﾞｰ"; break;
	 case 1: cout << "ﾁｮｷ"; break;
	 case 2: cout << "ﾊﾟｰ"; break;
	}
	cout << "です。\n"; 
}

int cont_game(void)//-- 続行の確認 --//
{
	int cont;
	cout << "もう一度しますか？\n"
		 << "<Yes･･1／No･･0>：";
	cin >> cont;
	return (cont);
}


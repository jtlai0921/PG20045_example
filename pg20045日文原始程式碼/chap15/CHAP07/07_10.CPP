#include	<iostream.h>

enum menu  { Termination, Dog, Cat, Mokey, Invalid };

//--- 犬に鳴かせる ---//
void dog(void)
{
	cout << "ワン!!ワン!!\n";
}

//--- 猫に鳴かせる ---//
void cat(void)
{
	cout << "ニャン!!ニャン!!\n";
}

//--- 猿に鳴かせる ---//
void monkey(void)
{
	cout << "キッキッ!!\n";
}

//--- メニュー選択 ---//
menu SelectMenu(void)
{
	int	 ch;

	do {
		cout << "(０) 終　わ　り\n";
		cout << "(１) 犬の鳴き声\n";
		cout << "(２) 猫の鳴き声\n";
		cout << "(３) 猿の鳴き声\n";
		cin >> ch;
	} while (ch < Termination || ch >= Invalid);
	return (menu(ch));				// int型chの値をmenu型にキャストして返却
}

//--- メイン ---//
int main(void)
{
	menu  menu;

	do {
		switch (menu = SelectMenu()) {
		 case Dog:   dog(); break;			// 追加処理
		 case Cat:   cat(); break;			// 削除処理
		 case Mokey: monkey();  break;		// 表示処理
		}
	} while (menu != Termination);

	return (0);
}

/*
実行例
(０) 終　わ　り
(１) 犬の鳴き声
(２) 猫の鳴き声
(３) 猿の鳴き声
1▼
ワン!!ワン!!
(０) 終　わ　り
(１) 犬の鳴き声
(２) 猫の鳴き声
(３) 猿の鳴き声
2▼
ニャン!!ニャン!!
(０) 終　わ　り
(１) 犬の鳴き声
(２) 猫の鳴き声
(３) 猿の鳴き声
3▼
キッキッ!!
(０) 終　わ　り
(１) 犬の鳴き声
(２) 猫の鳴き声
(３) 猿の鳴き声
0▼
*/

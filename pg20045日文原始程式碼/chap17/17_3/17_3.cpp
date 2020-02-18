/*
	継承版ペット線形リストクラスPetList －利用例－
*/

#include	<iostream.h>

#include	"petlist.h"

enum Menu {
	Terminate, Insert, Append, DspFirst, DspLast, Delete, Remove, Clear,
	Print, Intro, MenuOver
};

//----- データ入力 -----//
Pet* AllocPet(void)
{
	int		kind;
	Pet*	ptr;

	do {
		cout << "種別 【0･･犬, 1･･猫, 2･･猿】 : ";
		cin >> kind;
	} while (kind < 0 || kind > 2);
	switch (kind) {
	 case 0 : ptr = new Pdog();     break;
	 case 1 : ptr = new Pcat();     break;
	 case 2 : ptr = new Pmonkey();  break;
	}
	return (ptr);
}

Menu SelectMenu(void)		//----- メニュー選択 -----//
{
	int		ch;

	do {
		cout << "(1) 先頭に挿入  (2) 末尾に追加  "
		     << "(3) 先頭を表示  (4) 末尾を表示\n";
		cout << "(5) 先頭を削除  (6) 末尾を削除  "
		     << "(7) 全てを削除  (8) 全てを表示\n";
		cout << "(9) リスト順自己紹介  (0) 終了\n";
		cin >> ch;
	} while (ch < Terminate || ch >= MenuOver);
	return (Menu(ch));
}

int main(void)
{
	Menu	menu;
	PetList	list;

	do {
		menu = SelectMenu();
		switch (menu) {
		 PetNode* p;
		 case Insert  :	{	cout << "先頭に挿入するデータを入力せよ\n";
							Pet* x = AllocPet();
							x->Input();
							PetNode* n = new PetNode(x);
							list.Insert(n);
						} break;

		 case Append  :	{	cout << "末尾に追加するデータを入力せよ\n";
							Pet* x = AllocPet();
							x->Input();
							PetNode* n = new PetNode(x);
							list.Append(n);
						} break;

		 case DspFirst: if (p = list.Top())
							((Pet*)*p)->Sintro(); break;

		 case DspLast : if (p = list.Top())
							((Pet*)*p)->Sintro(); break;

		 case Delete  : list.Delete(); break;
		 case Remove  : list.Remove(); break;
		 case Clear   : list.Clear();  break;
		 case Print   : cout << list;  break;
		 case Intro   : list.Introduce(); break;
		}
	} while (menu != Terminate);

	return (0);
}

/*
実行例
(1) 先頭に追加  (2) 末尾に追加  (3) 先頭を表示  (4) 末尾を表示
(5) 先頭を削除  (6) 末尾を削除  (7) 全てを削除  (8) 全てを表示
(9) リスト順自己紹介  (0) 終了
1▼
先頭に挿入するデータを入力せよ
種別 【0･･犬, 1･･猫, 2･･猿】 : 1▼
名前 : Michael▼
(1) 先頭に追加  (2) 末尾に追加  (3) 先頭を表示  (4) 末尾を表示
(5) 先頭を削除  (6) 末尾を削除  (7) 全てを削除  (8) 全てを表示
(9) リスト順自己紹介  (0) 終了
1▼
先頭に挿入するデータを入力せよ
種別 【0･･犬, 1･･猫, 2･･猿】 : 0▼
名前 : Taro▼
種別 : 雑種▼
(1) 先頭に追加  (2) 末尾に追加  (3) 先頭を表示  (4) 末尾を表示
(5) 先頭を削除  (6) 末尾を削除  (7) 全てを削除  (8) 全てを表示
(9) リスト順自己紹介  (0) 終了
2▼
末尾に追加するデータを入力せよ
種別 【0･･犬, 1･･猫, 2･･猿】 : 2▼
名前 : Jiro▼
年齢 : 10▼
(1) 先頭に追加  (2) 末尾に追加  (3) 先頭を表示  (4) 末尾を表示
(5) 先頭を削除  (6) 末尾を削除  (7) 全てを削除  (8) 全てを表示
(9) リスト順自己紹介  (0) 終了
8▼
{
	{ Taro }
	{ Michael }
	{ Jiro }
}
(1) 先頭に追加  (2) 末尾に追加  (3) 先頭を表示  (4) 末尾を表示
(5) 先頭を削除  (6) 末尾を削除  (7) 全てを削除  (8) 全てを表示
(9) リスト順自己紹介  (0) 終了
9▼
<<---------------- 自己紹介 ---------------->>
僕は雑種のTaroだワン!!
僕の名前はMichaelだニャン!!
僕は10歳のJiroだキッ!!
<<------------------------------------------>>
(1) 先頭に追加  (2) 末尾に追加  (3) 先頭を表示  (4) 末尾を表示
(5) 先頭を削除  (6) 末尾を削除  (7) 全てを削除  (8) 全てを表示
(9) リスト順自己紹介  (0) 終了
0▼
*/

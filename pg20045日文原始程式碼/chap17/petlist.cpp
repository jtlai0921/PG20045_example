/*
	ペット線形リストクラスPetList －利用例－
*/

#include	<iostream.h>

#include	"petlist.h"

enum Menu {
	Terminate, Insert, Append, DspFirst, DspLast, Delete, 
    Remove, Clear, Print, Intro, MenuOver
};

Menu SelectMenu(void)							// メニュー選択
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
	return ((Menu)ch);
}

int main(void)
{
	Menu	menu;
	PetList	list;

	do {
		menu = SelectMenu();

		switch (menu) {
		 PetNode* p;
		 case Insert :	{	cout << "先頭に挿入するデータを"
									"入力せよ\n";
							Pet* x = new Pet();
							x->Input();
							PetNode* n = new PetNode(x);
							list.Insert(n);
						} break;

		 case Append :	{	cout << "末尾に追加するデータを"
									"入力せよ\n";
							Pet* x = new Pet();
							x->Input();
							PetNode* n = new PetNode(x);
							list.Append(n);
						} break;

		 case DspFirst:	if (p = list.Top())
							((Pet*)*p)->Sintro(); break;

		 case DspLast :	if (p = list.Bottom())
							((Pet*)*p)->Sintro(); break;

		 case Delete  :	list.Delete(); break;
		 case Remove  :	list.Remove(); break;
		 case Clear   :	list.Clear();  break;
		 case Print   :	cout << list;  break;
		 case Intro   :	list.Introduce(); break;
		}
	} while (menu != Terminate);

	return (0);
}

/*
実行例
(1) 先頭に挿入  (2) 末尾に追加  (3) 先頭を表示  (4) 末尾を表示
(5) 先頭を削除  (6) 末尾を削除  (7) 全てを削除  (8) 全てを表示
(9) リスト順自己紹介  (0) 終了
1▼
先頭に挿入するデータを入力せよ
種別 【0･･犬, 1･･猫, 2･･猿】 : 1▼
名前 : Michael▼
(1) 先頭に挿入  (2) 末尾に追加  (3) 先頭を表示  (4) 末尾を表示
(5) 先頭を削除  (6) 末尾を削除  (7) 全てを削除  (8) 全てを表示
(9) リスト順自己紹介  (0) 終了
1▼
先頭に挿入するデータを入力せよ
種別 【0･･犬, 1･･猫, 2･･猿】 : 0▼
名前 : Taro▼
(1) 先頭に挿入  (2) 末尾に追加  (3) 先頭を表示  (4) 末尾を表示
(5) 先頭を削除  (6) 末尾を削除  (7) 全てを削除  (8) 全てを表示
(9) リスト順自己紹介  (0) 終了
2▼
末尾に追加するデータを入力せよ
種別 【0･･犬, 1･･猫, 2･･猿】 : 2▼
名前 : Jiro▼
(1) 先頭に挿入  (2) 末尾に追加  (3) 先頭を表示  (4) 末尾を表示
(5) 先頭を削除  (6) 末尾を削除  (7) 全てを削除  (8) 全てを表示
(9) リスト順自己紹介  (0) 終了
8▼
{
    { 犬, Taro }
    { 猫, Michael }
    { 猿, Jiro }
}
(1) 先頭に挿入  (2) 末尾に追加  (3) 先頭を表示  (4) 末尾を表示
(5) 先頭を削除  (6) 末尾を削除  (7) 全てを削除  (8) 全てを表示
(9) リスト順自己紹介  (0) 終了
9▼
<<---------------- 自己紹介 ---------------->>
僕は犬で、名前はTaroって言うんだよ!!
僕は猫で、名前はMichaelって言うんだよ!!
僕は猿で、名前はJiroって言うんだよ!!
<<------------------------------------------>>
(1) 先頭に挿入  (2) 末尾に追加  (3) 先頭を表示  (4) 末尾を表示
(5) 先頭を削除  (6) 末尾を削除  (7) 全てを削除  (8) 全てを表示
(9) リスト順自己紹介  (0) 終了
0▼
*/


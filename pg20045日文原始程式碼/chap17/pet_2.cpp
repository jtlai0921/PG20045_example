/*
	継承版ペットクラスPet －利用例－
*/

#include	"pet.h"

int main(void)
{
	const int  max = 10;		// ペットの最大数
	int		i;
	int		no;					// ペットの数
	Pet*	MyPet[max];			// ペットへのポインタの配列
	int		kind;				// 種別

	cout << "ペットは何匹ですか？ ( 1 ･･ " << max << " ) : ";
	do {
		cin >> no;
	} while (no < 1 || no > max);

	for (i = 0; i < no; i++) {					// データ入力
		cout << i + 1 << "匹目のデータを入力せよ\n";
		do {
			cout << "種別 【0･･犬, 1･･猫, 2･･猿】 : ";
			cin >> kind;
		} while (kind < 0 || kind > 2);
		switch (kind) {
		 case 0 : MyPet[i] = new Pdog();     break;
		 case 1 : MyPet[i] = new Pcat();     break;
		 case 2 : MyPet[i] = new Pmonkey();  break;
		}
		MyPet[i]->Input();
	}

	cout << "\n僕のペットの一覧表\n";				// 一覧表
	for (i = 0; i < no; i++)
		cout << *MyPet[i] << '\n';

	cout << "\nみんなに自己紹介をさせます。\n";		// 自己紹介
	for (i = 0; i < no; i++)
		MyPet[i]->Sintro();

	for (i = 0; i < no; i++)
		delete MyPet[i];

	return (0);
}

/*
実行例
ペットは何匹ですか？ ( 1 ･･ 10 ) : 3▼
1匹目のデータを入力せよ
種別 【0･･犬, 1･･猫, 2･･猿】 : 0▼
名前 : Taro▼
種別 : 雑種▼
2匹目のデータを入力せよ
種別 【0･･犬, 1･･猫, 2･･猿】 : 1▼
名前 : Michael▼
3匹目のデータを入力せよ
種別 【0･･犬, 1･･猫, 2･･猿】 : 2▼
名前 : Jiro▼
年齢 : 10▼
僕のペットの一覧表
{ Taro }
{ Michael }
{ Jiro }

みんなに自己紹介をさせます
僕は雑種のTaroだワン!!
僕の名前はMichaelだニャン!!
僕は10歳のJiroだキッ!!
*/

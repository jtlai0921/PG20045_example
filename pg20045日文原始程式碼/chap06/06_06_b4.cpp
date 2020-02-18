/*
	ジャンケンゲーム（メイン部）                          "main.c"
*/

#include	<iostream.h>

#include	"jyanken.h"

int	 draw;							// 引き分けが続いた回数
int	 win;							// 勝った回数
int	 lose;							// 負けた回数

int main(void)
{
	cout << "ジャンケンしましょう\a\n\n";

	do {
		int  hantei;
		draw = 0;
		do {
			int	 comp = kettei();				// コンピュータの手
			int	 user = input();				// 利用者の手

			display(comp);						// 両者の手を表示
			hantei = judge(user);				// 勝敗判定
			if (hantei > 0)
				cout << "あなたの勝ち!!\n";
			else if (hantei < 0)
				cout << "あなたの負け!!\n";
		} while (!hantei);
		cout << win << "勝" << lose << "敗です。\n";
	} while (cont_game());

	return (0);
}

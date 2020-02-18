/*
	ジャンケンゲーム（メイン部）                          "main.c"
*/

#include	<iostream.h>

int	 kettei(void);					// コンピュータの手を決定
int	 judge(int user);				// 勝敗を判定			

int	 input(void);					// 利用者の手を入力
void display(int comp);				// コンピュータの手を表示
int	 cont_game(void);				// 続行の確認

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

/*
実行例
ジャンケンをしましょう。

ジャンケンぽん
(0)ｸﾞｰ (1)ﾁｮｷ (2)ﾊﾟｰ:1▼
コンピュータはﾊﾟｰです。
あなたの勝ち!!
1勝0敗です。
もう一度しますか？
<Yes･･1／No･･0>：1▼
ジャンケンぽん
(0)ｸﾞｰ (1)ﾁｮｷ (2)ﾊﾟｰ:0▼
コンピュータはｸﾞｰです。
あいこでショ
(0)ｸﾞｰ (1)ﾁｮｷ (2)ﾊﾟｰ:0▼
コンピュータはﾊﾟｰです。
あのたの負け!!
1勝1敗です。
もう一度しますか？
<Yes･･1／No･･0>：0▼
*/

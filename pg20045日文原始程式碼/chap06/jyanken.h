/*
	ジャンケンゲーム（ヘッダ部）                          "jyanken.h"
*/

int	 kettei(void);					// コンピュータの手を決定
int	 judge(int user);				// 勝敗を判定			

int	 input(void);					// 利用者の手を入力
void  display(int comp);				// コンピュータの手を表示
int	 cont_game(void);				// 続行の確認　　

extern int	draw;					// 引き分けが続いた回数
extern int	win;					// 勝った回数
extern int	lose;					// 負けた回数


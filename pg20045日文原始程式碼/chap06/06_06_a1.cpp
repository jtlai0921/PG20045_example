/*
	ジャンケンゲーム（判定関係）"kai.c"
*/

#include		<stdlib.h>

static int	pre = 0;	// 前回の手
static int	crn = 0;	// 今回の手

extern int  draw;
extern int  win;
extern int  lose;

//--- コンピュータの手を決定 ---//
int kettei(void)
{
	srand(pre * (win + lose) + draw);
	crn = rand() % 3;
	pre = crn;
	return (crn);
}

//--- 判定 ---//
int judge(int user)
{
	int diff = (user - crn + 3) % 3;

	if (diff == 0) {	// 引き分け
		draw++;
		return (0);
	} else if (diff % 3 == 2) {
		win++;
		return (1);			// 勝ち
	}
	lose++;
	return (-1);			// 負け
}


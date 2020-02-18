#include	<iostream.h>

int main(void)
{
	char  c;
	int	 cnt[10] = {0};	// 配列cntの全要素を0で初期化

	while (cin.get(c)) {
		if (c >= '0' && c <= '9')
			cnt[c - '0']++;      
	}

	for (int i = 0; i < 10; i++)
		cout << i << "の出現回数：" << cnt[i] << '\n';

	return (0);
}

/*
実行例
3.1415926535897▼
Ctrl+Z▼
0の出現回数：0
1の出現回数：2
2の出現回数：1
3の出現回数：2
4の出現回数：1
5の出現回数：3
6の出現回数：1
7の出現回数：1
8の出現回数：1
9の出現回数：2
*/

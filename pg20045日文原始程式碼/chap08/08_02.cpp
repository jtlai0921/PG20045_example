#include	<iostream.h>

//--- 配列aのx以上y以下の要素を順に配列bにコピーする ---//
int int_rcpy(int a[], int b[], int n, int x, int y)
{
	int	 num = 0;
	for (int i = 0; i < n; i++)
		if (b[i] >= x && b[i] <= y)
			a[num++] = b[i];
	return (num);
}

int main(void)
{
	const int	max = 5;
	int		a[max], b[max];
	int		i, x, y;	

	for (i = 0; i < max; i++) {	
		cout << "b[" << i << "] = ";
		cin >> b[i];
	}
	cout << "下限値：";		cin >> x;
	cout << "上限値：";		cin >> y; 

	int	 num = int_rcpy(a, b, max, x, y);

	cout << x << "以上" << y << "以下の要素：\n";
	for (i = 0; i < num; i++)
		cout << i + 1 << "番目：" << a[i] << '\n';

	return (0);
}

/*
実行例
b[0] = 3▼
b[1] = 9▼
b[2] = 5▼
b[3] = 7▼
b[4] = 10▼
下限値：4
上限値：8
4以上8以下の要素：
1番目：5
2番目：7
*/

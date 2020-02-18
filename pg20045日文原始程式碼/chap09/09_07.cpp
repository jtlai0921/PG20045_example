#include	<iostream.h>

typedef int (*func)(int ,int);

//--- b > aであれば1を、そうでなければ0を返却 --//
int int_cmp(int a, int b)
{
	return (a > b);
}

//--- a > bであれば1を、そうでなければ0を返却 --//
int int_rcmp(int a, int b)
{
	return (a < b);
}

//--- 引数aとbの値を交換 ---//
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//--- 要素数nの配列aを関数cmpでの比較を基準にソートする ---//
void sort(int* a, int n, int (*cmp)(int ,int))
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if ((*cmp)(a[i], a[j]))
				swap(a[i], a[j]);
}

int main(void)
{
	char  cont;											// 処理を続行するか

	do {
		int  size;
		cout << "配列の大きさを入力してください：";
		cin >> size;

		int*  a = new int[size];						// 配列を生成

		for (int i = 0; i < size; i++) {				// 各要素の値を読み込む
			cout << "a[" << i << "] = ";
			cin >> a[i];
		}

		do {
			int	 asc;									// 昇順あるいは降順

			cout << "昇順にソート(0) 降順にソート(1)：";
			cin >> asc;

			if (!asc)
				sort(a, size, int_cmp);					// 昇順にソート
			else
				sort(a, size, int_rcmp);				// 降順にソート

			cout << "ソート後：\n";
			for (int i = 0; i < size; i++)
				cout << "a[" << i << "] = " << a[i] << '\n';

			cout << "もう一度ソートしますか？（Ｙ／Ｎ）";
			cin >> cont;
		} while (cont == 'Y' || cont  == 'y');

		delete[] a;										// 配列を消滅

		cout << "配列を変更してやり直しますか？（Ｙ／Ｎ）";
		cin >> cont;
	} while (cont == 'Y' || cont  == 'y');

	return (0);
}

/*
実行例
配列の大きさを入力してください：3▼
a[0] = 4▼
a[1] = 8▼
a[2] = 5▼
もう一度ソートしますか？（Ｙ／Ｎ）y▼
昇順にソート(0)降順にソート(1)：0▼
a[0] = 4
a[1] = 5
a[2] = 8
もう一度ソートしますか？（Ｙ／Ｎ）y▼
昇順にソート(0)降順にソート(1)：1▼
a[0] = 8
a[1] = 5
a[2] = 4
もう一度ソートしますか？（Ｙ／Ｎ）n▼
配列を変更してやり直しますか？（Ｙ／Ｎ）y▼
配列の大きさを入力してください：5▼
a[0] = 5▼
a[1] = 4▼
a[2] = 8▼
a[3] = 6▼
a[4] = 7▼
昇順にソート(0)降順にソート(1)：0▼
a[0] = 4
a[1] = 5
a[2] = 6
a[3] = 7
a[4] = 8
もう一度ソートしますか？（Ｙ／Ｎ）n▼
配列を変更してやり直しますか？（Ｙ／Ｎ）n▼
*/

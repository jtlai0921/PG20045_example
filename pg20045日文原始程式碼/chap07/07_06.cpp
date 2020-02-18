
#include	<iostream.h>

//--- 整数ｘ中の1であるビットの数を返却する ---//
int count_bits(unsigned x)
{
	int	 count = 0;
	while (x != 0) {
		if (x & 1) count++;
		x >>= 1;				// x = x >> 1;
	}
	return (count);
}

//--- int型のビット数を返却する ---//
int int_len(void)
{
	unsigned  x = ~0;
	return (count_bits(x));
}

//--- ｘのビット構成を表示する ---//
void print_bits(unsigned x)
{
	for (int i = int_len() - 1; i >= 0; i--)
		cout << ((x >> i) & 1) ? '1' : '0';
}

int main(void)
{
	unsigned  x;
	char  cont;				// 処理を続行するか

	do {
		cout << "正の整数値を入力してください：";
		cin >> x;

		cout << "その数のビット構成は以下の通りです。\n";
		print_bits(x);
		cout << '\n';

		cout << "処理を続けますか？（Ｙ／Ｎ）";
		cin >> cont;
	} while (cont == 'Y' || cont == 'y');

	return (0);
}

/*
実行結果一例
正の整数値を入力してください：10▼
その数のビット構成は以下の通りです。
0000000000001010
処理を続けますか？（Ｙ／Ｎ）Y▼
正の整数値を入力してください：255▼
その数のビット構成は以下の通りです。
0000000011111111
処理を続けますか？（Ｙ／Ｎ）N▼
*/

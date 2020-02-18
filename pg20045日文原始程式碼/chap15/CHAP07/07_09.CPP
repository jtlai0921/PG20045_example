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

//--- xを左にnビットシフトした値を返却 ---//
inline unsigned left_shift(unsigned x, int n)
{
	return ((x >= int_len()) ? 0 : (x << n));
}

//--- xのposビット目からnビットを1にした値を返却 ---//
unsigned set_n(unsigned x, int pos, int n)
{
	return (x | (~left_shift(~0, n) << (pos - 1)));
}

//--- xのposビット目からnビットを0にした値を返却 ---//
unsigned reset_n(unsigned x, int pos, int n)
{
	return (x & (~(~left_shift(~0, n) << (pos - 1))));
}

//--- xのposビット目からnビットを反転した値を返却 ---//
unsigned inverse_n(unsigned x, int pos, int n)
{
	return (x ^ (~left_shift(~0, n) << (pos - 1)));
}

int main(void)
{
	unsigned	x;
	int			a, b;

	cout << "正の整数値を入力してください：";					cin >> x;
	cout << "操作するビットの開始位置を入力してください：";		cin >> a;
	cout << "操作するビット数を入力してください：";				cin >> b;
	cout << "x                 :"; print_bits(x);				  cout << '\n';
	cout << "set_n(x, a, b)    :"; print_bits(set_n(x, a, b));	  cout << '\n';
	cout << "reset_n(x, a, b)  :"; print_bits(reset_n(x, a, b));  cout << '\n';
	cout << "inverse_n(x, a, b):"; print_bits(inverse_n(x, a, b));cout << '\n';

	return (0);
}

/*
実行結果一例
正の整数値を入力してください：565▼
操作するビットの開始位置を入力してください：4▼
操作するビット数を入力してください：5▼
x               :0000001000110101
set(x, a, b)    :0000001001111101
reset(x, a, b)  :0000001000000101
inverse(x, a, b):0000001001001101
*/

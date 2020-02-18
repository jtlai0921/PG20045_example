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

//--- 右にnビット回転した値を返却する ---//
unsigned rrotate(unsigned x, int n)
{
	int		  bits = int_len();
	unsigned  tmp = x;
	return ((x >>= (n % bits)) | (tmp <<= (bits - (n % bits))));
}

//--- 左にnビット回転した値を返却する ---//
unsigned lrotate(unsigned x, int n)
{
	int		  bits = int_len();
	unsigned	  tmp = x;
	return ((x <<= (n % bits)) | (tmp >>= (bits - (n % bits))));
}

int main(void)
{
	unsigned	x;
	int			n;

	cout << "正の整数値を入力してください：";		cin >> x;
	cout << "何ビット回転しますか：";				cin >> n;

	cout << "ｘ　　：";		print_bits(x);			     cout << '\n';
	cout << "右回転：";		print_bits(rrotate(x, n));   cout << '\n';
	cout << "左回転：";		print_bits(lrotate(x, n));   cout << '\n';

	return (0);
}

/*
実行結果一例
正の整数値を入力してください：565▼
何ビット回転しますか：4▼
ｘ　　：0000001000110101
右回転：0101000000100011
左回転：0010001101010000
*/

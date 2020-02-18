#include	<iostream.h>

//int count_bits(unsigned x)		{ /*--- 省略・問題7-6を参照せよ ---*/ }
//int int_len(void)				{ /*--- 省略・問題7-6を参照せよ ---*/ }
//void print_bits(unsigned x)		{ /*--- 省略・問題7-6を参照せよ ---*/ }

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
inline unsigned Lsft(unsigned x, int n)
{
	return ((n >= int_len()) ? 0 : (x << n));
}

//--- xのposビット目を1にした値を返却 ---//
unsigned set(unsigned x, int pos)
{
	return (x | Lsft(1U, pos - 1));
}

//--- xのposビット目を0にした値を返却 ---//
unsigned reset(unsigned x, int pos)
{
	return (x & (~Lsft(1U, pos - 1)));
}

//--- xのposビット目を反転した値を返却 ---//
unsigned inverse(unsigned x, int pos)
{
	return (x ^ Lsft(1U, pos - 1));
}

int main(void)
{
	unsigned  x;
	int  a;

	cout << "正の整数値ｘを入力してください：";				cin >> x;
	cout << "操作するビット位置ａを入力してください：";		cin >> a;

	cout << "x            :"; print_bits(x)			   ; cout << '\n';
	cout << "set(x, a)    :"; print_bits(set(x, a))	   ; cout << '\n';
	cout << "reset(x, a)  :"; print_bits(reset(x, a))  ; cout << '\n';
	cout << "inverse(x, a):"; print_bits(inverse(x, a)); cout << '\n';

	return (0);
}	

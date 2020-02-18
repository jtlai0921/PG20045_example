#include	<iostream.h>

//--- ２のｎ乗を返却する ---//
int pow2(unsigned n)
{
	int	 beki = 1;
	for (int i = 0; i < n; i++)
		beki *= 2;
	return (beki);
}

int main(void)
{
	unsigned  a, n;

	cout << "整数値ａを入力してください："; 	cin >> a;
	cout << "整数値ｎを入力してください："; 	cin >> n;

	unsigned  l_sht = a << n;
	unsigned  r_sht = a >> n;
	unsigned  m_pow = a * pow2(n);
	unsigned  d_pow = a / pow2(n);
	cout << "ａ × (２の" << n << "乗) は" << m_pow << " です。\n";
	cout << "ａ ÷ (２の" << n << "乗) は" << d_pow << " です。\n";
	cout << "ａ << " << n << " は " << l_sht << " です。\n";
	cout << "ａ >> " << n << " は " << r_sht << " です。\n";

	if (m_pow == l_sht)
		cout << "符号なし整数" << a << "の左" << n << "ビットシフトは、２の"
			 << n << "乗と乗算した値と等しいです。\n";
	if (d_pow == r_sht)
		cout << "符号なし整数" << a << "の右" << n << "ビットシフトは、２の"
			 << n << "乗で除算した値と等しいです。\n";

	return (0);
}

/*
実行例
整数値ａを入力してください：10▼
整数値ｎを入力してください：2▼
ａ × (２の2乗) は 40 です。
ａ ÷ (２の2乗) は 2 です。
ａ << 2 は 40 です。
ａ >> 2 は 2 です。
符号なし整数10の左2ビットシフトは、２の2乗と乗算した値と等しいです。
符号なし整数10の右2ビットシフトは、２の2乗で除算した値と等しいです。
*/

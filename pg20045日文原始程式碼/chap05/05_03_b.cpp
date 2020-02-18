//--- 浮動小数点数ｘのｎ乗を返却する ---//
double power(double x, int n)
{
	double	a = 1.0;

	if (n > 0)						// nが0より大きい場合
		while (n-- > 0) 	a *= x;
	else							// nが0以下の場合
		while (n++ < 0) 	a /= x;

	return (a);
}


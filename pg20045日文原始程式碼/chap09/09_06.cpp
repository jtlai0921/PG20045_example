#include	<iostream.h>

double f(double x)		//--- 関数f ---//
{
	return (x * x);
}

double g(double x)		//--- 関数g ---//
{
	return (x * x * x + 3 * x * x);
}

//--- 台形公式を用いて関数func(x)をx1からx2までn分割で積分する関数 ---//
double daikei(double x1, double x2, int n, double (*func)(double x))
{
	double	s = 0.0;
	double	step = (x2 - x1) / n;
	for (int i = 0; i < n; i++)
		s += ( (*func)(x1 + step*i) + (*func)(x1 + step*(i+1)) ) * step / 2.0;
	return (s);
}

int main(void)
{
	cout << "f(x)を0.0から1.0まで10分割で積分："
		 << daikei(0.0, 1.0, 10, f) << '\n';

	cout << "g(x)を1.0から3.0まで15分割で積分："
		 << daikei(1.0, 3.0, 15, g) << '\n';

	return (0);
}

/*
実行結果
f(x)を0.0から1.0まで10分割で積分：0.335
g(x)を1.0から3.0まで15分割で積分：46.0533
*/

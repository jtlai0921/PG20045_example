#include	<iostream.h>

//--- ｘを２乗した値を返却する ---//
inline double square(double x)
{
	return (x * x);
}

//--- ｘを３乗した値を返却する ---//
inline double cube(double x)
{
	return (x * x * x);
}

int main(void)
{
	double  a;

	cout << "実数値を入力してください：";
	cin >> a;

	cout << a << "の２乗は" << square(a) << "です。\n";
	cout << a << "の３乗は" << cube(a)   << "です。\n";

	return (0);
}

/*
実行例
実数値を入力してください：4.2▼
4の２乗は17.64です。
4の３乗は74.088です。
*/

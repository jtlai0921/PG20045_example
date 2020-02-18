#include	<iostream.h>

int main(void)
{
	int	 a;

	cout << "正の整数値を入力してください：";
	cin >> a;

	for (int i = 1; i <= a; i++) {
		for (int j = 0; j < a - i ; j++)		// 空白を出力
			cout << ' ';
		for (j = 0; j < i * 2 - 1 ; j++)	// '*'を出力
			cout << '*';
		cout << '\n';
	}

	return (0);
}

/*
実行例
正の整数値を入力してください：3▼
    *
   ***
  *****
*/

#include	<iostream.h>
#include	<iomanip.h>

int main(void)
{
	int	 a, base;

	do {														// 基数読み込み
		cout << "何進数での入力ですか（８/10/16）：";
		cin >> dec >> base;
	} while (base != 8 && base != 10 && base != 16);

	cout << "整数値を入力してください：";
	cin >> setbase(base) >> a;								// 整数値入力

	do {														// 基数読み込み
		cout << "何進数で表示しますか（８/10/16）：";
		cin >> dec >> base;
	} while (base != 8 && base != 10 && base != 16);

	cout << setbase(base) << a << '\n';					// 整数値出力

	return (0);
}

/*
実行結果
何進数での入力ですか（８/10/16）：16▼
整数値を入力してください：ff
何進数で表示しますか（８/10/16）：10▼
255
*/

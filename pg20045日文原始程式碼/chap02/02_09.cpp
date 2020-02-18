#include	<iostream.h>

int main(void)
{
	int	 month;

	cout << "月を入力して下さい：";
	cin >> month;

	switch (month) {
	 case  2: cout << month << "月は28日か29日です。\n";
	          break;
	 case  4:
	 case  6:
	 case  9:
	 case 11: cout << month << "月は30日です。\n";
	          break;
	 case  1:
	 case  3:
	 case  5:
	 case  7:
	 case  8:
	 case 10:
	 case 12: cout << month << "月は31日です。\n";
	          break;
	 default: cout << month << "月なんて、ありませんよ。\n";
	          break;	
	}

	return (0);
}

/*
実行例（1）
月を入力してください：5▼
5月は31日です。
実行例（2）
月を入力してください：15▼
15月なんて、ありませんよ。
*/
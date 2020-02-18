#include	<iostream.h>

int main(void)
{
	int	 a, b;
    //int max ,min;
	cout << "整数値ａを入力せよ：";
	cin >> a;

	cout << "整数値ｂを入力せよ：";
	cin >> b;

   int max=a;
   int min=a;

	if (a > b)                                    
        min =b;
	else                                        
        max =b;
		cout << "小さい方の値は" << min << "です。\n"  
		     << "大きい方の値は" << max << "です。\n";
 
    return (0);
}

/*
実行例（1）
整数値ａを入力せよ：7▼
整数値ｂを入力せよ：12▼
小さい方の値は7です。
大きい方の値は12です。
実行例（2）
整数値ａを入力せよ：7▼
整数値ｂを入力せよ：5▼
小さい方の値は5です。
大きい方の値は7です。
*/

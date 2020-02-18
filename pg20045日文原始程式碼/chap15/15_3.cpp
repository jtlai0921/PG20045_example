/*
	キュークラステンプレート　－利用例－
*/

#include	<string.h>
#include	<iostream.h>

#include	"queue.h"

int main(void)
{
	Queue<int>	Q(10);
	int			menu;

	do {
		cout << "(1)追加　(2)取出し　(3)印刷　(0)終了\n";
		cin >> menu;

		switch (menu) {
		 int data;
		 case 1 : cout << "整数を入力せよ : ";
				  cin >> data;	Q.Add(data); break;
		 case 2 : try {
					  cout << Q.Remove() << "を取り出しました。\n";
				  }
				  catch (Queue<int>::EmptyErr x) {
					  cout << "キューは空ですよ!!\n";
				  }
				  break;
		 case 3 : cout << Q; break;
		}
	} while(menu);

	return (0);
}

/*
実行例
(１)追加　(２)取出し(３)印刷　(４)終了
1▼
整数を入力せよ：5▼
(１)追加　(２)取出し(３)印刷　(４)終了
1▼
整数を入力せよ：8▼
(１)追加　(２)取出し(３)印刷　(４)終了
1▼
整数を入力せよ：10▼
(１)追加　(２)取出し(３)印刷　(４)終了
3▼
{ 5 8 10 }
(１)追加　(２)取出し(３)印刷　(４)終了
2▼
5を取り出しました。
(１)追加　(２)取出し(３)印刷　(４)終了
3▼
{ 8 10 }
(１)追加　(２)取出し(３)印刷　(４)終了
1▼
整数を入力せよ：5▼
(１)追加　(２)取出し(３)印刷　(４)終了
3▼
{ 8 10 5 }
(１)追加　(２)取出し(３)印刷　(４)終了
4▼
*/

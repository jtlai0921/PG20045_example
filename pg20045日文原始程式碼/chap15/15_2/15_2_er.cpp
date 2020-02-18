/*
	スタッククラステンプレート Stack　－ 利用例 －
*/

#include	<string.h>
#include	<iostream.h>

#include	"stack.h"

int main(void)
{
	char  x[256];

	cout << "文字列を入力して下さい : ";
	cin >> x;

	Stack<char>	sc(strlen(x));

	for (int i = 0; x[i] != '\0'; i++)
		sc.Push(x[i]);

	try {
		for (int i = 0; i < strlen(x); i++) {
			char c = sc.Pop();
			cout << c;
		}
		cout << '\n';
	}
	catch (Stack<char>::EmptyErr x) {
		cout << "\n空の<char>スタック["  << x.Ptr()
		     << "]からポップしようとしました。\n";
	}

	Stack<char> a(sc);				// コンパイル・エラー

	Stack<char> b(100);
	b = sc;							// コンパイル・エラー

	return (0);
}

/*
実行例
文字列を入力してください　：shibata▼
atabihs
*/

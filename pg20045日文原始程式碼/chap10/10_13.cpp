#include	<string.h>
#include	<iostream.h>

int main(void)
{
	int	 i;
	int	 smax;

	cout << "文字列はいくつありますか：";
	cin >> smax;

	char**  a = new char*[smax];			// charへのポインタの配列を生成
	for (i = 0; i < smax; i++) {
		char  s[1024];
		cout << "a[" << i << "] = ";
		cin >> s;
		a[i] = new char[strlen(s) + 1];		// 文字列の長さの分だけ文字列を生成
		strcpy(a[i], s);						// 文字列をコピー
	}

	cout << "配列の各要素：\n";
	for (i = 0; i < smax; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';

	for (i = 0; i < smax; i++)				// 各要素の指す文字列を消滅
		delete[] a[i];
	delete[] a;								// 配列を消滅

	return (0);
}

/*
実行結果
文字列はいくつありますか：3▼
a[0] = Turbo▼
a[1] = NA▼
a[2] = DOHC▼
配列の各要素：
a[0] = Turbo
a[1] = NA
a[2] = DOHC
*/

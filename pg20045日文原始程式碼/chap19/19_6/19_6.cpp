#include	<iostream.h>
#include	<fstream.h>
#include	<stdlib.h>

//---タブを調整しながらsrcからの入力をdstへ出力 ---//
void entab(istream &src, ostream &dst, int width)
{
	char  ch;
	int   count = 0;
	int   ntab  = 0;
	int   pos   = 1;

	for (; src.get(ch); pos++)
		if (ch == ' ') {
			if (pos % width != 0)
				count++;
			else {
				count = 0;
				ntab++;
			}
		} else {
			for (; ntab > 0; --ntab)
				dst.put('\t');
			if (ch == '\t')
				count = 0;
			else
				for (; count > 0; count--)
					dst.put(' ');
			dst.put(ch);
			if (ch == '\n')
				pos = 0;
			else if (ch == '\t')
				pos += width - (pos - 1) % width - 1;
		}
}

int main(int argc, char* argv[])
{
	/* 前問のmain関数の、関数detabの呼び出しを以下のように書き換えてください。

		detab(cin, cout, width)		→	entab(cin, cout, width)
		detab(input, cout, width) 	→	entab(input, cout, width)
	*/
}


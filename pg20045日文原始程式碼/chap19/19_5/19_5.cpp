#include	<stdlib.h>
#include	<fstream.h>
#include	<iostream.h>

//---タブを調整しながらsrcからの入力をdstへ出力 ---//
void detab(istream &src, ostream &dst, int width)
{
	char  ch;
	int   pos = 1;

	while (src.get(ch)) {
		int num;
		switch (ch) {
		 case '\t':
			 num = width - (pos - 1) % width;
			 while (num > 0) {
				dst.put(' ');
				++pos;
				--num;
			 }
			 break;
		 case '\n':
			 dst.put(ch); pos=1; break;
		 default:
			 dst.put(ch); ++pos; break;
		}
	}
}

int main(int argc, char* argv[])
{
	int  width = 8;

	if (argc < 2)
		detab(cin, cout, width);
	else {
		while (--argc > 0) {
			if (**(++argv) == '-') {
				if (*++(*argv) == 't')
					width = atoi(++*argv);
				else {
					cerr << "パラメータが不正です。\n";
					return (1);
				}
			} else {
				ifstream  input;
				input.open(*argv);
				if (!input) {
					cerr << "ファイル" << *argv <<
							"が正しくオープンできません。\n";
					return (1);
				}
				detab(input, cout, width);	// ストリームinput → 標準出力
				input.close();
			}
		}
	}

	return (0);
}


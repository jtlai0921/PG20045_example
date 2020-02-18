#include	<fstream.h>
#include	<iostream.h>

//----- 入力srcを出力dstへコピー -----//
void copyfile(istream& src, ostream& dst)
{
	char ch;

	while (src.get(ch))
		dst.put(ch);
}

int main(int argc, char* argv[])
{
	if (argc < 2)							// 引数のない場合は
		copyfile(cin, cout);				//    標準入力→標準出力
	else {
		while (--argc > 0) {
			ifstream input;
			input.open(*++argv);
			if (!input) {
				cerr << "ファイル" << *argv <<
						"が正しくオープンできません\n";
				return (1);
			} else {
				copyfile(input, cout);
				input.close();
			}
		}
	}

	return (0);
}


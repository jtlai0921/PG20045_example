#include	<iostream.h>
#include	<fstream.h>
#include	<ctype.h>

int main(int argc , char* argv[])
{
	char  ch;

	while (--argc > 0) {
		ifstream input;
		input.open(*++argv);
		if (!input) {
			cerr << "�t�@�C���𐳂����I�[�v���ł��܂���B\n";
			return (1);
		}
		while (input.get(ch))
			cout << (char)tolower(ch);
		input.close();
	}

	return (0);
}


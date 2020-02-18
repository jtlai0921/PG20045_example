#include	<stdlib.h>
#include	<fstream.h>
#include	<iostream.h>

//---�^�u�𒲐����Ȃ���src����̓��͂�dst�֏o�� ---//
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
					cerr << "�p�����[�^���s���ł��B\n";
					return (1);
				}
			} else {
				ifstream  input;
				input.open(*argv);
				if (!input) {
					cerr << "�t�@�C��" << *argv <<
							"���������I�[�v���ł��܂���B\n";
					return (1);
				}
				detab(input, cout, width);	// �X�g���[��input �� �W���o��
				input.close();
			}
		}
	}

	return (0);
}


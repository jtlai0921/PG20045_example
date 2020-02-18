#include	<iostream.h>
#include	<fstream.h>
#include	<stdlib.h>

//---�^�u�𒲐����Ȃ���src����̓��͂�dst�֏o�� ---//
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
	/* �O���main�֐��́A�֐�detab�̌Ăяo�����ȉ��̂悤�ɏ��������Ă��������B

		detab(cin, cout, width)		��	entab(cin, cout, width)
		detab(input, cout, width) 	��	entab(input, cout, width)
	*/

	int  width = 8;

	if (argc < 2)
		entab(cin, cout, width);
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
				entab(input, cout, width);	// �X�g���[��input �� �W���o��
				input.close();
			}
		}
	}

	return (0);

}


#include	<fstream.h>
#include	<iostream.h>

//----- ����src���o��dst�փR�s�[ -----//
void copyfile(istream& src, ostream& dst)
{
	char ch;

	while (src.get(ch))
		dst.put(ch);
}

int main(int argc, char* argv[])
{
	if (argc < 2)							// �����̂Ȃ��ꍇ��
		copyfile(cin, cout);				//    �W�����́��W���o��
	else {
		while (--argc > 0) {
			ifstream input;
			input.open(*++argv);
			if (!input) {
				cerr << "�t�@�C��" << *argv <<
						"���������I�[�v���ł��܂���\n";
				return (1);
			} else {
				copyfile(input, cout);
				input.close();
			}
		}
	}

	return (0);
}


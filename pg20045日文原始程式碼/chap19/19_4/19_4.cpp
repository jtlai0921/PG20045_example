#include	<iostream.h>
#include	<fstream.h>
#include	<string.h>

//----- ����src���̍Œ��̍s��dst�ɏo�� -----//
void max_len(istream &src, ostream &dst)
{
	const int max = 256;		// �i�[���镶���̍ő�̒���
	int   len = 0;				// �Œ��̕�����̒���
	int   lenmax = 0;
	int   top = 0;
	char  ch;					// �P�������ǂݍ���
	char  strtmp[max];			// �s��max�܂ł��ꎞ�I�Ɋi�[
	char  strmax[max] = "";		// �Œ��s�̕�������i�[

	while (src.get(ch)) {
		if (++len < max) {					// �s������ő�max�܂ł�ۑ�
			strtmp[len - 1] = ch;	strtmp[len] = '\0';
		}
		if (ch == '\n') {					// �s�̏I�[�ɒB������
			len -= 1;
			if (len >= lenmax) {
				lenmax = len;		strcpy(strmax, strtmp);
			}
			len = 0;
		}
	}

	if (len >= lenmax)
		strcpy(strmax, strtmp);
	dst << "\n�Œ��s �F" << strmax << '\n';
}

int main(int argc, char* argv[])
{
	/*
		�O���main�֐����̊֐�copyfile�̌Ăяo�����A
        									�ȉ��̂悤�ɏ��������Ă��������B

			copyfile(cin, cout)		�� maxlen(cin, cout)
			copyfile(input, cout)	�� maxlen(input, cout)

	*/
}


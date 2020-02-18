#include	<iostream.h>
#include	<fstream.h>
#include	<string.h>

//----- 入力src中の最長の行をdstに出力 -----//
void max_len(istream &src, ostream &dst)
{
	const int max = 256;		// 格納する文字の最大の長さ
	int   len = 0;				// 最長の文字列の長さ
	int   lenmax = 0;
	int   top = 0;
	char  ch;					// １文字分読み込む
	char  strtmp[max];			// 行頭maxまでを一時的に格納
	char  strmax[max] = "";		// 最長行の文字列を格納

	while (src.get(ch)) {
		if (++len < max) {					// 行頭から最大maxまでを保存
			strtmp[len - 1] = ch;	strtmp[len] = '\0';
		}
		if (ch == '\n') {					// 行の終端に達したか
			len -= 1;
			if (len >= lenmax) {
				lenmax = len;		strcpy(strmax, strtmp);
			}
			len = 0;
		}
	}

	if (len >= lenmax)
		strcpy(strmax, strtmp);
	dst << "\n最長行 ：" << strmax << '\n';
}

int main(int argc, char* argv[])
{
	/*
		前問のmain関数中の関数copyfileの呼び出しを、
        									以下のように書き換えてください。

			copyfile(cin, cout)		→ maxlen(cin, cout)
			copyfile(input, cout)	→ maxlen(input, cout)

	*/
}


#include	<iostream.h>
#include	<iomanip.h>
#include	<fstream.h>
#include	<ctype.h>

//--- srcからbufにnumバイト読み込む ---//
size_t read_num(istream& src, unsigned char* buf, size_t num)
{
	size_t read = 0;
	while (src && num--) {
		src.read(buf++, 1);
		read++;
	}
	return (read);
}

//--- srcからの入力をdstへダンプ ---//
void dump(istream& src, ostream& dst)
{
	const int      buf_max = 16;
	size_t		   n;
	unsigned long  count = 0;
	unsigned char  buf[buf_max];

	dst << setfill('0');
	while ((n = read_num(src, buf, buf_max)) > 0) {
		int  i;

		dst << setw(8) << hex << count << ' ';
		for (i = 0; i < n; i++)
			dst << setw(2) << (unsigned)buf[i] << ' ';
		if (n < buf_max)
			for (i = n; i < buf_max; i++) dst << "   ";
		for (i = 0; i < n; i++)
			dst.put(isprint(buf[i]) ? buf[i] : '.');

		cout << '\n';
		count += buf_max;
	}
	cout << '\n';
}

int main(int argc, char* argv[])
{
	if (argc < 2)
		cerr << "ファイルを指定してください。\n";
	else {
		while (--argc > 0) {
			ifstream  input;
			input.open(*++argv, ios::binary);
			if (!input) {
				cerr << "ファイル" << *argv << "が正しくオープンできません。\n";
				return (1);
			}
			dump(input, cout);
			input.close();
		}
	}

	return (0);
}


//#include	<imanip.h>
#include	<iostream.h>
#include	<iomanip.h>
#include	<io.h>

const char  ESC = 0x1B;		// �G�X�P�[�v�R�[�h

//----- ��ʏ��� -----//
ostream& cls(ostream& os)
{
	if (os == cout)
		os << ESC << "[2J";
	return (os);
}

//----- �F�ݒ� -----//
ostream& color(ostream& os, int c)
{
	if (os == cout)
		os << ESC << "[3" << char(c+'0') << 'm';
	return (os);
}

OMANIP<int> color(int c)
{
	return ( OMANIP<int>(color, c) );
}

//----- ���W�ݒ� -----//
class Pos {		// ���W�N���X
	int  x;
	int  y;
public:
	Pos(int x, int y) { Pos::x = x;  Pos::y = y; }
	void locate(ostream& os) {
		os << ESC << '[' << x << ';' << y << 'H';
	}
};

ostream& locate(ostream& os, Pos xy)
{
	if (os == cout)
		xy.locate(os);
	return (os);
}

OMANIP<Pos> locate(int x, int y)
{
	Pos xy(x, y);
	return ( OMANIP<Pos>(locate, xy) );
}

//----- �A���[����num��炷 -----//
ostream& beep(ostream& os, int num)
{
	if (os == cout)
		while (num--)
			os << '\a';
	return (os);
}

OMANIP<int> beep(int num)
{
	return (OMANIP<int>(beep, num));
}

int main(void)
{
	char  cont;

	do {
		int	 c, x, y;

		cout << beep(3) << "�ǂ̐F�ŕ\�����܂����H";
		cout << "0�j���@1�j�ԁ@2�j�΁@3�j���@4�j�@5�j���@6�j���F�@7�j���@\n";
		cin >> c;

		cout << "�ǂ��ɕ\�����܂����H\n";
		cout << "�w���W�F";  cin >> x;
		cout << "�x���W�F";  cin >> y;

		cout <<  cls  << color(c) << locate(x, y) << "ABC\n";

		cout << "������x�\�����܂����H�i�x�^�m�j";
		cin >> cont;
	} while (cont == 'Y' || cont == 'y');

	return (0);
}


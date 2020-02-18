//#include	<imanip.h>
#include	<iostream.h>
#include	<iomanip.h>
#include	<io.h>

const char  ESC = 0x1B;		// エスケープコード

//----- 画面消去 -----//
ostream& cls(ostream& os)
{
	if (os == cout)
		os << ESC << "[2J";
	return (os);
}

//----- 色設定 -----//
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

//----- 座標設定 -----//
class Pos {		// 座標クラス
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

//----- アラームをnum回鳴らす -----//
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

		cout << beep(3) << "どの色で表示しますか？";
		cout << "0）黒　1）赤　2）緑　3）黄　4）青　5）紫　6）水色　7）白　\n";
		cin >> c;

		cout << "どこに表示しますか？\n";
		cout << "Ｘ座標：";  cin >> x;
		cout << "Ｙ座標：";  cin >> y;

		cout <<  cls  << color(c) << locate(x, y) << "ABC\n";

		cout << "もう一度表示しますか？（Ｙ／Ｎ）";
		cin >> cont;
	} while (cont == 'Y' || cont == 'y');

	return (0);
}


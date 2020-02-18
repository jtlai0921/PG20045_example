#include	<iostream.h>

int main(void)
{
	char  c;
	int	 upp[26] = {0};		// 配列uppの全要素を0で初期化
	int	 low[26] = {0};		// 配列lowの全要素を0で初期化

	while (cin.get(c)) {
		switch (c) {
		 case 'A': upp[ 0]++; break;		case 'a': low[ 0]++; break;
		 case 'B': upp[ 1]++; break;		case 'b': low[ 1]++; break;
		 case 'C': upp[ 2]++; break;		case 'c': low[ 2]++; break;
		 case 'D': upp[ 3]++; break;		case 'd': low[ 3]++; break;
		 case 'E': upp[ 4]++; break;		case 'e': low[ 4]++; break;
		 case 'F': upp[ 5]++; break;		case 'f': low[ 5]++; break;
		 case 'G': upp[ 6]++; break;		case 'g': low[ 6]++; break;
		 case 'H': upp[ 7]++; break;		case 'h': low[ 7]++; break;
		 case 'I': upp[ 8]++; break;		case 'i': low[ 8]++; break;
		 case 'J': upp[ 9]++; break;		case 'j': low[ 9]++; break;
		 case 'K': upp[10]++; break;		case 'k': low[10]++; break;
		 case 'L': upp[11]++; break;		case 'l': low[11]++; break;
		 case 'M': upp[12]++; break;		case 'm': low[12]++; break;
		 case 'N': upp[13]++; break;		case 'n': low[13]++; break;
		 case 'O': upp[14]++; break;		case 'o': low[14]++; break;
		 case 'P': upp[15]++; break;		case 'p': low[15]++; break;
		 case 'Q': upp[16]++; break;		case 'q': low[16]++; break;
		 case 'R': upp[17]++; break;		case 'r': low[17]++; break;
		 case 'S': upp[18]++; break;		case 's': low[18]++; break;
		 case 'T': upp[19]++; break;		case 't': low[19]++; break;
		 case 'U': upp[20]++; break;		case 'u': low[20]++; break;
		 case 'V': upp[21]++; break;		case 'v': low[21]++; break;
		 case 'W': upp[22]++; break;		case 'w': low[22]++; break;
		 case 'X': upp[23]++; break;		case 'x': low[23]++; break;
		 case 'Y': upp[24]++; break;		case 'y': low[24]++; break;
		 case 'Z': upp[25]++; break;		case 'z': low[25]++; break;
		}
	}

	cout << "A : " << upp[ 0] << " a : " << low[ 0] << '\n';
	cout << "B : " << upp[ 1] << " b : " << low[ 1] << '\n';
	cout << "C : " << upp[ 2] << " c : " << low[ 2] << '\n';
	cout << "D : " << upp[ 3] << " d : " << low[ 3] << '\n';
	cout << "E : " << upp[ 4] << " e : " << low[ 4] << '\n';
	cout << "F : " << upp[ 5] << " f : " << low[ 5] << '\n';
	cout << "G : " << upp[ 6] << " g : " << low[ 6] << '\n';
	cout << "H : " << upp[ 7] << " h : " << low[ 7] << '\n';
	cout << "I : " << upp[ 8] << " i : " << low[ 8] << '\n';
	cout << "J : " << upp[ 9] << " j : " << low[ 9] << '\n';
	cout << "K : " << upp[10] << " k : " << low[10] << '\n';
	cout << "L : " << upp[11] << " l : " << low[11] << '\n';
	cout << "M : " << upp[12] << " m : " << low[12] << '\n';
	cout << "N : " << upp[13] << " n : " << low[13] << '\n';
	cout << "O : " << upp[14] << " o : " << low[14] << '\n';
	cout << "P : " << upp[15] << " p : " << low[15] << '\n';
	cout << "Q : " << upp[16] << " q : " << low[16] << '\n';
	cout << "R : " << upp[17] << " r : " << low[17] << '\n';
	cout << "S : " << upp[18] << " s : " << low[18] << '\n';
	cout << "T : " << upp[19] << " t : " << low[19] << '\n';
	cout << "U : " << upp[20] << " u : " << low[20] << '\n';
	cout << "V : " << upp[21] << " v : " << low[21] << '\n';
	cout << "W : " << upp[22] << " w : " << low[22] << '\n';
	cout << "X : " << upp[23] << " x : " << low[23] << '\n';
	cout << "Y : " << upp[24] << " y : " << low[24] << '\n';
	cout << "Z : " << upp[25] << " z : " << low[25] << '\n';

	return (0);
}


//---------------------------------------------------------------------------
//	“ú¤é´Áclass Date(¤¶­±³¡¥÷)					"date.h"
//---------------------------------------------------------------------------

#include	<iostream.h>

//===== ¤é´Áclass =====//
class Date {
private:
	int		year;		// ¦è¤¸¦~
	int		month;		// ¤ë
	int		day;		// ¤é

public:
	Date(void);					// ¹w³]«Øºc¤¸
	Date(int y, int m = 1, int d =1);		// «Øºc¤¸

	int Year(void) const { return (year);  }	// 
	int Month(void) const { return (month); }	// 
	int Day(void)  const { return (day);   }	// 

	int CompY(int y) const { return (y - year);  }	// ¶Ç¦^©M¦~¤§¶¡ªº®t
	int CompM(int m) const { return (m - month); }	//¶Ç¦^©M¤ë¤§¶¡ªº®t
	int CompD(int d) const { return (d - day);   }	//¶Ç¦^©M¤é¤§¶¡ªº®t

};

ostream& operator<<(ostream& s, Date& x);		// ´¡¤J¹Bºâ¤l


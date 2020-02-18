//---------------------------------------------------------------------------
//	�����class Date(��������)					"date.h"
//---------------------------------------------------------------------------

#include	<iostream.h>

//===== ���class =====//
class Date {
private:
	int		year;		// �褸�~
	int		month;		// ��
	int		day;		// ��

public:
	Date(void);					// �w�]�غc��
	Date(int y, int m = 1, int d =1);		// �غc��

	int Year(void) const { return (year);  }	// 
	int Month(void) const { return (month); }	// 
	int Day(void)  const { return (day);   }	// 

	int CompY(int y) const { return (y - year);  }	// �Ǧ^�M�~�������t
	int CompM(int m) const { return (m - month); }	//�Ǧ^�M�뤧�����t
	int CompD(int d) const { return (d - day);   }	//�Ǧ^�M�餧�����t

};

ostream& operator<<(ostream& s, Date& x);		// ���J�B��l


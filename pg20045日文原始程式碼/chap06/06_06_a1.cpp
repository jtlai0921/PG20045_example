/*
	�W�����P���Q�[���i����֌W�j"kai.c"
*/

#include		<stdlib.h>

static int	pre = 0;	// �O��̎�
static int	crn = 0;	// ����̎�

extern int  draw;
extern int  win;
extern int  lose;

//--- �R���s���[�^�̎������ ---//
int kettei(void)
{
	srand(pre * (win + lose) + draw);
	crn = rand() % 3;
	pre = crn;
	return (crn);
}

//--- ���� ---//
int judge(int user)
{
	int diff = (user - crn + 3) % 3;

	if (diff == 0) {	// ��������
		draw++;
		return (0);
	} else if (diff % 3 == 2) {
		win++;
		return (1);			// ����
	}
	lose++;
	return (-1);			// ����
}


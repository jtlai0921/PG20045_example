/*
	【int】連想配列クラスAcAintの利用例
*/

#include	<iostream.h>

#include	"acaint.h"

int main(void)
{
	AcAint  x;				// int連想配列

	x["ｻｶﾞ"] = 0;
	x["ﾌｸｵｶ"] = 100;
	x["ﾅｶﾞｻｷ"] = x["ﾌｸｵｶ"] / 2;

	x.Put();

	return (0);
}


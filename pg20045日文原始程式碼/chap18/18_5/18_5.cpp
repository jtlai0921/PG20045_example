/*
	【string】連想配列の利用例　姓と名前
*/

#include	<iostream.h>

#include	"acastrng.h"

int main(void)
{
	AcAstring	name;			// string連想配列

	name["シバタ"] = "ボウヨウ";
	name["マツダ"] = name["ハセガワ"] = "タクヤ";
	name["アカオ"] = name["コガ"] = "ヒロシ";

	name.Put();

	return (0);
}


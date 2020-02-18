#include   <iostream.h>

int main(void)
{
    int	 i = 777;						//----- 整数 -----//

    cout.width(7);							// フィールド幅を7にする
    cout.fill('X');							// フィル文字に'X'を指定
    cout << i << '\n';

    cout.fill(' ');
    cout.setf(ios::showpos);				// 符号付き
    cout.setf(ios::left, ios::adjustfield);	// 左詰め
    cout << i << '\n';
    cout.unsetf(ios::left);					// 左詰め解除
    cout.unsetf(ios::showpos);				// 符号付き解除

    cout.width(7);							// フィールド幅を7にする
    cout.setf(ios::showbase);				// 基数付き
    cout.setf(ios::uppercase);				// 大文字基数表示
    cout.setf(ios::hex, ios::basefield);	// 16進数
    cout << i << '\n';
    cout.unsetf(ios::showbase);				// 基数付き解除
    cout.unsetf(ios::uppercase);			// 大文字基数表示の解除

    double  d = 555.0;					//----- 浮動小数点数 -----//

    cout.setf(ios::showpoint);				// 小数点以下を出力する
    cout << d << '\n';

    cout.precision(5);						// 浮動小数点数の精度は5桁
    cout << d << '\n';
    cout.unsetf(ios::showpoint);			// 小数点以下を出力しない

    cout.setf(ios::scientific, ios::floatfield);	// 指数付き
    cout << d << '\n';

    return (0);
}

/*
実行結果
XXXX777
+777
  0X309
555.000
555.00
5.55000e+02
*/

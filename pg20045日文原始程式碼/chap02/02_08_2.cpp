#include	<iostream.h>

int main(void)
{
	int	 a, b;
    //int max ,min;
	cout << "�����l������͂���F";
	cin >> a;

	cout << "�����l������͂���F";
	cin >> b;

   int max=a;
   int min=a;

	if (a > b)                                    
        min =b;
	else                                        
        max =b;
		cout << "���������̒l��" << min << "�ł��B\n"  
		     << "�傫�����̒l��" << max << "�ł��B\n";
 
    return (0);
}

/*
���s��i1�j
�����l������͂���F7��
�����l������͂���F12��
���������̒l��7�ł��B
�傫�����̒l��12�ł��B
���s��i2�j
�����l������͂���F7��
�����l������͂���F5��
���������̒l��5�ł��B
�傫�����̒l��7�ł��B
*/

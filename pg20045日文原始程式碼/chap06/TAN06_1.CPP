#include    <iostream.h>

int  vw = 0;

void func(void)
{
    int   vx = 0;
    static int  vy = 0;
    cout << vw << " " <<vx << " " << vy << '\n';
    vw++;  vx++;  vy++;
}

int main(void)
{
    for (int i = 0; i < 5; i++)
        func();
    return (0);
}

#include   <iostream.h>
#include   <iomanip.h>

int main(void)
{
    int	 i = 777;						//----- ®” -----//

    cout << setw(7) << setfill('x') << i << '\n';

    cout << setfill(' ')
         << setiosflags(ios::showpos) << setiosflags(ios::left)
         << i << '\n';
    cout << resetiosflags(ios::showpos) << resetiosflags(ios::left);

    cout << setw(7)
         << setiosflags(ios::showbase) << setiosflags(ios::uppercase)
         << hex << i << '\n';

    cout << resetiosflags(ios::showbase);
    cout << resetiosflags(ios::uppercase);

    double  d = 555.0;					//----- •‚“®¬”“_”‚Ì®Œ` -----//

    cout << setiosflags(ios::showpoint) << d << '\n';

    cout << setprecision(5) << d << '\n';
    cout << resetiosflags(ios::showpoint);

    cout << setiosflags(ios::scientific)
         << d << '\n';

cout << oct << 100 << '\n';
 cout << dec << 100 << '\n';
  cout << hex << 100 << '\n';
    return (0);
}


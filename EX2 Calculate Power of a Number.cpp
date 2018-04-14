#include <iostream>

using namespace std;

float power(int X, int N)
{
    int P(1);
    for( int i = 0 ; i < N ; i++ )
        P *= X;
    return ( 1.0 / P );
}

int main()
{
    power(3,2);
    cout << "\'W=1/X^N\' W =" << power(3,2) << endl;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int n, sum1(0), sum2(0);
    n = 4;
    while( n > 0 )
    {
        sum1 += n--;
    }
    n = 4;
    do{
        if( n <= 0) break;
        sum2 += n--;
    }while(1);
    cout << "Sum1 = " << sum1 << "\nSum2 = " << sum2 << endl;
    return 0;
}

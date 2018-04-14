#include <iostream>

using namespace std;

int* xOr(int *a, int n, int *b, int m, int &k)
{
    int *c = new int[ n+m ], D;
    k = 0;
    for(int i = 0; i < n ; i++ )
    {
        D = 1;
        for(int j = 0 ; j < m ; j++)
        {
            if( a[i] == b[j] )
            {
                D = 0;
                break;
            }
        }
        if( D )
        {
            c[k++] = a[i];
        }
    }
    for(int i = 0; i < n ; i++ )
    {
        D = 1;
        for(int j = 0 ; j < m ; j++)
        {
            if( b[i] == a[j] )
            {
                D = 0;
                break;
            }
        }
        if( D )
        {
            c[k++] = b[i];
        }
    }
    return c;
}

int main()
{
    int n = 5, m = 5, k;
    int a[n] = {3,4,5,6,7},b[m] = {1,3,6,2,8};
    int *c = xOr(a,n,b,m,k);
    for(int i=0; i < k ; i++)
        cout << c[i] << endl;
    return 0;
}

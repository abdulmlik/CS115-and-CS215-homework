#include <iostream>

using namespace std;

int u=8; //Global Variable

int main()
{
    int u=4;
    cout<<::u<<u<<endl;//::u = 8 , u = 4     :: == scope qualifier
    {//start block one   //block == if , while , do while ,function , ...
        int u=0;
        cout<<::u<<u<<endl;//::u = 8 , u = 0  overload u = 4
        {//start block two
            int u=9;
            cout<<::u<<u<<endl;//::u = 8 , u = 9 overload u = 0 & u= 4
        }//end block two & deallocation u = 9
        cout<<::u<<u<<endl;//::u = 8 , u = 0  overload u = 4
    }//end block one & deallocation u = 0
    cout<<u<<endl;//u =4
    return 0;
}// deallocation u = 4 & u = 0

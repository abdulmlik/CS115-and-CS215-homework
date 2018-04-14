#include <iostream>
#include <algorithm>
#include <string>

// stoi std c++11
// complexity of sort function = O( n*log(n) )

using namespace std;

int main()
{
    string sort_char[3]={"1000","20","1"},sort_number[3]={"1000","20","1"};
    for(int i=0;i<3;i++)
    {
        cout<<sort_char[i]<<endl;
    }
    sort(sort_char,sort_char+3);
    cout<< endl <<"sort by char : " << endl;
    for(int i=0;i<3;i++)
    {
        cout<<sort_char[i]<<endl;
    }
    sort(sort_number,sort_number+3, [&](string a,string b){ return stoi(a) < stoi(b); });
    cout<< endl <<"sort by number : " << endl;
    for(int i=0;i<3;i++)
    {
        cout<<sort_number[i]<<endl;
    }
    return 0;
}

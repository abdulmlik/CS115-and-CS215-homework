#include <iostream>
#include <typeinfo>

using namespace std;

//template<class type,class type2>
//bool typeEqual(type ch1, type2 ch2)
//bool typeEqual(auto ch1, auto ch2)
bool typeEqual(char ch1, char ch2)
{
    //if(typeid(ch1) != typeid(ch2)) return false;    // template & auto
    //else if(typeid(ch1) == typeid(ch2)) return true;

    if( isalpha(ch1) && isalpha(ch2) ) return true;
    else if( isdigit(ch1) && isdigit(ch2) ) return true;
    else if( !isalpha(ch1) && !isalpha(ch2) && !isdigit(ch1) && !isdigit(ch2) ) return true;
    return false;
}

int main()
{
    cout << typeEqual('2','9');// 1 = true   0 = false
    cout << typeEqual('a','F');
    cout << typeEqual('#','%');
    cout << typeEqual('2','a');
    cout << typeEqual('2','#');
    cout << typeEqual('#','a');
    return 0;
}

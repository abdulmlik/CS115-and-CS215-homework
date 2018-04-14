#include <iostream>
#include<stack>

using namespace std;
void fun(stack<int>* s)
{
    cout<<s->top()<< endl;
    s->pop();
}

int main()
{
    stack<int> s;
    s.push(3);
    s.push(4);
    fun(&s);
    cout<<s.top()<< endl;
    s.pop();
    /*s.push(5);*/
    cout<<"1.T|0.F :"<<s.empty()<< endl;
    cout << "Hello world!" << endl;
    return 0;
}

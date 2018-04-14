#include <iostream>

using namespace std;

typedef int (*f)(int );
//type is function (* name used)(parameter function)

int fun(int r)
{
    return 0;
}

int anyfun(f t)
{
    t(10);
    t(10);
    return 0;
}

int passAnyFun(auto t) //C++14
{
    //عند استعمال الاوتو يقفل التاكد من النوع ويحدد النوع لوحده
    t(10,3);//error
    t(10);//error
    t('f',34,"dsg");//error
    return 0;
}

int main()
{
    anyfun(fun);
    anyfun([&](int b){return b;});
    //passAnyFun(fun);
    /*
        [&](int b)
        {
            return b;
        }
    */
    cout << "Hello world!" << endl;
    return 0;
}

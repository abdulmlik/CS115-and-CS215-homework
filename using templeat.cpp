#include <iostream>

using namespace std;

template<class Type,int x>
/*
    template<> ==
    class ==> int ,char ,float ,bool ,...


*/
class array{
    Type list[x];
public:
    Type getDataIn(int i)
    {
        return list[i];
    }
    void setDataIn(Type d,int i)
    {
        list[i] = d;
    }
};

template<class Type,class C>
struct anystruct{
    Type u;
    C r;
};


template<class Type,class C>
Type anyfun(Type x,C y)
{
    return x;
}

template<class Type>
Type anyfun2(Type x,Type y)
{
    return x*y;
}

int main()
{
    array<int,8> u; //
    anystruct<int,float> k;
    anyfun(u,90);
    anyfun("hjkjbhj",k);
    anyfun('a',true);
    anyfun(90,7.7777);
    anyfun2(20,40);
    anyfun2(8.45,3.3435);
    cout << "Hello world!" << endl;
    return 0;
}

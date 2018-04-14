#include <iostream>

using namespace std;

enum one_enum{C,S};// C = 0 C = 1

/*---------star struct inside union --------------------*/
struct one_struct{
    int i;
    float f;
    char c;
};

union one_union{
    one_struct l;
};
/*---------end struct inside union --------------------*/

/*---------star union inside struct --------------------*/
union two_union{
    int i;
    float f;
    char c;
};

struct two_struct{
    two_union l;
};
/*---------end union inside struct --------------------*/

/*---------star struct inside union &temple --------------------*/
struct three_struct1{
    int i;
};
struct three_struct2{
    float f;
};
struct three_struct3{
    char c;
};

template<class TypeStruct>
union three_union{
    TypeStruct l;
};
/*---------end struct inside union &temple --------------------*/

int main()
{
    one_enum y;
    y = C;
    cout << "enum y = " << y << endl;
    y = S;
    cout << "enum y = " << y << endl << endl;

    one_struct a;
    a.i = 4;
    a.f = 4.5;
    a.c = 'a';
    cout << "struct a = { " << a.i << " , " << a.f << " , " << a.c << " }." << endl;

    one_union g;
    g.l.i = 4;
    g.l.f = 4.5;
    g.l.c = 'a';
    cout << "struct inside union g = { " << g.l.i << " , " << g.l.f << " , " << g.l.c << " }.\n" << endl;

    two_union l;
    l.i = 4;
    l.f = 4.5;
    l.c = 'a';
    cout << "union l = { " << l.i << " , " << l.f << " , " << l.c << " }. union saved one variable" << endl; // اليونين يخزن حقل واحد فقط


    two_struct v;
    v.l.i = 4;
    v.l.c = 'a';
    v.l.f = 4.5;
    cout << "union inside struct v = { " << v.l.i << " , " << v.l.f << " , " << v.l.c << " }. union saved one variable" << endl; // اليونين يخزن حقل واحد فقط

    three_union<three_struct1> X;
    three_union<three_struct2> Y;
    three_union<three_struct3> Z;
    X.l.i = 10;
    Y.l.f = 5.3;
    Z.l.c = 'w';
    cout << "struct inside union  X,Y,Z = { " << X.l.i << " , " << Y.l.f << " , " << Z.l.c << " }. " << endl; // اليونين يخزن حقل واحد فقط

    return 0;
}

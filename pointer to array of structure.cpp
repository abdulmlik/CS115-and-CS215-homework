#include <iostream>
#include <string.h>

using namespace std;

struct Consumer
{
    char   name[20];
    int    id;
    double lastRead;
    double currRead;
    double debt;
};

const float s = 0.2;

Consumer* inputConsumers(Consumer* con,int &Size);
char** listName(Consumer* con,const int &Size, int &n);

int main()
{
    int Size,n;
    Consumer* con;
    con = inputConsumers(con, Size);
    // يساوي بالمتغير حتى يخبر المين المتغر اصبح له قيمة يعني في الستدعاء الدالة التانية يعامله  كانه فيه قيمة
    char** arr = listName(con, Size,n);
    cout << endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout << "name " << i + 1 << " : " << arr[i] << endl;;
    }
    return 0;
}

Consumer* inputConsumers(Consumer* con,int &Size)
{
    cout << "Enter no of Consumers : ";
    cin >> Size;
    con = new Consumer[Size];
    float invoice[Size];
    for(int i = 0 ; i < Size ; i++)
    {
        cout << endl << "Enter data Consumer " << i + 1 << " : " << endl;
        cout << "Enter name : ";
        cin.ignore();
        cin.getline(con[i].name, 19);
        cout << "Enter id : ";
        cin >> con[i].id;
        cout << "Enter last read : ";
        cin >> con[i].lastRead;
        cout << "Enter current reading : ";
        cin >> con[i].currRead;
        cout << "Enter debt : ";
        cin >> con[i].debt;
        invoice[i] = ( con[i].currRead - con[i].lastRead ) * s + con[i].debt ;
    }
    for(int i = 0 ; i < Size ; i++)
    {
        cout << endl << "Consumer " << i + 1 << " : " << endl;
        cout << "name : " << con[i].name << endl;
        cout << "id : " << con[i].id << endl;
        cout << "last read : " << con[i].lastRead << endl;
        cout << "current reading : " << con[i].currRead << endl;
        cout << "debt : " << con[i].debt << endl;
        cout << "invoice : " << invoice[i]<< endl;
    }
    return con;
}

char** listName(Consumer* con,const int &Size, int &n)
{
    char** arr = new char*[Size];
    for(int i = 0 ; i < Size ; i++)
    {
        arr[i] = new char[20];
    }
    n = 0;
    for(int i = 0 ; i < Size ; i++)
    {
        if( con[i].debt == 0 )
        {
            strcpy(arr[n],con[i].name);
            n++;
        }
    }
    return arr;
}

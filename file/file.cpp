#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char n;
    int o=1;
    ifstream fl;
    fl.open("data.txt");
    while(!fl.eof())
    {
        fl>>n;
        cout<<"\n"<<n;
        if(o)fl.seekg(-1,ios::cur);o=0;
    }
    fl.close();
    return 0;
}

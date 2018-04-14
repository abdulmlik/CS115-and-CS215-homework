#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void read (){
long long student_id;
fstream info("ajaj.txt",ios::out);
string name;
cout<<"\nEnter name : ";
getline(cin,name);

cout<<"\nEnter student id : ";
cin>>student_id;

info<< name<<endl<<endl<<student_id;

}

void* af()
{
    int *t;
    t = new int();
    return t;
}

int main()
{
//    int x;
//    try{
//        cin>>x;
//    }
//    catch(exception e)
//    {
//        cout << "ggggggggggg";
//    }
    //read();
}

#include <iostream>
#include <fstream>
using namespace std;

fstream od;
string pats[]="data.txt";

struct Book
{
    int n;
    string fname;
    string lname;
    float sal;
};

int main()
{
    Book bk;
    fstream fl;
    cout << "\nEntre n:" ;cin>>bk.n;
    cout << "\nEntre first name :" ;cin>>bk.fname;
    cout << "\nEntre last name :" ;cin>>bk.lname;
    cout << "\nEntre salay :" ;cin>>bk.sal;
    fl.open("data.txt",ios::out|ios::app );
    fl<<bk.n<<"\t"<<bk.fname<<"\t"<<bk.lname<<"\t"<<bk.sal<<endl;
    fl.close();
    cout<<" n= "<<bk.n<<" first name : "<<bk.fname<<" last name : "<<bk.lname;
    return 0;
}

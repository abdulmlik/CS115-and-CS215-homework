#include <iostream> //cin,cout
#include <fstream>  //file
#include <cstring>  //strcpy
#include <stdio.h>  //remove
#include <stdlib.h>  //exit,system
#include <iomanip>   //setw
#define MAX_A 100    //const MAX_A=100

/* 111 Means No Data */

/*
«Ê·«: 111  ⁄‰Ì ·« ÌÊÃœ Õ”«»
1=true
0=false

œ«·… RememberInTheFile :
«·œ«·…  ” ﬁ»· «·»Ì«‰«  Ê ﬁÊ„ »Õ›ŸÂ« ›Ì „·› »«”„ CAA
Ê  Ã«Â· «·Õ”«» —ﬁ„ 111

œ«·… R_file :
 «·œ«·…  ﬁÊ„ »ﬁ—«¡… «·»Ì«‰«  „‰ «·„·› »«”„ CAA
( ﬁ—«¡ —ﬁ„ «·Õ”«» «Ê·« À„  ÷⁄ «·»Ì«‰«  ›Ì —ﬁ„ «·Õ”«» ‰«ﬁ’ Ê«Õœ ›Ì struct )

œ«·… P_Struct :
  «·œ«·…  ﬁÊ„ »ÿ»«⁄… struct
 Ê  Ã«Â· «·Õ”«» —ﬁ„ 111

œ«·… StartingValue :
 «·œ«·…  ﬁÊ„ »«⁄ÿ«¡ struct
 ﬁÌ„ «» œ«∆Ì…

œ«·… Search : «·œ«·…  ﬁÊ„ »«·»ÕÀ ⁄‰ Õ”«»  —Ã⁄ 1 ›Ì Õ«·… ÊÃÊœÂ Ê 0 ›Ì ⁄œ„ ÊÃÊœÂ
œ«·… print_txt: «·œ«·…  ﬁÊ„ » ﬂÊÌ‰ „·› ‰’Ì ··Õ”«»« 
œ«·… update_a : «·œ«·…  ﬁÊ„ » ⁄œÌ· —« » «Õœ «·Õ”«»« 
œ«·… new_a : «·œ«·…  ﬁÊ„ »«÷«›… Õ”«» ÃœÌœ
œ«·… delete_a : «·œ«·…  ﬁÊ„ »Õ–› «Õœ «·Õ”«»« 

*/

using namespace std;

struct Book
{
    int ip;
    char fname[20];
    char lname[20];
    double sala;
};


int RememberInTheFile(Book ST[])
{
    fstream CA("CAA.dat",ios::out |ios::binary);
    if(!CA)
    {
        cerr<<"File could not be opened "<<endl;
        exit(1);
    }//End if
    for(int i=0;i<MAX_A;i++)
    {
        if(ST[i].ip!=111)
        {CA<<ST[i].ip<<setw(20)<<ST[i].fname<<setw(20)<<ST[i].lname<<setw(10)<<ST[i].sala<<endl;}
    }//End for
    CA.close();
    return 0;
}

int R_file(Book ST[])
{
    fstream CA("CAA.dat",ios::in);
    if(!CA)
    {
        cerr<<"File could not be opened "<<endl;
        exit(1);
    }//End if
    int i=0,j;
    while(!CA.eof())
    {
     	CA>>i;
        j=i-1;
        ST[j].ip=i;
        CA>>setw(20)>>ST[j].fname>>setw(20)>>ST[j].lname>>setw(10)>>ST[j].sala;
    }//End while
    CA.close();
    return 0;
}

int P_Struct(Book ST[])
{
	cout<<"Acct"<<setw(20)<<"First Name"<<setw(20)<<"Last Name"<<setw(10)<<"Balance"<<endl;
    for(int i=0;i<MAX_A;i++)
    {
        if(ST[i].ip!=111)
        {
            cout<<"#"<<ST[i].ip<<setw(20)<<ST[i].fname<<setw(20)<<ST[i].lname<<setw(10)<<ST[i].sala<<endl;
        }
    }//End for
    return 0;
}

int StartingValue(Book ST[])
{
    for(int i=0;i<MAX_A;i++)
    {
        ST[i].ip=111;
        strcpy(ST[i].fname,"no_fname");
        strcpy(ST[i].lname,"no_fname");
        ST[i].sala=0;
    }
    return 0;
}

int Search(int n,int &z,Book ST[])
{
    int j=0,i=n-1;
    if(ST[i].ip==n)
    {
        j=1;
        z=i;
    }
    return j;
}//end sb

int print_txt(Book ST[]) //1
{
    system("cls");
    ofstream CA("print.txt");
    if(!CA)
    {
        cerr<<"File could not be opened "<<endl;
        exit(1);
    }//End if
    CA<<"Acct"<<setw(20)<<"First Name"<<setw(20)<<"Last Name"<<setw(10)<<"Balance"<<endl;
    //sort_ip(ST);
    for(int i=0;i<MAX_A;i++)
    {
    	if(ST[i].ip!=111)
    	{
        	CA<<ST[i].ip<<setw(20)<<ST[i].fname<<setw(20)<<ST[i].lname<<setw(10)<<ST[i].sala<<endl;
        }
    }//End for
    CA.close();
    P_Struct(ST);
    system("PAUSE");
    return 0;
}

int update_a(Book ST[])//2
{
    int n=0,z=111;
    double l,m;
    while(n>100||n<1)
    {
        system("cls");
        cout<<"Enter Account to Update(1-100): ";
        cin>>n;
    }
    if(Search(n,z,ST))
    {
        cout<<"#"<<ST[z].ip<<setw(20)<<ST[z].fname<<setw(20)<<ST[z].lname<<setw(10)<<ST[z].sala<<endl;
        cout<<"Enter charde (+) or payment (-): ";
        cin>>l;
        m=ST[z].sala*-1;
        if(l<ST[z].sala&&l>m)
        {
            ST[z].sala+=l;
            cout<<ST[z].ip<<setw(20)<<ST[z].fname<<setw(20)<<ST[z].lname<<setw(20)<<ST[z].sala<<endl;
        }
        else
            cout<<"Account #"<<n<<" has no value"<<endl;
    }
    else
        cout<<"Account #"<<n<<" does not exist"<<endl;
    system("PAUSE");
    return 0;
}

int new_a(Book ST[]) //3
{
    int n=0,z=111,e;
    while(n>100||n<1)
    {
        system("cls");
        cout<<"Enter New Account Number(1-100): ";
        cin>>n;
    }
    if(!Search(n,z,ST))
    {
        cout<<"Enter last name, first name, Balance\n? ";
        e=n-1;
        ST[e].ip=n;
        cin.ignore(); //clear input
        cout<<"first name: ";
        cin.getline(ST[e].fname,19,'\n');
        cout<<"last name: ";
        cin.getline(ST[e].lname,19,'\n');
        cin.clear();
        cout<<"Balance: ";
        cin>>ST[e].sala;
    }
    else
        cout<<"Account #"<<n<<" is in The Accounts."<<endl;
    system("PAUSE");
    return 0;
}

int delete_a(Book ST[]) //4
{
    int n=0,z=111;
    while(n>100||n<1)
    {
        system("cls");
        cout<<"Enter Account Number to delete(1-100): ";
        cin>>n;
    }
    if(Search(n,z,ST))
    {
        cout<<"Acct"<<setw(20)<<"First Name"<<setw(20)<<"Last Name"<<setw(10)<<"Balance"<<endl;
        cout<<ST[z].ip<<setw(20)<<ST[z].lname<<setw(20)<<ST[z].fname<<setw(10)<<ios::left<<ST[z].sala<<endl;
        ST[z].ip=111;
        cout<<"Account #"<<n<<" deleted."<<endl;
    }
    else
        cout<<"Account #"<<n<<" does not exist"<<endl;
    system("PAUSE");
    return 0;
}
void print_a()
{
    cout << "\n\t\t\tName           : Abdulmalik Ben Ali"<<"\n\t\t\tStudent Number : 213010551" << endl;
    cout <<"\n\t\t1- Stroea Fornatted text File of accounts called \n\t\t  'print.txt' For prining."<<endl;
    cout <<"\n\t\t2- Updute an Account."<<endl;
    cout <<"\n\t\t3- Add a New Account."<<endl;
    cout <<"\n\t\t4- Delete an Account."<<endl;
    cout <<"\n\t\t5- End Program."<<endl;
}

int main()
{
    fstream CA("CAA.dat",ios::in);
    if(!CA)
    {
        cerr<<"File could not be opened "<<endl;
        exit(1);
    }//End if
    Book ST[MAX_A];
    StartingValue(ST);
    R_file(ST);
    //P_Struct(ST);
    char ch;
    while(true)
    {
    	system("cls");
    	print_a();
        cout<<endl<<"Enter ch: ";
        cin>>ch;
        switch (ch)
        {
            case '1': print_txt(ST);break;
            case '2': update_a(ST);break;
            case '3': new_a(ST);break;
            case '4': delete_a(ST);break;
            case '5': RememberInTheFile(ST); exit(0);
        }
    }
}

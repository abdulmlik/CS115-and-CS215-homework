#include <iostream>
#include <string.h>
using namespace std;

int passwordStringht(string password){

    int password_strenght=0;

    if(password.length() >=8)

        password_strenght+=10;

    if(password.length() >=8)

        password_strenght+=(password.length()-8)/2;

        for(int i=0;i<password.length()/2;i++){

        if( isupper ( password[i] ) && islower ( password [i+1] ) || islower ( password[i] ) && isupper (password [i+1] ) ){

        password_strenght++;

        }


        if( (isalpha (password[i]) && isdigit ( password [ i + 1 ] )) || (isdigit (password[i]) && isalpha  ( password [ i + 1 ] ))){


        password_strenght++;

        }

        if( (isalpha (password[i]) && isascii( password [i+1] )) || (isascii (password[i]) && isalpha  ( password [i+1] ))){

        password_strenght++;
        }

        if(((!isalpha(password[i]) && !isdigit ( password [ i ] )) && isdigit(password[i+1])) || ((!isalpha(password[i+1]) && !isdigit ( password [ i+1 ] )) && isdigit(password[i])))

        password_strenght++;

        }

    return password_strenght;

}




int main()
{
    string password;

    cout<<"\nEnter password [End to exit ] ";
    cin>>password;
    while(password!="end"){
    int stringht = passwordStringht(password);
    cout<<"stringht : "<<stringht<<endl;
    cout<<"Enter password [end to strat ] : ";
    cin>>password;
    }

}

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    string fileName = "back.txt";   //back = су
    ifstream file;              //الملف
    char c;
    vector<char> temp;
    int Token(0),   //Count token
        Line(1),    //Count line
        col(0),     //Count column
        scol(0),
        Count(0),   //length token
        logic(1),   //0 or 1
        Error(0);   //Count Error
    file.open(fileName);
    while(file.get(c))
    {
        logic = 1;
        col++;
        if(c ==' '){ cout<<"spas"; continue;}  //back while 'skip space' #1
        else if(c =='\n') //line end in file
        {
            Line++;
            col = 0;
            cout<<"\\n";
            continue;
        }
        else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))//#2
        {
            Token++;
            cout<<"\n\tToken # "<<Token<<" = \'";
            scol = col;
            int o=0;
            do{
                cout<<c;
                file.get(c);
                col++;

            }while( ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') ) && !file.eof());// //end Do while
            col--;
            //file.seekg(-1,ios::cur);  // false
            //file.unget();             // true // back 1 char
            cout<<"\' at Line "<<Line<<" ,col "<<scol<<endl;
        }//end if a-z
        else if(c >= '0' && c <= '9')     //#4
        {
            Token++;
            cout<<"\n\tToken # "<<Token<<" = \'";
            scol = col;
            do{
                cout<<c;
                file.get(c);
                col++;
            }while( (c >= '0' && c <= '9') && !file.eof());// //end Do while

            col--;
            //file.seekg(-1,ios::cur);  // false
            file.unget();             // true // back 1 char
            cout<<"\' at Line "<<Line<<" ,col "<<scol<<endl;
            continue;
        }//end if digit
    }
    file.close();
    return 0;
}

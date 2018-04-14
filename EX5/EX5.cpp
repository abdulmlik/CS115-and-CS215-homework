#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct person{
    string nid, name, passportNo;
};

int search(string year)
{
    int X = stoi(year);
    if( X < 1900 && X > 2020 )
    {
        cerr << "The year is incorrect" << endl;
        return -1; //
    }
    ifstream file("persons.txt");
    if(!file)
    {
        cerr << "File (\" persons.txt \") not open " << endl;
        return -1;
    }
    ofstream wfile("passport.txt");
    if(!wfile)
    {
        cerr << "File (\" passport.txt \") not open " << endl;
        return -1;
    }
    person per;
    int Count = 0;
    while(!file.eof())
    {
        file >> per.nid >> per.name >> per.passportNo;
        if(!file) break;
        if( per.nid.substr(0,4) == year)
        {
            Count++;
            wfile << per.nid << "\t" << per.name <<"\t" << per.passportNo << endl;
        }
    }
    return Count;
}

int main()
{
    cout << search("1993") << endl;
    return 0;
}

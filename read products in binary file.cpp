#include <iostream>
#include <fstream>

using namespace std;

struct product
{
    int id;
    char name[20];
    float price;
};

void printProduct(ifstream& file);
void insert(ofstream& file);

int main()
{
    ofstream file("product.dat",ios::binary);
    if(!file.is_open())
    {
       cerr << "error in File \n";
       exit(1);
    }
    insert(file);
    file.close();

    ifstream file2("product.dat",ios::binary);
    if(!file2.is_open())
    {
       cerr << "File not found \n";
       exit(1);
    }
    printProduct(file2);
    file2.close();
    return 0;
}

void insert(ofstream& file)
{

    product d;
    int Size;
    cout << "Enter no of products : ";
    cin >> Size;

    for(int i = 0 ; i < Size ; i++)
    {
        cout << endl << "Enter data product " << i + 1 << " : " << endl;
        cout << "Enter id : ";
        cin >> d.id;
        cout << "Enter name : ";
        cin.ignore();
        cin.getline(d.name, 19);
        cout << "Enter price : ";
        cin >> d.price;
        file.write((char *) & d , sizeof(product));
    }
}

void printProduct(ifstream& file)
{
    product d;
    int i = 1;
    while(!file.eof())
    {
        file.read((char *) & d , sizeof(product));
        if(file.eof())continue;// ÊÝÇÏí ÇáÝÑÇÛ Ýí äåÇíÉ ÇáãáÝ
        if(d.price >= 80 && d.price <= 100)
        {
            cout << endl << "product " << i++ << " : " << endl;
            cout << "name : " << d.name << endl;
            cout << "id : " << d.id << endl;
            cout << "price : " << d.price << endl;
        }
    }
}

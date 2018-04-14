#include <iostream>
#include <string.h>

using namespace std;

struct Book
{
    char name[20];
    int id;
    float price;
    Book* next;
};

void insertBook(Book** head);
void printBookPrice(Book** head);

int main()
{
    Book* head = NULL;
    insertBook(&head);
    printBookPrice(&head);
    return 0;
}

void add_last(Book** head,char _name[20], int _id, float _price)
{
    Book* b = new Book;
    strcpy(b->name,_name);
    b->id = _id;
    b->price = _price;
    b->next = NULL;
    if(*head == NULL)
    {
        *head = b;

    }
    else
    {
        Book* c = *head;
        while(c->next != NULL)
        {
            c = c->next;
        }
        c->next = b;
    }
}

void insertBook(Book** head)
{
    int Size;
    cout << "Enter no of Books : ";
    cin >> Size;

    char name[20];
    int id;
    float price;

    for(int i = 0 ; i < Size ; i++)
    {
        cout << endl << "Enter data book " << i + 1 << " : " << endl;
        cout << "Enter name : ";
        cin.ignore();
        cin.getline(name, 19);
        cout << "Enter id : ";
        cin >> id;
        cout << "Enter price : ";
        cin >> price;
        add_last(head,name, id, price);
    }

}
void printBookPrice(Book** head)
{
     if( !(head == NULL) )
        {
           Book *c = *head;
           cout << endl << "list : ";
            while(c != NULL)
            {
                if( c->price > 15 && c->price < 30)
                    cout << endl << c->name << " | " << c->id << " | " << c->price;
                c = c->next;
            }
             cout << endl;
        }
        else
            cout << endl << "list is Empty " << endl;
}

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class linked
{
    Node *head,*tail;
public:
    linked()
    {
        head=tail=NULL;
    }
    bool isEmpty()
    {
        return head==NULL;
    }
    void add_l(int item)
    {
        Node *n=new Node;
        n->data=item;
        n->next=NULL;
        if(isEmpty())
        {
            head=tail=n;
        }
        else
        {
            tail->next=n;
            tail=n;
        }
    }
    void add_f(int item)
    {
        Node *n=new Node;
        n->data=item;
        n->next=NULL;
        if(isEmpty())
        {
            head=tail=n;
        }
        else
        {
            n->next=head;
            head=n;
        }
    }
    void addm(int item,int x)
    {
        Node *n=new Node;
        n->data=item;
        n->next=NULL;
        if(!isEmpty())
        {
           if(head->data==x)
           {
               n->next=head;
               head=n;
           }
           else if(tail->data==x)
           {
               tail->next=n;
               tail=n;
           }
           else
           {
               Node *c=head->next;
               while(c!=tail)
               {
                   if(c->data==x)
                   {
                       n->next=c->next;
                       c->next=n;
                       break;
                   }
                   else
                   {
                       c=c->next;
                   }
               }
           }

        }
        else
        {
            head=tail=n;
        }
    }
    void delete_x(int x)
    {
        if(!isEmpty())
        {
            Node *p;
            if(head->data==x)
            {
                p=head;
                head=head->next;
                p->next=NULL;
                delete p;
                return;
            }
            else
            {
               Node *c=head;
               while(c->next!=NULL)
               {
                   if(c->next->data==x)
                   {
                       p=c->next;
                       c->next=p->next;
                       p->next=NULL;
                       return;
                   }
                   else
                   {
                       c=c->next;
                   }
               }
               if(1){cout<<endl<<x<<" not found"<<endl;}
            }

        }
        else
            cout<<endl<<"list is Empty "<<endl;
    }

    void delete_ALL()
    {
        if(!isEmpty())
        {
            Node *p;
            p=head;
            tail=NULL;
            head=NULL;
            delete p; //delete all node , p->next ...
        }
        else
            cout<<endl<<"list is Empty "<<endl;
    }
    int num()
    {
        if(!isEmpty())
        {
            int i=1;
            Node *c;
            c=head;
            while(c->next!=NULL)
            {
                i++;
                c=c->next;
            }
            return i;
        }
        else
        {
            cout<<endl<<"list is Empty "<<endl;
            return 0;
        }
    }
    void max_min_avg()
    {
        if(!isEmpty())
        {
            int sum=0,i=1,max,min;
            float avg;
            Node *c;
            c=head;
            max=min=c->data;
            sum+=c->data;
            while(c->next!=NULL)
            {
                i++;
                c=c->next;
                sum+=c->data;
                if(c->data>max){max=c->data;}
                if(c->data<min){min=c->data;}
            }
            avg=sum/i;
        }
        else
        {
            cout<<endl<<"list is Empty "<<endl;
        }
    }
    static void CypeBinA(linked *a,linked *b)
    {
        if(!a->isEmpty())
        {
            Node *c;
            c=a->head;
            b->add_l(c->data);
            while(c->next!=NULL)
            {
                c=c->next;
                b->add_l(c->data);
            }
        }
        else
        {
            cout<<endl<<"list is Empty "<<endl;
        }
    }
    static int Com(linked *a,linked *b)
    {
        if(!a->isEmpty()&&!b->isEmpty())
        {
            Node *c,*o;
            int m=1;
            c=a->head;
            o=b->head;
            if(c->data!=o->data){m=0;}
            while(c->next!=NULL && o->next!=NULL)
            {
                c=c->next;
                o=o->next;
                if(c->data!=o->data){m=0;return m;}
            }
            return m;//(m)? cout<<"\nis Equal\n" : cout<<"\nis not Equal\n";
        }
        else
        {
            cout<<endl<<"list A or B is Empty "<<endl;
            return 0;
        }
    }
    void reverse() //
    {
        if(isEmpty()) return;
        Node *p,*c,*temp;
        if(head->next == NULL) return;//one node
        if(head->next->next == NULL)//two node
        {
            p = head;
            c = tail;
            temp = head;
            head = tail;
            tail = temp;
            c->next = p;
            p->next = NULL;
            return;
        }
        ////////////// many node
        c = head;
        temp = head;
        head = tail;
        tail = temp;
        temp = c;
        p = c->next;
        c = c->next->next;
        temp->next = NULL; //مهم
        while(1)
        {
            p->next = temp;
            temp = p;
            p = c;
            c = c->next;
            if(c == NULL)
            {
                p->next = temp;
                break;
            }
        }

    }
    void print()
    {
        if(!isEmpty())
        {
           Node *c=head;
           cout << endl << "list : ";
            while(c!=NULL)
            {
                cout << c->data << " ";
                c=c->next;
            }
        }
        else
            cout<<endl<<"list is Empty "<<endl;
    }
};

int main()
{
    linked u,v;
    u.add_l(1);
    u.add_l(2);
    u.add_l(3);
    u.add_l(4);
    u.add_l(5);
    u.add_l(6);
    u.add_l(7);
    u.add_f(0);
    u.addm(66,3);
    u.print();
    u.reverse();
    u.print();
    u.delete_x(0);
    u.delete_x(9);
    u.print();
    cout << "\nnumber node = " << u.num() << endl;
    linked::CypeBinA(&u,&v);
    v.print();
    (linked::Com(&u,&v))? cout<<"\nu,v is Equal\n" : cout<<"\nu,v is not Equal\n";
    v.delete_ALL();
    cout<< "V= ";
    v.print();
    cout << "\nHello world!" << endl;
    return 0;
}

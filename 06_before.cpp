#include <iostream>
using namespace std;

// SLL

class Node
{
    int value;
    Node* next;
    
    friend class SLL;
};

class SLL
{
    Node* headPtr;
  public:
    SLL();  // constructor
    ~SLL();  // destructor
    
    bool isEmpty();
    int head();
    void print();
    
    void insertFront(int x);
    void insertEnd(int x);
    
    void removeFront();
    void removeEnd();
};

SLL::SLL()
{
    headPtr=NULL;
};

bool SLL::isEmpty()
{
    if(headPtr==NULL)
    {
        //cout <<"The list is empty." <<endl;
        return 1;
    }
    else
    {
        //cout <<"The list is not empty." <<endl;
        return 0;
    };
};

int SLL::head()
{
    if(headPtr)
    {
        cout <<"Head: " <<headPtr->value <<endl;
        return headPtr->value;
    }
    else
    {
        cout <<"Head: N/A" <<endl;
        return 0;
    };
};

void SLL::print()
{
    Node* p=headPtr;
    cout <<"List: ";
    while(p!=NULL)
    {
        cout <<p->value <<" ";
        p=p->next;
    };
    cout <<endl;
};

void SLL::insertFront(int x)
{
    Node* n=new Node;
    n->value=x;
    n->next=headPtr;
    headPtr=n;
};

void SLL::insertEnd(int x)
{
    Node* n=new Node;
    n->value=x;
    n->next=NULL;
    
    Node* p=headPtr;
    if(p)  // non-empty list
    {
        while(p->next!=NULL)
            p=p->next;
        p->next=n;
    }
    else  // empty list
        insertFront(x);
};

void SLL::removeFront()
{
    Node* p=headPtr;
    if(p)
    {
        headPtr=headPtr->next;
        delete p;
    }
    else  // empty list
        cout <<"Failed to remove as the list is empty." <<endl;
};

void SLL::removeEnd()
{
    Node* p=headPtr;
    if(p==NULL)
        cout <<"Failed to remove as the list is empty." <<endl;
    else if(p->next==NULL)
    {
        delete p;
        headPtr=NULL;
    }
    else
    {
        while(p->next->next != NULL)
            p = p->next;
        delete p->next;
        p->next=NULL;
    };
};

SLL::~SLL()
{
    while(!isEmpty())
        removeFront();
};


int main()
{
    SLL myList;
    myList.insertFront(2);
    myList.insertFront(1);
    myList.insertEnd(3);
    myList.print();
    myList.removeEnd();
    myList.print();

    
    cout <<endl <<endl;
    return 0;
};

#include <iostream>

// SLL
class Node
{
    int value; // value stored in the node
    Node* next; // pointer to the next node
    friend class SLL; // declare SLL as friend, sll node'a erişebiliyor
};

class SLL
{
    Node* headPtr;
   public:
    SLL(); // constructor
    ~SLL(); // destructor
    void insertFront(int x);
    int head();
    bool isEmpty();
    void print();
    void removeFront();
    Node* find(int x);
    void insertAfter(int x, int w);
};

SLL::SLL()
{
    headPtr=NULL;
}

SLL::~SLL()
{
    while(!isEmpty())
        removeFront();
    std::cout <<"The list is deleted";
}

void SLL::insertFront(int x)
{
    Node* n = new Node; // create a new node and assign its address to n
    n->value = x; // pointerda metodlara memberlara okla erişiyorsun
    n->next = headPtr;
    headPtr = n;

}

int SLL::head()
{
    std::cout <<"Head: " <<headPtr->value <<std::endl;
    return headPtr->value;
}

bool SLL::isEmpty()
{
    if(headPtr==NULL)
    {
        return true;
    }
    else
    {
        std::cout <<"The list is not empty." <<std::endl;
        return false;
    }
}

void SLL::print()
{
    Node *p = headPtr;
    std::cout <<"List: ";
    while(p != NULL)
    {
        std::cout <<p->value <<" ";
        p = p->next; // link hopping
    }
    std::cout <<std::endl;
}

void SLL::removeFront()
{
    Node *p =headPtr;
    if (p)
    {
        headPtr=headPtr->next;
        delete p;
    }
    else
    {
        std::cout <<"The list is empty anyway." <<std::endl;
    }
}

Node *SLL::find(int x)
{
    Node *p=headPtr;
    while(p!=NULL)
    {
        if(p->value == x)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}

void SLL::insertAfter(int x, int w)
{
    Node *n = new Node;
    n->value = x;
    Node *p = find(w);
    n->next =p->next;
    p->next = n;

}

int main()
{
    SLL mylist;
    mylist.isEmpty();
    mylist.insertFront(7);
    mylist.isEmpty();
    mylist.head();
    mylist.insertFront(4);
    mylist.removeFront();
    mylist.insertFront(8);
    mylist.insertFront(1);
    std::cout <<mylist.find(1);
    mylist.removeFront();
    mylist.insertAfter(4,7);
    mylist.insertAfter(3,8);
    mylist.print();
    mylist.head();
    std::cout <<std::endl <<"--end--" <<std::endl;
    return 0;
}
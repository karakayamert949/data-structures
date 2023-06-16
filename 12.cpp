#include <iostream>
using namespace std;

// Binary Search Tree (int)

class node
{
    int value;
    node* left;
    node* right;
  friend class BST;
};

class BST
{
    node* root;
  public:
    BST() { root=NULL; };
    void insert(int);
    void print();  // will be improven next week
};

void BST::insert(int key)
{
    // Create the node
    node* n=new node;
    n->value=key;
    n->left=NULL;
    n->right=NULL;
    node* parent=NULL;  // need to find the parent
    if(root)
    {
        // Find the parent
        node* p=root;
        while(p)
        {
            parent=p;
            if(key <= p->value)
                p=p->left;
            else
                p=p->right;
        };
        // Insert as child of parent
        if(key <= parent->value)
            parent->left=n;
        else
            parent->right=n;
    }
    else
        root=n;
};

void BST::print()
{
    cout <<"0)\t\t    " <<root->value <<endl;
    cout <<"1)\t    " <<root->left->value <<"  \t\t    " <<root->right->value <<endl;
    cout <<"2)\t";
    if(root->left->left)
        cout <<root->left->left->value <<"\t";
    else
        cout <<"-" <<"\t";
    if(root->left->right)
        cout <<root->left->right->value <<"\t";
    else
        cout <<"-" <<"\t";
    if(root->right->left)
        cout <<root->right->left->value <<"\t";
    else
        cout <<"-" <<"\t";
    if(root->right->right)
        cout <<root->right->right->value <<endl;
    else
        cout <<"-" <<endl;
};


int main()
{
    BST tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    
    tree.print();
    
    cout <<endl <<endl;
    return 0;
};

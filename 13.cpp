#include <iostream>
using namespace std;

// (Binary Search) Tree Traversal

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
    void print();  // will be improven in the next code
    void preorder();
    void preorder(node*);
    void inorder();
    void inorder(node*);
    void postorder();
    void postorder(node*);
    void removeTree();
    void removeTree(node* &);
    ~BST() { removeTree(root); };
};

void BST::insert(int key)
{
    node* n=new node;
    n->value=key;
    n->left=n->right=NULL;
    node* parent=NULL;
    if(root)
    {
        node* p=root;
        while(p) // find new node's parent
        {
            parent=p;
            if(key <= p->value)
                p=p->left;
            else
                p=p->right;
        };
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
    cout <<"0)\t\t  " <<root->value <<endl;
    cout <<"1)\t  " <<root->left->value <<"  \t  " <<root->right->value <<endl;
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
    cout <<endl;
};

void BST::preorder(node* n)
{
    if(n)
    {
        cout <<" " <<n->value <<" ";
        preorder(n->left);
        preorder(n->right);
    };
};

void BST::preorder()
{
    cout <<"Preorder:  ";
    preorder(root);
    cout <<endl;
};

void BST::inorder(node* n)
{
    if(n)
    {
        inorder(n->left);
        cout <<" " <<n->value <<" ";
        inorder(n->right);
    };
};

void BST::inorder()
{
    cout <<"Inorder:   ";
    inorder(root);
    cout <<endl;
};

void BST::postorder(node* n)
{
    if(n)
    {
        postorder(n->left);
        postorder(n->right);
        cout <<" " <<n->value <<" ";
    };
};

void BST::postorder()
{
    cout <<"Postorder: ";
    postorder(root);
    cout <<endl;
};

void BST::removeTree(node* &n) // node passed by reference
{ // postorder
    if(n)
    {
        removeTree(n->left);
        removeTree(n->right);
        cout <<"Removing node with value " <<n->value <<endl;
        delete n;
        n=NULL;
    };
};

void BST::removeTree()
{
    cout <<endl <<"Removing tree:" <<endl;
    removeTree(root);
};

int main()
{
    BST tree;
    int keys[]={4,2,6,1,3,5,7};
    for(int i=0; i<7; i++)
        tree.insert(keys[i]);
    
    tree.print();
    
    tree.preorder();
    tree.inorder();
    tree.postorder();
    
    //tree.removeTree();
    //tree.print();
    
    cout <<endl <<endl;
    return 0;
};

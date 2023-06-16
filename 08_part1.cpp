#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n)
{
    if(n)  // recursive case
    {
        cout <<"Recursive case: n=" <<n <<endl;
        return n*factorial(n-1);
    }
    else  // (n=0) base case
    {
        cout <<"Base case: n=" <<n <<endl;
        return 1;
    };
        
};

int f(int n)
{
    if(n)
        return n*f(n-1);
    else
        return 1;
};

int g(int* A, int n)
{  // n: size
    if(n==1)
        return A[0];
    else
        return A[n-1]+g(A, n-1);
};

void h(int* A, int i, int j)
{  // i: first index  j: last index
    int temp;
    if(i<j)
    {
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        h(A, i+1, j-1);
    };
};

void h2(int* A, int i, int j)
{  // i: first index  j: last index
    int temp;
    while(i<j)
    {
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        i++;
        j--;
    };
};

int g2(int* A, int i, int n)
{  // i: first index  n: size
    if(n==1)
        return A[i];
    else
    {
        int n1=floor(n/2.0);
        int n2=ceil(n/2.0);
        return g2(A, i, n2)+g2(A, i+n2, n1);
    };
};

int f2(int n)
{
    if(n<=1)
        return n;
    else
        return f2(n-1)+f2(n-2);
};

int f1(int n, int i=0, int j=1)
{
    if(n==0)
        return i;
    else if(n==1)
        return j;
    else
        return f1(n-1, j, i+j);
};


int main()
{
    int n=4;
    cout <<factorial(n);
    cout <<endl <<"-------------------" <<endl;
    cout <<f(n);
    cout <<endl <<"-------------------" <<endl;

    int A[]={1,2,3,4,5};
    cout <<g(A, 5);
    cout <<endl <<"-------------------" <<endl;
    
    h(A, 0, 4);
    for(int i=0; i<5; i++)
        cout <<A[i] <<" ";
    cout <<endl <<"-------------------" <<endl;
    
    h2(A, 0, 4);
    for(int i=0; i<5; i++)
        cout <<A[i] <<" ";
    cout <<endl <<"-------------------" <<endl;
    
    cout <<g2(A, 0, 5);
    cout <<endl <<"-------------------" <<endl;
    
    for(int i=0; i<9; i++)
        cout <<f2(i) <<" ";
    cout <<endl <<"-------------------" <<endl;

    for(int i=0; i<9; i++)
        cout <<f1(i) <<" ";
    cout <<endl <<"-------------------" <<endl;
    
    cout <<endl <<endl;
    return 0;
};




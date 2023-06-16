#include <iostream>
using namespace std;

// Max-Heap

void heapify(int A[], int n, int root)
{

};

void build(int A[], int n)
{

};

void heapSort(int A[], int n)
{
  
};


int main()
{
    int n=11;
    int A[]={10, 3, 7, 4, 6, 1, 2, 9, 8, 5, 15};
    
    build(A, n);
    
    cout <<"Heap:     ";
    for(int i=0; i<n; i++)
        cout <<A[i] <<" ";
    cout <<endl;

    heapSort(A, n);
    
    cout <<"HeapSort: ";
    for(int i=0; i<n; i++)
        cout <<A[i] <<" ";
    
    cout <<endl <<endl;
    return 0;
};

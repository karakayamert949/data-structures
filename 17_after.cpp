#include <iostream>
using namespace std;

// Max-Heap

void heapify(int A[], int n, int root)
{
	int max=root;
	int left=2*root+1;
	int right=left+1;
    
    if(left<n && A[left]>A[max])
    	max=left;
    
    if(right<n && A[right]>A[max])
    	max=right;
    	
    if(max!=root)
    {
    	swap(A[root], A[max]);
    	heapify(A, n, max);
	};
};

void build(int A[], int n)
{
	int lastParent=n/2-1;
	for(int i=lastParent; i>=0; i--)
		heapify(A, n, i);
};

void heapSort(int A[], int n)
{
	build(A, n);
	for(int i=n-1; i>0; i--)
	{
		swap(A[0], A[i]);
		heapify(A, i, 0);
	};    
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

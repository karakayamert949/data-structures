#include <iostream>
#include <queue>
using namespace std;

// Priority Queue (int)

void print(priority_queue <int> pq)
{
    cout <<"Priority queue: ";
    while(!pq.empty())
    {
        cout <<pq.top() <<" ";
        pq.pop();
    };
    cout <<endl;
};

int main()
{
    priority_queue <int> pq1, pq2;
    
    if(pq1.empty())
        cout <<"The priority queue is empty." <<endl;
    else
        cout <<"The priority queue is not empty." <<endl;
    
    int A[]={1,8,5,6,3,4,0,9,7,2};
    for(int i=0; i<10; i++)
        pq1.push(A[i]);
    
    print(pq1);
    
    cout <<"Number of elements in the priority queue: " <<pq1.size() <<endl;
    cout <<"Element with highest priority: " <<pq1.top() <<endl;
    
    pq2.push(pq1.top());
    
    pq1.pop(); cout <<"Pop!" <<endl;
    cout <<"Element with highest priority: " <<pq1.top() <<endl;
      
    cout <<endl <<endl;
    return 0;
};

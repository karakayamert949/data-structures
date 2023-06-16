#include <iostream>
#include <queue>
using namespace std;

// Queue (int)

void print(queue <int> q)
{
    cout <<"Queue: ";
    while(!q.empty())
    {
        cout <<q.front() <<" ";
        q.pop();
    };
    cout <<endl;
};

int main()
{
    queue <int> q1, q2;
    
    if(q1.empty())
        cout <<"The queue is empty." <<endl;
    else
        cout <<"The queue is not empty." <<endl;
    
    q1.push(10);
    q1.push(20);
    q1.push(30);
    
    print(q1);
    
    cout <<"Number of elements in the queue: " <<q1.size() <<endl;
    cout <<"First element of the queue: " <<q1.front() <<endl;
    cout <<"Last element of the queue: " <<q1.back() <<endl;
    
    q1.pop(); cout <<"Pop!" <<endl;
    cout <<"First element of the queue: " <<q1.front() <<endl;
    
    q1.swap(q2);
    print(q1);
    print(q2);
    
    cout <<endl <<endl;
    return 0;
};
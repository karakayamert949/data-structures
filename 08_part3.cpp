#include <iostream>
#include <queue>
using namespace std;

void print(queue <int> q)
{
    cout << "queue: ";
    while (!q.empty())
    {
        cout <<q.front() <<" ";
        q.pop();
    }
    cout <<endl;
}

int main()
{
    queue <int> q1,q2;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    print(q1);
    q1.pop();
    cout <<"last element is "<<q1.back() <<endl;
    cout <<"first element is "<<q1.front() <<endl;
    cout <<"number of elements " <<q1.size();


    if (q1.empty())
    {
        cout << "stack is empty" <<endl;
    }
    else
    {
        cout << "stack is not empty" <<endl;
    }

    print(q1);
}

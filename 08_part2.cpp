#include <iostream>
#include <stack>
using namespace std;

void print(stack <int> st)
{
    cout << "Stack: ";
    while (!st.empty())
    {
        cout <<st.top() <<" ";
        st.pop();
    }
    cout <<endl;
}

int main()
{
    stack <int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    print(s1);
    s1.pop();
    cout <<s1.top() <<endl;

    if (s1.empty())
    {
        cout << "stack is empty" <<endl;
    }
    else
    {
        cout << "stack is not empty" <<endl;
    }

    print(s1);

    //check a word is palindrome
    stack <char> s2;
    string str="noon";
    int i;
    int n=str.length();
    int n2=n/2;

    for(i=0; i<n2; i++)
    {
        s2.push(str[i]);
    }
    if(n%2)
        i++;

    cout <<str <<" is ";

    for( ; i<n; i++)
    {
        if(str[i]!=s2.top())
        {
            cout <<"not ";
            break;
        }
        else
            s2.pop();
    }
    cout << "a palindrome." << endl;
}
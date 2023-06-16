#include <iostream>
#include <stack>
using namespace std;

// Stack (char)

int main()
{
    stack <char> s;
    string str="noon";  // racecar
    int i;
    int n=str.length();
    int n2=n/2;
        
    for(i=0; i<n2; i++)
        s.push(str[i]);
    
    if(n%2)   // odd
        i++;  // skip the char in the middle
    
    cout <<"\"" <<str <<"\" is";
    for( ; i<n; i++)
    {
        if(str[i]!=s.top())
        {
            cout <<" not";
            break;
        }
        else
            s.pop();
    }
    cout <<" a palindrome." <<endl;

    cout <<endl <<endl;
    return 0;
};

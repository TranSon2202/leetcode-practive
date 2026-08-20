#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isValid(string s)
{
       stack<char> stk;
    if(s.size()==1) return false;
    for(char c : s)
    {
        if(c == '[' || c == '{' || c == '(') stk.push(c);
        else
        {
            if(c == ']' && stk.top() == '[' || c == ')' && stk.top() == '(' || c == '}' && stk.top() == '{' ) stk.pop();
            else return false;
            
        }

    }
    if(!stk.empty()) return false;
    return true;
   

}
int main()
{
    string s;
    getline(cin,s);
    if(isValid(s))
    {
        cout << "true";
    }
    else cout << "false";
}
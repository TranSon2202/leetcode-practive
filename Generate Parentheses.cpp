#include <iostream>
#include <vector>
#include <string>
using namespace std;
void backtrack(string s, int open, int close, vector<string>& result, int n)
{
    if(s.size() == 2*n) 
    {
        result.push_back(s);

    }
    if(open < n)
    {
       
        backtrack(s + '(',open + 1, close, result, n);
    }

    if(close < open)
    {
    
        backtrack(s + ')',open,close + 1, result, n);
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> result;

    backtrack("" ,0 ,0 ,result,n );
    
    return result;

}
int main()
{
    int n; cin >> n;
    vector<string> s = generateParenthesis(n);
    for(int i=0; i<s.size(); i++)
    {
        cout << s[i] <<  " ";
    }
}
#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n)
{
    string s = "1";
    for(int k=1; k < n; k++)
    {
        int count = 1;
        string result = "";
        for(int i=1; i< s.size() ; i++)
        {
            if(s[i] == s[i-1]) count++;
            else 
            {
                result += to_string(count);
                result += s[i-1] ;

                count = 1;
            }
            
        }
        result += to_string(count);
        result += s[s.size()-1];

        s = result;
    }
    return s;
}
int main()
{
    int n; cin >> n;
    string s= countAndSay(n);
    cout << s;
}
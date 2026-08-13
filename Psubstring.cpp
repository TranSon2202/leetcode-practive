#include <iostream>
#include <string>
using namespace std;
string longestPalindrome(string s)
{
    int n = s.size();
    bool **dp = new bool*[n];
    for(int i=0; i<n; i++)
    {
        dp[i]= new bool[n]{false};
    }
    for(int i=0; i < n; i++)
    {
        dp[i][i] = true;
    }
    int maxLen = 1;
    int start = 0;
    for(int i=n-1; i>=0; i--)
    {
        for(int j=i+1; j<n; j++)
        {
            if(s[i]==s[j])
            {
            
                if(j - i <3) dp[i][j] =true;
            
                else dp[i][j] = dp[i+1][j-1];
    
            }

            if(dp[i][j] && j-i+1 > maxLen)
            {
                start = i;
                maxLen = j-i+1;

            }
        }
    }
    return s.substr(start,maxLen);
}

int main()
{
    string s;
    getline(cin,s);
    string result = longestPalindrome(s);
    cout << result;
}
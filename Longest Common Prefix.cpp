#include <iostream>
#include <string>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs) 
{
    for(int i=0; i< strs[0].size(); i++)
    {
        char c = strs[0][i];
        for(int j=1; j< strs.size(); j++)
        {
            if( i >= strs[j].size() || strs[j][i] != c)
            {
                return strs[0].substr(0,i);

            }
        }
    }
        
}
int main()
{
    
    int n; cin >> n;
    cin.ignore();
    vector<string> strs(n); 
    for(int i=0; i<n; i++)
    {
      getline(cin,strs[i]);
    }
    cout << longestCommonPrefix(strs);

}
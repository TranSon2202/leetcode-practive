#include <iostream>
#include <string>

using namespace std;

bool check(string haystack, string needle, int temp)
{
    for(int j=1;j < needle.size(); j++)
    {
       
            if(haystack[temp+j] != needle[j]) return false;

    }
    return true;
}

int strStr(string haystack, string needle)
{
     if(needle.size() > haystack.size()) return -1;
    for(int i = 0; i + needle.size() <= haystack.size(); i++)
    {
        if(haystack[i] == needle[0])
        {
            if(check(haystack,needle,i)) return i;
        }
       
    }
    return -1;
}
int main()
{
    string haystack, needle;
    getline(cin, haystack);
    getline(cin, needle);
    cout << strStr(haystack,needle);
}
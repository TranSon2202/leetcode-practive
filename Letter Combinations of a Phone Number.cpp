#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

void Init(map<char, string>& mp)
{
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";
}
void XuLy(string digits, string current, vector<string>& result, int index, map<char, string> mp)
{
    if(index == digits.size())
    {
        result.push_back(current);
        return;
    }

    string s = mp[digits[index]];

    for( char c : s)
    {
        current.push_back(c);
        XuLy(digits,current,result, index+1, mp);
        current.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    map<char, string> mp;
    Init(mp);
    vector<string> result;
    string current = "";
    int index = 0;
    XuLy(digits, current, result, index, mp);
    return result;
}

int main()
{
    string digits;
    getline(cin, digits);
    vector<string> result = letterCombinations(digits);
    for(string c: result)
    {
        cout << c;
    }

}
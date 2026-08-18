#include <iostream>
#include <map>
#include <string>
using namespace std;
int romanToInt(string s)
{
    map <char, int> roman;
    roman['M'] = 1000;
    roman['D'] = 500;
    roman['C'] = 100;
    roman['L'] = 50;
    roman['X'] = 10;
    roman['V'] = 5;
    roman['I'] = 1;

    int result = 0;

    for(int i=0; i< s.size()-1; i++)
    {
        if(roman[s[i]] < roman[s[i+1]]) result -= roman[s[i]];
        else result += roman[s[i]];
    }
    result += roman[s[s.size()-1]];

    return result;

}
int main()
{
    string s;
    getline(cin, s);
    cout << romanToInt(s);
}
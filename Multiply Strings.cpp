#include <iostream>
#include <string>
#include <vector>
using namespace std;

string multiply(string num1, string num2)
{
    if(num1 == "0" || num2 == "0")  return "0";
    vector<int> result(num1.size() + num2.size(),0);
    for(int i = num1.size()-1; i>=0; i--)
    {
        for(int j=num2.size()-1; j>=0; j--)
        {
            int a = num1[i] - '0';
            int b = num2[j] - '0';

            result[i+j+1] += a * b;
        }
    }
    for(int i= result.size()-1; i>0; i--)
    {
        result[i-1] += result[i] / 10;
        result[i] %=10;
    }

    string ans;
    int start = 0;
    while(start < result.size() && result[start] == 0)
    {
        start++;
    }
    for(int i = start; i< result.size(); i++)
    {
        ans+= to_string(result[i]);

    }
    return ans;

}

int main()
{
    string num1,num2;
    getline(cin,num1);
    getline(cin,num2);
    cout << multiply(num1,num2);
}
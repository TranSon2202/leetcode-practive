#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1 || numRows >= s.length())
        return s;

    vector<string> rows(numRows);

    int row = 0;
    int direction = 1;

    for (char c : s)
    {
        rows[row] += c;

        if (row == numRows - 1)
            direction = -1;

        else if (row == 0)
            direction = 1;

        row += direction;
    }

    string result;

    for (string r : rows)
    {
        result += r;
    }   

    return result;
}

int main()
{
    string s;
    getline(cin, s);
    int numRows;
    cin >> numRows;
    string result = convert(s, numRows);
    cout << result;
}
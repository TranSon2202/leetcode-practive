#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int divide(int dividend, int divisor)
{
    long long x = dividend;
    long long y = divisor;
    long long result =0;
    if(x == 0) return 0;

   

    if (x == INT_MIN && y == -1)
        return INT_MAX;

    


    bool checkdividend, checkdivisor;
    checkdividend = false;
    checkdivisor = false;
    if(x < 0)
    {
        checkdividend = true;
        x = -x;
        
    } 
    if(y <0)
    {
        checkdivisor = true;
        y = -y;
        
    }
    
    while(x >= y)
    {
        long long temp = y ;
        long long count = 1;
        while(temp <= x - temp)
        {
            temp <<= 1;
            count <<=1;
        }
        
        result += count;
        x -= temp;
    }
    if(checkdividend && checkdivisor) return result;
    else if(checkdividend && !checkdivisor) return -result;
    else if(!checkdividend && checkdivisor) return -result;
    else return result;

        
}
int main()
{
    int dividend, divisor;
    cin >> dividend >> divisor;
    cout << divide( dividend,  divisor);
}
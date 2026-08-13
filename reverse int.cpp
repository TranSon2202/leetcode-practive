#include <iostream>
#include <climits>
using namespace std;
int reverse(int x)
{
    long long y=0;
    bool check = false;
    if(x<0)
    {
         x*=-1;
        check = true;
    }
    while(x>0 )
    {
        if(y==0)
        {
            y+=x%10;
        
        }
        else
        {
            y*=10;
            y+=x%10;
           
        }
        x/=10;
    }
    if(check)
    {
        y*=-1;
    }
    
    if(y <= INT_MAX && y > INT_MIN) return y;
    else return 0;
    
}
int main()
{
    int x; cin >> x;
    int y=reverse(x);
    cout << y;
}
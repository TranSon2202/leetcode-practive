#include <iostream>
using namespace std;
int fibo(int n, int dp[])
{
    if(n<2) return n;
    if(dp[n]!=-1) return dp[n];

    dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
    return dp[n];
}
int main()
{
    int n;
    cout <<"Nhap thu tu so fibo can tim: ";
    cin >> n;
    int* dp = new int[n+1];
    for(int i=0; i<=n; i++)
    {
        dp[i]=-1;
    }
    for(int i=0; i<=n; i++)
    {
        cout << dp[i];
    }
    cout << "\n"<< fibo(n,dp);
}
 #include <iostream>
 #include <climits>
 using namespace std;
int reverseFunc(int x)
{
    long long y = x;
    long long result = 0;
    while(y>0)
    {
        if(result == 0)
        {
            result+= y%10;
        }
        else
        {
            result*=10;
            result+= y%10;
        }
        y/=10;
    }
    if(result <= INT_MAX && result > INT_MIN) return (int)result;
    else return 0;
}
 bool isPalindrome(int x)
{
    if(x<0) return false;
    else if(x==0) return true;
    int z= reverseFunc(x);
    if(x - z ==0) return true;
    else return false;
}

 int main()
 {
    int x; cin >> x;
    if(isPalindrome(x)) cout << "true";
    else cout << "false";

 }
#include <iostream>
#include <vector>
using namespace std;
bool Checks(vector<int>& check, int x)
{
    for(int i = 0; i< check.size(); i++)
    {
        if(x == check[i]) return false;
    }
    check.push_back(x);
    return true;
}
int removeDuplicates(vector<int>& nums) 
{
    vector<int> check ;
    int count = 0;
    for(int i=0; i< nums.size(); i++)
    {
        if(Checks(check,nums[i])) count++;
    }
    for(int i = 0; i < check.size(); i++)
    {
        cout << check[i] << " ";
    }
    return check.size();
   

        
}
int main()
{
    int n; cin >> n;
    vector<int> nums;
    int x;
    for(int i=0; i < n; i++)
    {
        cin >> x;
        nums.push_back(x);
    }
    cout << removeDuplicates(nums);
}
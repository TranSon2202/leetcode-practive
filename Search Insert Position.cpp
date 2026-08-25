#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size()-1;
    int mid;
    while (left <= right)
    {
        mid = (left+right)/2;

        if(nums[mid] == target ) return mid;

        if(nums[mid] < target) left=mid+1;
        else right = mid-1;
    }
    if(nums[mid] < target) return mid+1;
    else return mid;
    
        
}

int main()
{
    int n; cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    int target; cin >> target;
    cout << searchInsert(nums, target);
}
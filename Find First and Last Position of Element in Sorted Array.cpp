#include <iostream>
#include <vector>

using namespace std;
vector<int> searchRange(vector<int>& nums, int target) 
{
    vector<int> result;
    int first = -1;
    int last = -1;
    int left = 0;
    int right = nums.size()-1;

    while(left <= right)
    {
        int mid = (left+right)/2;
        if(nums[mid] == target)
        {
            first = mid;
            right = mid -1;
        }

        if(nums[mid] > target)
        {
            right = mid -1;
        }

        if(nums[mid] < target)
        {
            left = mid+1;
        }
    }
    
    left = 0;
    right = nums.size()-1;

     while(left <= right)
    {
        int mid = (left+right)/2;
        if(nums[mid] == target)
        {
            last = mid;
            left = mid + 1;
        }

        if(nums[mid] > target)
        {
            right = mid -1;
        }

        if(nums[mid] < target)
        {
            left = mid+1;
        }
    }
    result.push_back(first); result.push_back(last);
    return result;  
}
int main()
{
    int n; cin >> n ;
    vector<int> nums(n);

    for(int i=0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target; cin >> target;
    vector<int> result = searchRange(nums,target);
    for(int c : result)
    {
        cout << c;
    }
}
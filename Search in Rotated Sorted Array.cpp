#include <iostream>
#include <vector>
#include <map>
#include <Algorithm>
using namespace std;




int search(vector<int>& nums, int target)
{
    int left = 0; 
    int right = nums.size() -1;

    while(left <= right)
    {
        int mid = (left + right)/2;

        if(nums[mid] == target) return mid;

        if(nums[left] <= nums[mid] )
        {
            if(nums[left] <= target && target < nums[mid])
            {
                right = mid - 1;
            }
            else left = mid + 1;
        }
        else
        {
            if(nums[mid] < target && target <= nums[right])
            {
                left = mid + 1;
            }
            else right = mid - 1;
        }
    }
    return -1;

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
    cout << search(nums, target);
}
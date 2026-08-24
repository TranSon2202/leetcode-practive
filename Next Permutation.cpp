#include <iostream>
#include <vector>
using namespace std;
void nextPermutation(vector<int>& nums)
{
    int i = nums.size() -2;
    while(i >= 0)
    {
        if(nums[i] < nums[i+1]) break;
        i--;
    }
    int j = i+1;
    if (i >= 0)
    {
        int j = nums.size() - 1;

        while (nums[j] <= nums[i])
        {
            j--;
        }

        swap(nums[i],nums[j]);
    }

    int left = i+1;
    int right = nums.size()-1;
     while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
}
int main()
{
    int n; cin >> n;
    vector<int> nums(n);
    for(int i=0; i< n; i++)
    {
        cin >> nums[i];
    }
    nextPermutation(nums);
    for(int i=0; i< n; i++)
    {
        cout << nums[i];
    }
}
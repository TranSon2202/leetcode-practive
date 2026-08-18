#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
 vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> result ;
    sort(nums.begin(),nums.end());
    for(int i=0 ; i< nums.size()-2 ; i++)
    {
        if(i>0 && nums[i] == nums[i-1]) continue;
        int left = i+1;
        int right = nums.size()-1;
        int target = -nums[i];
        int s=0;
        while(left<right)
        {
            s= nums[left] + nums[right];
            if(s < target) left++;
            else if (s > target) right--;
            else
            {
                result.push_back({nums[i],nums[left],nums[right]});
                left++;
                right--;
                while(left<right && nums[left] == nums[left-1]) left++;
                while(left<right && nums[right] == nums[right+1]) right --; 
            }

        }

    }
    return result;

        
}
int main()
{
    int n; cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n ; i++)
    {
        cin >> nums[i];
    }
    vector<vector<int>> result =  threeSum(nums);
    for(int i = 0; i < result.size(); i++)
{
    for(int j = 0; j < result[i].size(); j++)
    {
        cout << result[i][j] << " ";
    }
    cout << endl;
}

}
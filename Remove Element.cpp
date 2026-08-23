#include <iostream>
#include <vector>

using namespace std;
int removeElement(vector<int>& nums, int val)
{
    int i = 0;
    int j = nums.size() - 1;

    while(i <= j)
    {
        if(nums[i] == val)
        {
            nums[i] = nums[j];
            j--;
        }
        else
        {
            i++;
        }
    }

    return i;

}
int main()
{
    int n; cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n ; i++)
    {
        cin >> nums[i];
    }
    int val; cin >> val;
    cout << removeElement(nums, val);
}
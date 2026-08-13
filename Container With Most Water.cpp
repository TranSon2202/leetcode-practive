#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int>& height) 
{
    int left = 0;
    int right = height.size()-1;
    int max = 0;
    int result =0;
    while(left < right)
    {
        result = min(height[left],height[right]) * (right-left);
        if(max < result) max = result;
        if(height[left] < height[right]) left++;
        else right--;
    }
    return max;

}
int main()
{
    vector<int> height;
    int n; cin >> n;
    int x;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        height.push_back(x);
    }
    cout << maxArea(height);

}
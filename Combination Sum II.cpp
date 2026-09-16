#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<vector<int>>& result, vector<int>& current, vector<int>& candidates, int start, int target)
{
    if(start > candidates.size())
    {
        return;
    }
    if(target == 0)
    {
        result.push_back(current);

    }
    if(target < 0)
    {
        return;
    }
    for(int i= start; i < candidates.size(); i++)
    {
        if(i > start && candidates[i] == candidates[i-1]) continue;

        if(candidates[i] > target) break;


        current.push_back(candidates[i]);

        backtrack(result, current, candidates, i+1, target - candidates[i]);

        current.pop_back();
        
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    vector<vector<int>> result;
    vector<int> current;
    sort(candidates.begin(), candidates.end());

    backtrack(result, current, candidates, 0, target);

    return result;
}
int main()
{
    int n; cin>> n;
    vector<int> candidates(n);
    for(int i=0; i< n; i++)
    {
        cin >> candidates[i];
    }
    int target; cin >> target;
    vector<vector<int>> result = combinationSum2(candidates, target);
    for(int i =0; i< result.size(); i++)
    {
        for(int j= 0; j< result[i].size(); j++)
        {
            cout << result[i][j];
        }
        cout << endl;
    }
}
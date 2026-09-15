#include <iostream>
#include <vector>
using namespace std;
void backtrack(vector<int>& candidates, vector<vector<int>>& result, vector<int>& current, int start, int target )
{
    if(target == 0)
    {
        result.push_back(current);
    }
    if(target < 0)
    {
        return;
    }
    for(int i = start; i < candidates.size(); i++)
    {
        current.push_back(candidates[i]);

        backtrack(candidates, result, current, i, target - candidates[i] );

        current.pop_back();
    }


}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
    vector<vector<int>> result;
    vector<int> current;

    backtrack(candidates, result, current, 0, target);

   
    return result;
}
int main()
{
    int n; cin >> n;
    vector<int> candidates(n);
    for(int i=0; i< n; i++)
    {
        cin >> candidates[i];
    }
    int target; cin >> target;
    vector<vector<int>> result = combinationSum(candidates, target);
    for(int i=0; i< result.size(); i++)
    {
        for(int j=0; j< result[i].size(); j++)
        {
            cout<< result[i][j];
        }
        cout << endl;
    }

}
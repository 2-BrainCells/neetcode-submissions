class Solution {
   public:
    void combinations(vector<vector<int>>& ans, vector<int>& candidates, vector<int> temp,
                      int target, int sum, int i) {
        if (sum > target) return;
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        for (int j = i; j < candidates.size(); j += 1) {
            if((j != i) && (candidates[j] == candidates[j - 1])) continue;
            int newSum = sum + candidates[j];
            if(newSum > target) break;
            temp.push_back(candidates[j]);
            cout << newSum << " ";
            combinations(ans, candidates, temp, target, newSum, j + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        combinations(ans, candidates, temp, target, 0, 0);
        return ans;
    }
};

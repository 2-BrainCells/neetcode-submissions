class Solution {
    int sum = 0;
    vector<int> temp;

   public:
    void combinations(vector<vector<int>>& ans, vector<int> nums, vector<int> temp, int target,
                      int i, int sum) {
        if (sum > target) return;
        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            int nextSum = sum + nums[j];
            if (nextSum > target) break;
            temp.push_back(nums[j]);
            combinations(ans, nums, temp, target, j, nextSum);
            temp.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        combinations(ans, nums, temp, target, 0, sum);
        return ans;
    }
};

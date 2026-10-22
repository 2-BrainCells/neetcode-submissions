class Solution {
   public:
    void combinations(vector<vector<int>>& ans, vector<int>& nums, vector<int>& temp, int i) {
        ans.push_back(temp);
        for (int j = i; j < nums.size(); j++) {
            // Skip duplicates at the same recursion level
            if (j > i && nums[j] == nums[j - 1]) continue;
            temp.push_back(nums[j]);
            combinations(ans, nums, temp, j + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        combinations(ans, nums, temp, 0);
        return ans;
    }
};
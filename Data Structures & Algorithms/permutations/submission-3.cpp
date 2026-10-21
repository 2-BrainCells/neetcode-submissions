class Solution {
   public:
    void combinations(vector<vector<int>>& ans, vector<int> &nums, vector<int> &temp, vector<bool> &used, int size) {
        if (temp.size() == size) {
            ans.push_back(temp);
            return;
        }
        for(int j = 0; j < size; j += 1){
            if(used[j] == true) continue;
            temp.push_back(nums[j]);
            used[j] = true;
            combinations(ans, nums, temp, used, size);
            temp.pop_back();
            used[j] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int size = nums.size();
        vector<bool> used(size, false);
        combinations(ans, nums, temp, used, size);
        return ans;
    }
};

class Solution {
   public:
    int checkRob(vector<int>& nums, int start, int end) {
        vector<int> dp(end + 1, -1);

        dp[start] = nums[start];
        dp[start + 1] = max(nums[start + 1], dp[start]);

        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        for (auto val : dp) {
            cout << val << " ";
        }
        cout << endl;
        return dp[end];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        return max(checkRob(nums, 0, n - 2), checkRob(nums, 1, n - 1));
    }
};

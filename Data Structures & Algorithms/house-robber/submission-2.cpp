class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int maxMoney = -1;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (i == 1)
                dp[i] = max(nums[i], dp[i - 1]);
            else
                dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
            if (maxMoney < dp[i]) maxMoney = dp[i];
        }
        for (auto val : dp) {
            cout << val << " ";
        }
        return maxMoney;
    }
};

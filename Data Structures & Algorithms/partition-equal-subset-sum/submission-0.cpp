
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int s = 1; s <= target; s++) {

                dp[i][s] = dp[i - 1][s];

                if (s >= nums[i - 1]) {
                    dp[i][s] = dp[i][s] || dp[i - 1][s - nums[i - 1]];
                }
            }
        }

        return dp[n][target];
    }
};

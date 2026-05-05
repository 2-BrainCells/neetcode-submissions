class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest_streak = 0;

        for (int num : numSet) {
            
            if (numSet.find(num - 1) == numSet.end()) {
                
                int current_num = num;
                int current_streak = 1;

                while (numSet.find(current_num + 1) != numSet.end()) {
                    current_num += 1;
                    current_streak += 1;
                }

                longest_streak = max(longest_streak, current_streak);
            }
        }

        return longest_streak;
    }
};
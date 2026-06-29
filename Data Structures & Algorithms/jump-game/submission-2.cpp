class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reachable = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // If the current index is greater than the farthest we can reach,
            // it means we've hit a dead end (like a 0 we couldn't bypass).
            if (i > max_reachable) {
                return false;
            }
            
            // Update the farthest index we can reach from the current position
            max_reachable = max(max_reachable, i + nums[i]);
            
            // If we can already reach or exceed the last index, we're good!
            if (max_reachable >= n - 1) {
                return true;
            }
        }
        
        return false;
    }
};
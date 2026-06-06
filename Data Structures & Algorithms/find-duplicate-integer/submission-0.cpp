class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        // Step 1: Initialize tortoise (slow) and hare (fast) pointers
        int slow = nums[0];
        int fast = nums[0];
        
        // Move pointers until they intersect inside the cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // Step 2: Locate the entrance to the cycle (the duplicate)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> temp;
        for(int i = 0; i < nums.size(); i++){
            temp[nums[i]] += 1;
        }
        for (const auto& [key, value] : temp) {
            if (value > 1){
                return true;
            }
        }
        return false;
    }
};
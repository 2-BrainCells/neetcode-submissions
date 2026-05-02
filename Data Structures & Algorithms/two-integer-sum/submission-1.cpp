class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> temp;
        vector<int> answer;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];

            if(temp.find(complement) != temp.end()){
                return {temp[complement], i};
            }
            temp[nums[i]] = i;
        }
        return {};
    }
};

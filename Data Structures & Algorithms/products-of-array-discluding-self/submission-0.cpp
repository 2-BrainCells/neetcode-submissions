class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++) {
            int temp = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (j != i) {
                    temp *= nums[j];
                }
            }
            answer.push_back(temp);
        }
        return answer;
    }
};

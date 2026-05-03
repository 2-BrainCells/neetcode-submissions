class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);

        int leftProduct = 1;
        for(int i = 0; i < nums.size(); i++){
            answer[i] = leftProduct;
            leftProduct *= nums[i];
        }

        int rightProduct = 1;
        for(int j = nums.size() - 1; j >= 0; j--){
            answer[j] *= rightProduct;
            rightProduct *= nums[j];
        }

        return answer;
    }
};

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int tempMax = maxProduct;
            int tempMin = minProduct;

            maxProduct = max(nums[i], max(tempMax * nums[i], tempMin * nums[i]));

            minProduct = min(nums[i], min(tempMax * nums[i], tempMin * nums[i]));

            result = max(result, maxProduct);
        }

        return result;
    }
};
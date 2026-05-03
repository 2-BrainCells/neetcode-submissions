class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix;
        vector<int> answer;

        prefix.push_back(1);
        for (int i = 1; i < nums.size(); i++){
            prefix.push_back(prefix[i - 1] * nums[i - 1]);
        }

        suffix.push_back(1);
        for (int i = nums.size() - 1; i > 0; i--){
            suffix.push_back(suffix[nums.size() - i - 1] * nums[i]);
        }

        reverse(suffix.begin(), suffix.end());
        
        for(int i = 0; i < prefix.size(); i++){
            answer.push_back(suffix[i] * prefix[i]);
        }
        return answer;
    }
};

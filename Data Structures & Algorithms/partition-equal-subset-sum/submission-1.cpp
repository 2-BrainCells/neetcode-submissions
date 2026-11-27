class Solution {
public:
bool func(vector<int>& nums, int i, int n, int sum){
    if(i==n){
        if(sum==0) return 1;
        return 0;
    }
    if(nums[i]<=sum) return func(nums, i+1, n, sum-nums[i]) || func(nums, i+1, n, sum);
    else return func(nums, i+1, n, sum);
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x: nums) sum+=x;
        if(sum%2) return 0;
        sum=sum/2;
        int n=nums.size();
        return func(nums, 0, n, sum);
    }
};

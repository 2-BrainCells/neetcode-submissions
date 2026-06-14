class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long num = 0;
        vector<int> ans;
        for(int i = 0; i < digits.size(); i++){
            num = 10 * num + digits[i];
        }
        cout << num;
        num += 1;
        while(num > 0){
            ans.push_back(num % 10);
            num /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

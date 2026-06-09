class Solution {
public:
    int binaryCalc(int n){
        int count = 0;
        while(n > 0){
            if(n % 2 != 0) count += 1;
            n /= 2;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i < n + 1; i++){
            ans.push_back(binaryCalc(i));
        }
        return ans;
    }
};

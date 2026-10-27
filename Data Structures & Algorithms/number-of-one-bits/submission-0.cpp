class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n > 0){
            int d = n % 2;
            if(d == 1) count += 1;
            n /= 2;
        }
        return count;
    }
};

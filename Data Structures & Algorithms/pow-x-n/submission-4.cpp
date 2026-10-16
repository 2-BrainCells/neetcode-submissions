class Solution {
   private:
    double calPow(double x, long long n) {
        if (n == 0) return 1.0;
        
        double half = calPow(x, n / 2);
        
        if (n % 2 != 0) {
            return half * half * x;
        }
        return half * half;
    }

public:
    double myPow(double x, int n) {
        long long N = n; 
        
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }
        
        return calPow(x, N);
    }
};

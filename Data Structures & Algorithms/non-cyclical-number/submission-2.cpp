class Solution {
   public:
    int getSumOfSquares(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> visited;
        while (n != 1 && visited.find(n) == visited.end()) {
            visited.insert(n);
            n = getSumOfSquares(n);
        }

        return n == 1;
    }
};

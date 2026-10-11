class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        int maxFreq = 0;

        for(int elem: tasks){
            counts[elem] += 1;
            maxFreq = max(maxFreq, counts[elem]);
        }

        int maxCount = 0;
        for(auto pair: counts){
            if(pair.second == maxFreq){
                maxCount += 1;
            }
        }

        int calc = (maxFreq - 1) * (n + 1) + maxCount;
        return max((int)tasks.size(), calc);
    }
};

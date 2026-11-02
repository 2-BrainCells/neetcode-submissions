class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> freqMap;
        for (int num : hand) freqMap[num]++;
        while (true) {
            int start = -1;
            for (auto& [val, freq] : freqMap) {
                if (freq > 0) {
                    start = val;
                    break;
                }
            }
            if (start == -1) return true;
            for (int i = 0; i < groupSize; i++) {
                int num = start + i;
                if (freqMap[num] <= 0) return false;
                freqMap[num]--;
            }
        }
        return true;
    }
};
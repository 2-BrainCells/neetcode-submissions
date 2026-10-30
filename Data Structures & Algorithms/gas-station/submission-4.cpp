class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();

        int totalGas = 0;
        int currentGas = 0;
        int start = 0;

        for (int i = 0; i < size; i++) {
            int gain = gas[i] - cost[i];

            totalGas += gain;
            currentGas += gain;

            if (currentGas < 0) {
                start = i + 1;
                currentGas = 0;
            }
        }

        return totalGas >= 0 ? start : -1;
    }
};
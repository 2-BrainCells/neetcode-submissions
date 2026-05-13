class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temp;
        vector<int> answer(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            temp = stack<int>();
            temp.push(temperatures[i]);
            for (int j = i; j < temperatures.size(); j++) {
                if (temp.top() < temperatures[j]) {
                    answer[i] = j - i;
                    break;
                }
            }
        }
        return answer;
    }
};

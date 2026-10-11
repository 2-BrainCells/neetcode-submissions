class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (char t : tasks) {
            counts[t] += 1;
        }

        priority_queue<int> maxHeap;
        for (auto pair : counts) {
            maxHeap.push(pair.second);
        }

        queue<pair<int, int>> cooldown;
        int time = 0;

        while (!maxHeap.empty() || !cooldown.empty()) {
            time += 1;

            if (!maxHeap.empty()) {
                int currCount = maxHeap.top();
                maxHeap.pop();

                currCount -= 1;

                if (currCount > 0) cooldown.push({currCount, time + n});
            }
            if (!cooldown.empty() && cooldown.front().second == time) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        return time;
    }
};

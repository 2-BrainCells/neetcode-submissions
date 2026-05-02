class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> temp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            temp[nums[i]] += 1;
        }

        vector<pair<int, int>> sort_value(temp.begin(), temp.end());

        sort(sort_value.begin(), sort_value.end(),
             [](const auto& a, const auto& b) { return a.second > b.second; });

        if (sort_value.size() == 1) {
            ans.push_back(sort_value[0].first);
            return ans;
        }
        for (const auto& pair : sort_value) {
            if (k < 1) {
                return ans;
            }
            ans.push_back(pair.first);
            k--;
        }
    }
};

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) {
            return "";
        }

        int low = 0;
        int high = m[key].size() - 1;
        string result = "";

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (m[key][mid].first <= timestamp) {
                result = m[key][mid].second;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};
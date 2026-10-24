class Solution {
   public:
    void combinations(unordered_map<char, string> &dig_map, vector<string>& ans, string digits,
                      string &temp, int start) {
        if (digits == "") return;
        if (start >= digits.length()) {
            ans.push_back(temp);
            return;
        }
        if (digits[start] < '2' || digits[start] > '9') return;
        int size = dig_map[digits[start]].size();
        for (int i = 0; i < size; i++) {
            temp += dig_map[digits[start]][i];
            // cout << temp << endl;
            combinations(dig_map, ans, digits, temp, start + 1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp;
        unordered_map<char, string> dig_map;
        dig_map['2'] = "abc";
        dig_map['3'] = "def";
        dig_map['4'] = "ghi";
        dig_map['5'] = "jkl";
        dig_map['6'] = "mno";
        dig_map['7'] = "pqrs";
        dig_map['8'] = "tuv";
        dig_map['9'] = "wxyz";
        combinations(dig_map, ans, digits, temp, 0);
        return ans;
    }
};

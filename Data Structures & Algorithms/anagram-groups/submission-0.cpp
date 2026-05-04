class Solution {
public:
    bool check_anagrams(string s1, string s2) {
        if (s1.size() != s2.size()) return false;

        vector<int> a(26, 0);
        vector<int> b(26, 0);

        for(int k = 0; k < s1.size(); k++) {
            a[s1[k] - 'a'] += 1;
        }
        for(int l = 0; l < s2.size(); l++) {
            b[s2[l] - 'a'] += 1;
        }

        for(int m = 0; m < a.size(); m++) {
            if(a[m] != b[m]) return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        vector<int> dl; 

        for(int i = 0; i < strs.size(); i++) {
            // Check if 'i' is in our "don't look" list
            if(find(dl.begin(), dl.end(), i) != dl.end()) {
                continue;
            }
            
            answer.push_back({strs[i]});
            dl.push_back(i);

            for(int j = i + 1; j < strs.size(); j++) {
                if(find(dl.begin(), dl.end(), j) != dl.end()) {
                    continue;
                }

                if(check_anagrams(strs[i], strs[j])) {
                    answer.back().push_back(strs[j]);
                    dl.push_back(j);
                }
            }
        } 
        return answer; 
    }
};

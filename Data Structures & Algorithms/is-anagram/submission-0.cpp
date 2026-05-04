class Solution {
   public:
    bool isAnagram(string s, string t) {
        vector<int> s1(26, 0);
        vector<int> s2(26, 0);

        int i = 0, j = 0;
        while (i < s.length()) {
            s1[s[i] - 97] += 1;
            i += 1;
        }

        while (j < t.length()) {
            s2[t[j] - 97] += 1;
            j += 1;
        }
        
        int k = 0;
        while(k < s1.size()){
            if(s1[k] != s2[k]){

                return false;
            }
            k += 1;
        }
        return true;
    }
};

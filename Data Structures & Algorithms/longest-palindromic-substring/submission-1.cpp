class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int longest = 0;
        string ans = "";

        for (int i = 0; i < n; i++) {

            int left = i;
            int right = i;

            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > longest) {
                    longest = right - left + 1;
                    ans = s.substr(left, longest);
                }

                left--;
                right++;
            }

            left = i;
            right = i + 1;

            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > longest) {
                    longest = right - left + 1;
                    ans = s.substr(left, longest);
                }

                left--;
                right++;
            }
        }

        return ans;
    }
};
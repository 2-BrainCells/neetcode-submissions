class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(auto &word: strs){
            encoded += to_string(word.length()) + '#' + word;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while(i < s.length()){
            int j = i;

            while(s[j] != '#'){
                j++;
            }

            int word_length = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, word_length);
            decoded.push_back(word);

            i = j + 1 + word_length;
        }
        return decoded;
    }
};

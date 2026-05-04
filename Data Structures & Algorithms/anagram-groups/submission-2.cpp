class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
    
        for (string word : strs) {
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end()); // Sort the letters
            
            map[sorted_word].push_back(word); 
        }
        
        vector<vector<string>> answer;
        for (auto& pair : map) {
            answer.push_back(pair.second);
        }
        
        return answer;  
    }
};

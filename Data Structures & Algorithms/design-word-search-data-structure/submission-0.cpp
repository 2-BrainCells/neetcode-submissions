class trieNode {
   public:
    trieNode* arr[26];
    bool flag;
    trieNode() {
        flag = false;
        for (int i = 0; i < 26; i++) {
            arr[i] = nullptr;
        }
    }
};

class WordDictionary {
    trieNode* root;

    bool dfs(string& word, int index, trieNode* curr) {
        if (index == word.length()) {
            return curr->flag;
        }

        char c = word[index];

        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (curr->arr[i] != nullptr) {
                    if (dfs(word, index + 1, curr->arr[i])) {
                        return true;
                    }
                }
            }
            return false;
        } 
        else {
            int charIndex = c - 'a';
            if (curr->arr[charIndex] == nullptr) {
                return false; // Dead end
            }
            return dfs(word, index + 1, curr->arr[charIndex]);
        }
    }

public:
    WordDictionary() { root = new trieNode(); }

    void addWord(string word) {
        trieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->arr[index] == nullptr) {
                curr->arr[index] = new trieNode();
            }
            curr = curr->arr[index];
        }
        curr->flag = true;
    }
    // can't think of this case used AI
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
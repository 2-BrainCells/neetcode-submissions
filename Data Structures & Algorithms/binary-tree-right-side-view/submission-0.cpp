class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }

private:
    void dfs(TreeNode* node, int level, vector<int>& result) {
        if (node == nullptr) {
            return; 
        }
        
        if (level == result.size()) {
            result.push_back(node->val);
        }
        
        dfs(node->right, level + 1, result);
        dfs(node->left, level + 1, result);
    }
};
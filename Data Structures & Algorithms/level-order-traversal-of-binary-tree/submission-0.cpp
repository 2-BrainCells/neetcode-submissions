class Solution {
public:
    vector<vector<int>> ans;
    void dfs(TreeNode* node, int level) {
        if (!node) return;

        if (level == ans.size()) {
            ans.push_back(vector<int>());
        }
        ans[level].push_back(node->val);

        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        ans.clear(); 
        dfs(root, 0); 
        return ans;
    }
};
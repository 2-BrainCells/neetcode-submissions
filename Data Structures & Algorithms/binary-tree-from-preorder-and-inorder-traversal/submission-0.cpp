/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    TreeNode* solve(vector<int>& preorder, unordered_map<int, int>& temp, int& idx, int isStart,
                    int isEnd) {
        if (isStart > isEnd) return nullptr;

        int value = preorder[idx];
        idx += 1;
        TreeNode* root = new TreeNode(value);

        int rootIndex = temp[value];

        root->left = solve(preorder, temp, idx, isStart, rootIndex - 1);
        root->right = solve(preorder, temp, idx, rootIndex + 1, isEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> temp;
        if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
        for (int i = 0; i < inorder.size(); i += 1) {
            temp[inorder[i]] = i;
        }
        int idx = 0;
        return solve(preorder, temp, idx, 0, preorder.size() - 1);
    }
};

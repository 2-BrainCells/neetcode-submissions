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
    int countDepth(TreeNode *root, int count){
        if (root == nullptr) return count;
        count += 1;
        int left = countDepth(root->left, count);
        int right = countDepth(root->right, count);
        return max(left, right);
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int count = 1;
        int tleft = countDepth(root->left, count);
        int tright = countDepth(root->right, count);
        return max(tleft, tright);
    }
};

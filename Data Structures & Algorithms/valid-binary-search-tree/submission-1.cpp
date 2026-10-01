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
    void inorderTraversal(TreeNode* root, vector<int>& temp) {
        if (root == nullptr) return;

        inorderTraversal(root->left, temp);
        temp.push_back(root->val);
        inorderTraversal(root->right, temp);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> temp;
        bool ans = true;
        inorderTraversal(root, temp);
        for(int i = 1; i < temp.size(); i++){
            if(temp[i - 1] >= temp[i]){
                ans = false;
            }
        }
        return ans;
    }
};

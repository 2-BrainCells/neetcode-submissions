class Solution {
public:
    TreeNode *ans = nullptr;

    int checkAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root == nullptr) return 0;

        int left = checkAncestor(root->left, p, q);
        int right = checkAncestor(root->right, p, q);

        int mid = (root == p || root == q) ? 1 : 0;

        int totalFound = left + right + mid;

        if (totalFound == 2 && ans == nullptr) {
            ans = root;
        }

        return totalFound; 
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        checkAncestor(root, p, q);
        return ans;
    }
};
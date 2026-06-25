class Solution {
public:
    int diameter = 0;
    int calculateHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        calculateHeight(root);
        return diameter;
    }
};
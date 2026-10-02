/*
class TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
*/

class Solution {
    int globalMax; // Stores the absolute highest "Arch" we find anywhere in the tree

public:
    int maxPathSum(TreeNode* root) {
        globalMax = INT_MIN; // Initialize to the smallest possible integer
        dfs(root);
        return globalMax;
    }

    int dfs(TreeNode* root) {
        // Base case: a null node contributes 0 to a path
        if (root == nullptr) {
            return 0;
        }

        // 1. Get the max branch from the left and right children.
        // If a branch is negative, we use max(0, ...) to just ignore it.
        int leftBranch = max(0, dfs(root->left));
        int rightBranch = max(0, dfs(root->right));

        // 2. THE ARCH: Calculate the max path if THIS node is the highest point.
        // (Left branch + Current Node + Right branch)
        int currentArchSum = root->val + leftBranch + rightBranch;
        
        // Update the global maximum if this arch is the best we've seen.
        globalMax = max(globalMax, currentArchSum);

        // 3. THE BRANCH: Return the best single straight path to the parent.
        // The parent can only choose ONE of our sides to continue their path.
        return root->val + max(leftBranch, rightBranch);
    }
};
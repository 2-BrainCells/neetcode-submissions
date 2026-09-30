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
    void solve(TreeNode* root, int& count, vector<int>& sequence) {
        if (root == nullptr) return;

        // for root element
        if (sequence.size() == 0)
            count += 1;

        else {
            // check in the sequence
            int max_value = INT_MIN;
            for (auto val : sequence) {
                max_value = max(val, max_value);
            }
            cout << max_value << endl;
            if (root->val >= max_value) count += 1;
        }

        sequence.push_back(root->val);

        solve(root->left, count, sequence);
        solve(root->right, count, sequence);
        sequence.pop_back();
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        vector<int> sequence;

        solve(root, count, sequence);
        return count;
    }
};

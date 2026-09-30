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
    void solve(TreeNode* root, int& count, priority_queue<int> max_heap) {
        if (root == nullptr) return;

        // for root element
        // if (sequence.size() == 0)
        if (max_heap.empty())
            count += 1;

        else {
            // check in the sequence
            // int max_value = INT_MIN;
            // for (auto val : sequence) {
            //     max_value = max(val, max_value);
            // }
            // cout << max_value << endl;
            int max_value = max_heap.top();
            cout << max_value << endl;
            if (root->val >= max_value) count += 1;
        }

        // sequence.push_back(root->val);
        max_heap.push(root->val);

        solve(root->left, count, max_heap);
        solve(root->right, count, max_heap);
        // sequence.pop_back();
        max_heap.pop();
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        // vector<int> sequence;
        priority_queue<int> max_heap;

        solve(root, count, max_heap);
        return count;
    }
};

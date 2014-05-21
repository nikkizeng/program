/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *prev = root, *cur = root;
        stack<TreeNode *> s;
        
        while (cur != NULL || !s.empty())
        {
            if (cur != NULL)
            {
                if (cur != root)
                {
                    prev->right = cur;
                    prev = prev->right;
                }
            }
            else
            {
                cur = s.top();
                s.pop();
                prev->right = cur;
                prev = prev->right;
            }
            if (cur->right != NULL)
                s.push(cur->right);
            cur->right = NULL;
            cur = cur->left;
            prev->left = NULL;
        }
    }
};

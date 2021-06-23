/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

// @lc code=start
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
private:
    int maxPathSumUtil(TreeNode* root, int &res){
        if(root==NULL)
            return 0;
        
        int l = maxPathSumUtil(root->left, res);
        int r = maxPathSumUtil(root->right, res);

        int temp = max(max(l, r)+root->val, root->val);
        int ans  = max(l+r+root->val, temp);
        res = max(res, ans);

        return temp;
    }

public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSumUtil(root, res);
        return res;
    }
};
// @lc code=end


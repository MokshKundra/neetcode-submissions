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
    int res = INT_MIN;

    int maxPathSum(TreeNode* root) {
        int temp = pathSum(root);
        return res;
    }

    int  pathSum(TreeNode* root){
        if(root -> left == nullptr && root -> right == nullptr){
            res = max(res, root -> val);
            return max(root -> val, 0);
        }
        
        int leftSum, rightSum;

        leftSum = (root -> left == nullptr)? 0 : pathSum(root -> left);
        rightSum = (root -> right == nullptr)? 0 : pathSum(root -> right);

        int ret = max(leftSum, rightSum) + root -> val;
        res = max(res, leftSum + rightSum + root -> val), root -> val;

        return max(ret, 0);
    }
};
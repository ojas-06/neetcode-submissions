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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,int pi = -1, int pr = -1, int ii = -1, int ir = -1) {
        if(pi == -1){
            pi = 0;
            pr = preorder.size()-1;
            ii = 0;
            ir = inorder.size()-1;
        }
        if(pr<pi) return nullptr;
        TreeNode* root = new TreeNode(preorder[pi]);
        if(pr == pi) return root;
        int leftSize = 0;
        while(inorder[ii+leftSize] != root->val) leftSize++;
        root->left = buildTree(preorder, inorder, pi+1, pi+leftSize, ii, ii+leftSize-1);
        root->right = buildTree(preorder, inorder, pi+leftSize+1, pr, ii+leftSize+1, ir);

        return root;
    }
};

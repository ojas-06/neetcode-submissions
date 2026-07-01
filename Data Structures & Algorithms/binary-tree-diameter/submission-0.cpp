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
int dia = 0;
unordered_map<int, int> ht;
    int height(TreeNode* root){
        if(!root) return 0;
        if(ht.count(root->val)) return ht[root->val];
        return ht[root->val] = 1+max(height(root->left), height(root->right));
    }
    void check(TreeNode* root){
        if(!root) return;
        dia = max(dia, height(root->left) + height(root->right));
        check(root->left);
        check(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        check(root);
        return dia;
    }
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        stringstream s(data);
        return buildTree(s);
    }

private:
    TreeNode* buildTree(stringstream& s) {
        string val;
        getline(s, val, ',');
        
        if (val == "#") {
            return nullptr;
        }
    
        TreeNode* root = new TreeNode(stoi(val));
        root->left = buildTree(s);
        root->right = buildTree(s);
        
        return root;
    }
};
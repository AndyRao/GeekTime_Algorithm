class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) {
            return nullptr;
        }
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
        return root;

    }
private:
    int sum = 0;
};

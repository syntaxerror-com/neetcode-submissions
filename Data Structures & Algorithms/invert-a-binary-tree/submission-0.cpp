class Solution {
public:

    TreeNode* create(TreeNode* root){
        if(root==NULL){
            return NULL;
        }

        TreeNode* b=root->right;
        root->right=root->left;
        root->left=b;

        create(root->left);
        create(root->right);

        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        TreeNode* a=create(root->left);
        TreeNode* b=create(root->right);
        
        root->right=a;
        root->left=b;
        
        return root;
    }
};
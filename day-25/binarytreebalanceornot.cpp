/*brute force code*/
/*
class Solution 
{
public:
    bool isBalanced(TreeNode* root) 
    {
        if (root == nullptr)
            return true;

        int leftHeight  = height(root->left);
        int rightHeight = height(root->right);

        if (abs(leftHeight - rightHeight) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int height(TreeNode* root) 
    {
        if (root == nullptr)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};*/
/*
my version in c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
 int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct TreeNode* root){
    if(root==NULL) return 0;
    return 1+ max(height(root->left),height(root->right));
}
bool isBalanced(struct TreeNode* root) {
   if (root == NULL) return true;
   int leftHeight  = height(root->left);
   int rightHeight = height(root->right);
   if(abs(leftHeight - rightHeight) > 1)return false;
   return isBalanced(root->left) && isBalanced(root->right);
}*/
/*optimal*/
int max(int a, int b) {
    return (a > b) ? a : b;
} 

int checkHeight(struct TreeNode* root){
    if(root == NULL)
    return 0;
    int left = checkHeight(root->left);
    if(left == -1)
    return -1;
    int right = checkHeight(root->right);
    if(right == -1)
    return -1;
    if(abs(left - right) > 1)
    return -1;
    return 1 + max(left, right);
}
bool isBalanced(struct TreeNode* root) {

    return checkHeight(root) != -1;

}
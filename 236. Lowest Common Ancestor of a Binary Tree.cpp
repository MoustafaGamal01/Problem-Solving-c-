/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* DFS(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr) return root;
        if(root == q || root==p){
            return root;
        }
        
        TreeNode*l = DFS(root->left,p,q);
        TreeNode*r = DFS(root->right,p,q);

        if(!l) return r;
        if(!r) return l;
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return DFS(root, p, q);
    }
};
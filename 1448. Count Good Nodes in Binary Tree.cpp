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
    int ans = 0;
public:
    void DFS(TreeNode* root, int mx){
        if(root == NULL) return;

        if(root->val >= mx){
            ans++;
            mx = root-> val;
        }
        
        DFS(root->left, mx);
        DFS(root->right, mx);
    }
    int goodNodes(TreeNode* root) {
        DFS(root, root->val);
        return ans;
    }   
};
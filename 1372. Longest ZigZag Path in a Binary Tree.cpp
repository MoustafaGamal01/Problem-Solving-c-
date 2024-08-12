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
    void DFS(TreeNode* root, int cnt, bool ok){
        if(!root) return;
        ans = max(ans,cnt);

        if(ok){
            DFS(root->right,cnt+1, false);
            DFS(root->left, 1, true);
        } else {
            DFS(root->left,cnt+1, true);
            DFS(root->right, 1, false);
        }
    }
    int longestZigZag(TreeNode* root) {
        DFS(root->left, 1, true);   // left ->  true
        DFS(root->right, 1, false); // right -> false
        return ans;
    }
};
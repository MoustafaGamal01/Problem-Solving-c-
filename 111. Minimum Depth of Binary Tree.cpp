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
    int BFS(TreeNode* root){
        queue<pair<int, TreeNode*>>q;
        
        q.push({1, root});
        int cntt = 0;
        while(!q.empty()){
            auto [cnt, cur] = q.front();
            q.pop();
            
            if(!cur->left && !cur->right) return cnt;
            
            if(cur->left)q.push({cnt+1, cur->left}), cntt = cnt;
            if(cur->right)q.push({cnt+1, cur->right}), cntt = cnt;
            
        }
        return cntt;
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        return BFS(root);
    }
};
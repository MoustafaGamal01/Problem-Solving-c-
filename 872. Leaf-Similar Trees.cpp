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
private:
    void DFS(TreeNode* root1, vector<int>&ans){
        if(root1 != NULL) {
            DFS(root1->right, ans);
            DFS(root1->left, ans);

            if(root1->left == NULL && root1->right == NULL)     
                ans.push_back(root1->val);
        }
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2;

        DFS(root1, v1);
        DFS(root2, v2);

        return v1 == v2;
    }
};
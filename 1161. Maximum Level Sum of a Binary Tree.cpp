class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        /*queue<TreeNode*>q;
        q.push(root);
        map<TreeNode*, int>mp;
		map<int, int>mpp;

        mp[root] = 1;
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur->left != NULL) {
                q.push(cur->left);
                mp[cur->left] = mp[cur] + 1;
            }
            if (cur->right != NULL) {
                q.push(cur->right);
                mp[cur->right] = mp[cur] + 1;
            }
        }
		for (auto it : mp) {
			mpp[it.second] += (it.first->val);
		}

		int ans = INT_MIN, level = 0;
        for (auto it : mpp) {
		    if (it.second > ans) {
				ans = it.second;
				level = it.first;
			}
        }
        return level;*/

        queue<TreeNode*>q;
        int mx(INT_MIN);
        int lvl(1), res(1);

        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int sum = 0;
            while(sz--){
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val; 
                if(curr->right)
                    q.push(curr->right);
                if(curr->left) 
                    q.push(curr->left);
            }
            if(mx < sum){
                mx = sum;
                res = lvl;
            }
            lvl++;
        }
        return res;
    }
};
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int x = spells.size(), y = potions.size();
        vector<int> ans;
        sort(potions.begin(), potions.end());

        for (int i = 0; i < x; i++) {
            auto it = lower_bound(potions.begin(), potions.end(), ceil((double)success / spells[i])) - potions.begin();
            ans.push_back(y - (it));
        }
        return ans;
    }
};

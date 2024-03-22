/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>v;
        
        while(head!=nullptr) {
            v.push_back(head->val);
            head = head->next;
        }

        int ans(0), x(v.size());
        for(int i = 0; i < x/2; i++)
            ans = max(ans, v[i]+v[x-i-1]);

        return ans;
    }
};
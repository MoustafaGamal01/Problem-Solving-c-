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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* sum = head->next;
        ListNode* nxt = sum;

        bool ok(true);
        int t(0);
        while(sum != nullptr){
            t += sum->val; 
            if(sum->val == 0){
                if(ok){ 
                    sum->val = t;
                    nxt = sum;
                    head = sum;
                    t = 0;
                    ok = false;
                }
                else {
                    sum->val = t;
                    nxt->next = sum;
                    nxt = sum;
                    t = 0;
                }
            }
            sum = sum->next;
        }
        return head;
    }
};
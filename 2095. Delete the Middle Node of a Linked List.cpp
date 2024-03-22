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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) return nullptr;
        
        // counting nodes
        int cnt(0);
        ListNode* temp = head;
        while(temp != nullptr){
            temp = temp->next;
            cnt++;
        }

        cnt /= 2; 
        // delete the one in the middle
        ListNode* cur = head->next;
        ListNode* prv = head;
        for(int i = 0; i < cnt-1; i++){
            prv = cur;
            cur = cur->next;
        }
        prv->next = cur->next;
        cur->next = nullptr;
        return head;

    }
};

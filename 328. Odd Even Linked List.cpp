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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode *cur = head, *nxt = cur->next;
        ListNode *temp = nxt;

        while(cur->next != nullptr && nxt->next != nullptr){
            cur->next = nxt->next;
            cur = nxt->next;
            nxt->next = cur->next;
            nxt = cur->next;
        }
        
        cur->next = temp;
        return head;
    }
};
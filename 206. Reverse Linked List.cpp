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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* prv = nullptr, *cur = head, *nxt = cur->next;
        while(nxt != nullptr){
            nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }
        head = prv;
        return head;
    }
};
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
        if(!head || !head->next) return nullptr; 
        ListNode* slow = head; 
        ListNode* fast = head->next; 
        ListNode* prev = nullptr; 

        // get pointer to middle node 
        while(fast && fast->next){
            prev = slow; 
            slow = slow->next;
            fast = fast->next->next; 
        }

        if(fast) prev = slow, slow = slow->next;

        cout << slow->val << prev->val;
        prev->next = slow->next;
        slow->next = nullptr; 
        return head; 
    }
};
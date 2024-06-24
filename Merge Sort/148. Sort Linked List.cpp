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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2; 
        if(!list2) return list1; 
        ListNode* head = NULL;
        if(list1->val < list2->val){
            head = list1; 
            head->next = mergeTwoLists(list1->next, list2);
        }else{
            head = list2;  
            head->next = mergeTwoLists(list1, list2->next);
        }
        return head; 
    }

    ListNode* sortList(ListNode* head) {
        //base case
        if(head == NULL || head->next == NULL){
            return head; 
        }
        // find middle of linked list
        ListNode* slow = head; 
        ListNode* fast = head->next; 
        while(fast && fast->next){
            slow = slow->next; 
            fast = fast->next->next; 
        }
        ListNode* n = slow->next;
        slow->next = NULL; 

        ListNode* list1 = sortList(head);
        ListNode* list2 = sortList(n); 
        // merge two sorted linked lists
        head = mergeTwoLists(list1, list2);
        return head; 
    }
};
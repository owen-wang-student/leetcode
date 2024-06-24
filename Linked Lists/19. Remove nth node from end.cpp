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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = head;
        ListNode* end = head; 

        for(int i = 0; i <  n; i++){
            end = end->next; 
        }

        if(end == NULL){
            return start->next; 
        }

        while(end->next != NULL){
            end = end->next; 
            start = start->next; 
        }

        ListNode* next = start->next->next; 
        start->next->next = NULL; 
        start->next = next; 

        return head; 
    }
};
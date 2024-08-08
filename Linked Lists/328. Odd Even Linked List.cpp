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
        if(!head) return nullptr;

        ListNode* odd = head;
        ListNode* evenStart = head->next; 
        ListNode* even = head->next;  

        while(odd && even){
            ListNode* nextOdd = odd->next->next; 
            ListNode* nextEven; 
            if(nextOdd) nextEven = even->next->next;  
            else break;          

            odd->next = nextOdd;  
            even->next = nextEven; 

            odd = nextOdd;
            even = nextEven; 
        }

        odd->next = evenStart;

        return head; 
    }
};
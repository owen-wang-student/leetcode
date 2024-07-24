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
        vector<int> v;
        while(head != NULL){
            v.push_back(head->val);
            head = head->next; 
        }
        int start = 0;
        int end = v.size()-1;
        int twinSum = 0;
        while(start < end){
            twinSum = max(twinSum, v[start] + v[end]);
            start += 1;
            end -= 1;
        }
        return twinSum;
    }
};
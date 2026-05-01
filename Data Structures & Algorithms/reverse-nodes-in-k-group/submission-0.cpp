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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head != nullptr && k==1) return head;
        
        ListNode * curr = head;
        int totalNodes = 0;

        while(curr != nullptr){
            totalNodes++;
            curr = curr->next;
        }

        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * prevGroup = dummy;
        curr = head;

        while(totalNodes >= k){
            ListNode * groupStart = curr;
            ListNode * prev = nullptr;

            for(int i=0; i < k; i++){
                ListNode * next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            prevGroup->next = prev;
            groupStart->next = curr;
            prevGroup = groupStart;
            totalNodes -= k;
        }

        return dummy->next;
    }
};

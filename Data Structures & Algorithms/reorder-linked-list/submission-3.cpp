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
    ListNode* mid(ListNode* head){
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* node;
        while(curr){
            node=curr->next;
            curr->next=prev;
            prev=curr;
            curr=node;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
       
    if (!head || !head->next) return;

    // Step 1: Find middle
    ListNode* mid_node = mid(head);
    ListNode* s_head = mid_node->next;
    mid_node->next = nullptr;

    // Step 2: Reverse second half
    ListNode* list2 = reverse(s_head);
    ListNode* list1 = head;

    // Step 3: Merge both lists
    while (list1 && list2) {
        ListNode* temp1 = list1->next;
        ListNode* temp2 = list2->next;

        list1->next = list2;
        list2->next = temp1;

        list1 = temp1;
        list2 = temp2;
    }
}





        
    
};

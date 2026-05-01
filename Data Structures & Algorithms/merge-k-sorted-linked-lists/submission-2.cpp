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
    ListNode* conv(vector<int>& arr){
        ListNode* dummy = new ListNode(0);
        ListNode* tail=dummy;
        for(int i:arr){
            tail->next=new ListNode(i);
            tail = tail->next;
        }
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for(int i=0;i<lists.size();i++){
            ListNode* head = lists[i];
            while(head){
                arr.push_back(head->val);
                head=head->next;
            }
        }
        sort(arr.begin(),arr.end());
        ListNode* head = conv(arr);
        return head;
        
    }
};

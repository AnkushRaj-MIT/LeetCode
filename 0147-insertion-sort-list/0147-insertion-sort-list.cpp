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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode();
        dummy->next=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* prev=dummy;
            while(prev->next!=NULL&&prev->next->val<temp->val){
                prev=prev->next;
            }
            ListNode* next=temp->next;
            temp->next=prev->next;
            prev->next=temp;
            temp=next;
        }
        return dummy->next;
    }
};
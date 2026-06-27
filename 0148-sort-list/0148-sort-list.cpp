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
    ListNode* mergeSort(ListNode* l1,ListNode* l2){
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
            }
        }
        while(l1!=NULL){
            temp->next=l1;
            l1=l1->next;
            temp=temp->next;
        }
        while(l2!=NULL){
            temp->next=l2;
            l2=l2->next;
            temp=temp->next;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
       if(head==NULL||head->next==NULL) return head;
       ListNode* prev=NULL;
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
       }
       prev->next=NULL;
       ListNode* l1=sortList(head);
       ListNode* l2=sortList(slow);
       return mergeSort(l1,l2);
    }
};
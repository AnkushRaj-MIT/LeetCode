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
    ListNode* reverseLL(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseLL(l1);
        l2=reverseLL(l2);
        ListNode* ans=new ListNode(0);
        ListNode* temp=ans;
        int carry=0;
        while(l1!=NULL && l2!=NULL){
            int sum=l1->val+l2->val+carry;
            ListNode* newNode=new ListNode(sum%10);
            carry=sum/10;
            temp->next=newNode;
            temp=newNode;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            int sum=l1->val+carry;
            ListNode* newNode=new ListNode(sum%10);
            carry=sum/10;
            temp->next=newNode;
            temp=newNode;
            l1=l1->next;
        }
        while(l2!=NULL){
            int sum=l2->val+carry;
            ListNode* newNode=new ListNode(sum%10);
            carry=sum/10;
            temp->next=newNode;
            temp=newNode;
            l2=l2->next;
        }
        if(carry!=0){
            ListNode* newNode=new ListNode(carry);
            temp->next=newNode;
            temp=newNode;
        }
        ans=reverseLL(ans->next);
        return ans;
    }
};
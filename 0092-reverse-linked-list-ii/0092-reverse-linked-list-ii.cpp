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
ListNode* reverseLL(ListNode* temp1,ListNode* temp2,ListNode* right,ListNode* left,ListNode* head){
    ListNode* curr=temp1;
    ListNode* prev=NULL;
    ListNode* next=NULL;
    while(curr!=right){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    if(left!=NULL){
       left->next=prev;
    }
    temp1->next=right;
    if(left==NULL){
        return prev;
    }
    return head;
}
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        ListNode* temp1=head;
        int count=1;
        while(count!=l){
            temp1=temp1->next;
            count++;
        }
        ListNode* temp2=head;
        count=1;
        while(count!=r){
            temp2=temp2->next;
            count++;
        }
        ListNode* rightNode=NULL;
        if(temp2->next!=NULL){
            rightNode=temp2->next;
        }
        ListNode* leftNode=NULL;
        if(temp1!=head){
            leftNode=head;
            while(leftNode->next!=temp1){
                leftNode=leftNode->next;
            }
        }
        return reverseLL(temp1,temp2,rightNode,leftNode,head);
    }
};
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
    ListNode* swapNodes(ListNode* head, int k) {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        ListNode* st;
        ListNode* end;
        temp=head;
        int pos=1;
        while(temp!=NULL){
            if(pos==k) st=temp;
            if(pos==(len-k+1)) end=temp;
            pos++;
            temp=temp->next;
        }
        swap(st->val,end->val);
        return head;
    }
};
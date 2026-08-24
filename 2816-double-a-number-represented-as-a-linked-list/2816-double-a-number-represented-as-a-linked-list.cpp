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
    ListNode* doubleIt(ListNode* head) {
        unordered_map<ListNode*,ListNode*> m;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            m[temp]=prev;
            prev=temp;
            temp=temp->next;
        }
        long long sum;
        int carry=0;
        while(prev!=NULL){
            sum=(prev->val*2+carry)%10;
            carry=(prev->val*2+carry)/10;
            prev->val=sum;
            prev=m[prev];
        }
        if(carry!=0){
            ListNode* newNode=new ListNode(carry);
            newNode->next=head;
            head=newNode;
        }
        return head;
    }
};
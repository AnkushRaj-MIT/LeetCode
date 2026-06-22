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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(0);
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        long long carry=0,a=0,b=0;
        ListNode* temp=ans;
        while(temp1!=NULL||temp2!=NULL){
            if(temp1==NULL) a=0;
            else a=temp1->val;
            if(temp2==NULL) b=0;
            else b=temp2->val;
            long long sum=a+b+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* New=new ListNode(sum);
            temp->next=New;
            temp=temp->next;
            if(temp1!=NULL) temp1=temp1->next;
            if(temp2!=NULL) temp2=temp2->next;
        }
        if(carry>0){
            temp->next=new ListNode(carry);
        }
        return ans->next;
    }
};
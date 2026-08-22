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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        vector<ListNode*> ans(k,NULL);
        temp=head;
        int partSize=len/k;
        int extra=len%k;
        for(int i=0;i<k && temp!=NULL;i++){
            ans[i]=temp;
            int size=partSize;
            if(i<extra) size++;
            for(int j=1;j<size;j++) temp=temp->next;
            ListNode* nextPart=temp->next;
            temp->next=NULL;
            temp=nextPart;
        }
        return ans;
    }
};
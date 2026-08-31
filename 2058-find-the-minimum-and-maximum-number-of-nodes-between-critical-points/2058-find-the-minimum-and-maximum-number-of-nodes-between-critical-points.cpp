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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2,-1);
        vector<int> critical;
        ListNode* temp=head;
        ListNode* prev=NULL;
        int i=1;
        while(temp->next!=NULL){
            if(prev!=NULL){
                if(temp->val>prev->val && temp->val>temp->next->val) critical.push_back(i);
                if(temp->val<prev->val && temp->val<temp->next->val) critical.push_back(i);
            }
            prev=temp;
            i++;
            temp=temp->next;
        }
        sort(critical.begin(),critical.end());
        int n=critical.size();
        if(n<=1) return ans;
        ans[1]=critical[n-1]-critical[0];
        int minm=INT_MAX;
        for(int i=1;i<n;i++){
            if(critical[i]-critical[i-1]<minm) minm=critical[i]-critical[i-1];
        }
        ans[0]=minm;
        return ans;
    }
};
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(),nums.end());
        ListNode* ans=new ListNode(0);
        ListNode* curr=ans;
        ListNode* temp=head;
        while(temp!=NULL){
            if(s.find(temp->val)==s.end()){
                curr->next=temp;
                curr=curr->next;
            }
            temp=temp->next;
        }
       curr->next=NULL;
       return ans->next;
    }
};
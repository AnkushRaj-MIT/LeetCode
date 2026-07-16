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
    class compare{
        public:
          bool operator()(ListNode* a,ListNode* b){
            return a->val>b->val;
          }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        ListNode* head=new ListNode(0);
        for(auto list:lists){
            if(list==NULL) continue;
            else pq.push(list);
        }
        ListNode* tail=head;
        while(!pq.empty()){
            ListNode* temp=pq.top();
            pq.pop();
            tail->next=temp;
            tail=tail->next;
            if(temp->next!=NULL) pq.push(temp->next);
        }
        return head->next;
    }
};
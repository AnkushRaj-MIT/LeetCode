class Solution {
public:  
    class node{
    public:
      int val;
      int row;
      int col;
      node(int d,int r,int c){
        val=d;
        row=r;
        col=c;
      }
    };
    class compare{
    public:
      bool operator()(node* a,node* b){
        return a->val>b->val;
      }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node*,vector<node*>,compare> pq;
        int mini=INT_MAX,maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int element=nums[i][0];
            mini=min(mini,element);
            maxi=max(maxi,element);
            pq.push(new node(element,i,0));
        }
        int st=mini,end=maxi;
        while(!pq.empty()){
            node* temp=pq.top();
            pq.pop();
            mini=temp->val;
            if(maxi-mini<end-st||(maxi-mini<end-st && mini<st)){
                end=maxi;
                st=mini;
            }
            if(temp->col+1<nums[temp->row].size()){
                maxi=max(maxi,nums[temp->row][temp->col+1]);
                pq.push(new node(nums[temp->row][temp->col+1],temp->row,temp->col+1));
            }
            else break;
        }
        return {st,end};
    }
};